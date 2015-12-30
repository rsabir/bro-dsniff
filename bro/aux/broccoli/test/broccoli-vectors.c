#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/time.h>

#include <broccoli.h>

static char* bro_string_to_c_str(const BroString* str)
	{
	uint32 len = bro_string_get_length(str);
	char* cstr = (char*) calloc(len + 1, sizeof(char));

	if ( ! cstr )
		return 0;

	strncpy(cstr, (const char*) bro_string_get_data(str), len);
	return cstr;
	}

static void bro_vector_cb(BroConn* bc, void* user_data, BroVector* v)
	{
	BroString str;
	int i;

	printf("Received bro_vector\n");

	for ( i = 0; i < bro_vector_get_length(v); ++i )
		{
		char* e = bro_string_to_c_str(bro_vector_get_nth_val(v, i, 0));
		printf("  %d: %s\n", i, e);
		free(e);
		}

	bro_string_set(&str, "additional element");
	bro_vector_add_val(v, BRO_TYPE_STRING, 0, &str);

	BroEvent* event;

	/*
	// Broccoli can't currently produce events w/ vector args,
	// see __bro_val_assign in bro_val.c
	event = bro_event_new("broccoli_vector");
	bro_event_add_val(event, BRO_TYPE_VECTOR, 0, v);
	bro_event_send(bc, event);
	bro_event_free(event);
	*/

	for ( i = 0; i < bro_vector_get_length(v); ++i )
		{
		event = bro_event_new("broccoli_vector_element");
		uint64 idx = i;
		bro_event_add_val(event, BRO_TYPE_COUNT, 0, &idx);
		bro_event_add_val(event, BRO_TYPE_STRING, 0,
		                  bro_vector_get_nth_val(v, i, 0));
		bro_event_send(bc, event);
		bro_event_free(event);
		}

	bro_string_cleanup(&str);
	}

static void usage()
	{
	printf("broccoli-vectors - send/recv events w/ vector args to Bro.\n"
			"USAGE: broccoli-vectors [-h|-?] [-d] [-p port] host\n");
	exit(0);
	}

int main(int argc, char** argv)
	{
	int opt, port;
	extern char* optarg;
	extern int optind;
	BroConn* bc;
	const char* host_str = "localhost";
	const char* port_str = "47757";
	char hostname[512];
	struct in_addr in4;
	struct in6_addr in6;
	bro_debug_messages = 0;

	while ( (opt = getopt(argc, argv, "?hdp:")) != -1 )
		{
		switch ( opt ) {
		case 'p':
			port_str = optarg;
			break;
		case 'd':
			bro_debug_messages = 1;
			break;
		case 'h':
		case '?':
		default:
			usage();
		}
		}

	argc -= optind;
	argv += optind;

	if ( argc > 0 )
		host_str = argv[0];

	snprintf(hostname, 512, "%s:%s", host_str, port_str);

	port = strtol(port_str, 0, 0);
	if ( errno == ERANGE )
		{
		fprintf(stderr, "invalid port string: %s\n", port_str);
		return 1;
		}

	bro_init(0);

	if ( ! (bc = bro_conn_new_str(hostname, BRO_CFLAG_NONE)) )
		{
		fprintf(stderr, "bro_conn_new_str failed for %s\n", hostname);
		return 1;
		}

	bro_event_registry_add(bc, "bro_vector", (BroEventFunc)&bro_vector_cb, 0);

	if ( ! bro_conn_connect(bc) )
		{
		fprintf(stderr, "failed to connect to %s\n", hostname);
		return 1;
		}

	printf("Connected to Bro instance at: %s\n", hostname);

	int fd = bro_conn_get_fd(bc);
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(fd, &fds);
	struct timeval to;
	to.tv_sec = 3;
	to.tv_usec = 0;

	while ( select(fd+1, &fds, 0, 0, &to) > 0 )
		bro_conn_process_input(bc);

	printf("Terminating\n");
	bro_conn_delete(bc);
	return 0;
	}
