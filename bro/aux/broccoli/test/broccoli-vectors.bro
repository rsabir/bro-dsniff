@load frameworks/communication/listen

redef Communication::nodes += {
	["vectors"] = [$host=127.0.0.1, $connect=F, $ssl=F,
	               $events=/broccoli_.*/]
};

event bro_vector(v: vector of string)
	{
	print fmt("bro_vector(%s)", v);
	}

global cnt = 0;

event broccoli_vector(v: vector of string)
	{
	# TODO: broccoli can't produce events w/ vector arguments
	print fmt("broccoli_vector(%s)", v);
	}

event broccoli_vector_element(idx: count, ele: string)
	{
	print fmt("broccoli_vector_element(%s, %s)", idx, ele);
	cnt = cnt + 1;

	if ( cnt == 10 )
		terminate();
	}

event broccoli_string(s: string)
	{
	print fmt("broccoli_string(%s)", s);
	}

event remote_connection_handshake_done(p: event_peer)
    {
	print "handshake done with peer";

	local v1: vector of string = ["a", "b", "c", "d", "e"];
	local v2: vector of string = ["one", "two", "three"];

	event bro_vector(v1);
	event bro_vector(v2);
    }
