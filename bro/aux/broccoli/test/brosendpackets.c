#include <string.h>
#include <broccoli.h>
#include <pcap.h>

void usage() {
	fprintf(stderr, "usage: brosendpackets [-r file] [-b host:port ] [-t tag]\n");
	exit(1);
}


int main(int argc, char** argv) {
	bro_init(NULL);

	char* filename=NULL;
	char* bro_connection=NULL;
	const char* tag="";

	int opt;
	while ((opt=getopt(argc, argv, "r:b:t:h?")) != -1) {
		switch(opt) {
		case 'r':
			filename=strdup(optarg);
			break;
		case 'b':
			bro_connection=strdup(optarg);
			break;
		case 't':
			tag=strdup(optarg);
			break;
		case 'h':
		case '?':
		default:
			usage();
		}
	}
	argc -= optind;
	argv += optind;


	if (filename==NULL || bro_connection==NULL) usage();

	BroConn *broccoli_p=bro_conn_new_str(bro_connection, BRO_CFLAG_NONE);
	if (!broccoli_p) {
		fprintf(stderr, "can't instantiate connection object\n");
		exit(1);
	}

	if (! bro_conn_connect(broccoli_p)) {
		fprintf(stderr, "Bro connection to %s failed\n",
				bro_connection);
		exit(1);
	}
	printf("connected to Bro %s\n", bro_connection);

	char pcap_errbuf[PCAP_ERRBUF_SIZE]="";
	pcap_t* pcap_p=pcap_open_offline(filename, pcap_errbuf);

	if (!pcap_p) {
		fprintf(stderr, "pcap eror: %s\n", pcap_errbuf);
		exit(1);
	}

	bro_conn_set_packet_ctxt(broccoli_p, pcap_datalink(pcap_p));

	const uchar* packet_p=NULL;
	struct pcap_pkthdr pkthdr;

	int pkt_cnt=0;
	while ((packet_p=pcap_next(pcap_p, &pkthdr))) {
		pkt_cnt++;
		BroPacket* broccoli_packet_p=bro_packet_new(&pkthdr, packet_p, tag);
		bro_packet_send(broccoli_p, broccoli_packet_p);
		bro_packet_free(broccoli_packet_p);
	}

	printf("sent %d packets\n",pkt_cnt);

	/*
	fd_set rfds;
	int broccoli_fd=bro_conn_get_fd(broccoli_p);

	//    printf("bro_connect_str=%s broccoli_fd=%d\n", conf_main_bro_connect_str, broccoli_fd);
	bro_event_registry_add(broccoli_p, "tm_query", (BroEventFunc)tm_query_cb);

	bro_event_registry_request(broccoli_p);

	// loop
	FD_ZERO(&rfds);
	FD_SET(broccoli_fd, &rfds);
	while (1) {
	  select(broccoli_fd+1, &rfds, NULL, NULL, NULL);
	  /// error handling!
	  printf("select()ed on Bro connection file descriptor\n");
	  bro_conn_process_input(broccoli_p);
	}
	*/

	bro_conn_delete(broccoli_p);
	printf("connection to Bro %s closed\n", bro_connection);

	return 0;
}
