module Poppassd;

export {
	redef enum Log::ID += { LOG };

	type Info: record {
		## Timestamp for when the event happened.
		ts:     time    &log;
		## Unique ID for the connection.
		uid:    string  &log;
		## The connection's 4-tuple of endpoint addresses/ports.
		id:     conn_id &log;
		
		# ## TODO: Add other fields here that you'd like to log.
	};

	## Event that can be handled to access the poppassd record as it is sent on
	## to the loggin framework.
	global log_poppassd: event(rec: Info);
}


const ports = { 106/tcp };

redef likely_server_ports += { ports };


global oldpassword : string = "";
global username:string = "";
global newpassword:string = "";
global test_pattern:pattern;


event bro_init() &priority=5
	{
	Log::create_stream(Poppassd::LOG, [$columns=Info, $ev=log_poppassd, $path="poppassd"]);

	# TODO: If you're using port-based DPD, uncomment this.
	# Analyzer::register_for_ports(Analyzer::ANALYZER_POPPASSD, ports);
	}

event poppassd_event(c: connection,user:string,pass:string,newpass:string){
	print "holla";
        print user;
        print pass;
        print newpass;
}

event poppassd_debug(c:connection,firsthex:string){
	print "holla";
	print firsthex;
}




# event tcp_packet(c: connection, is_orig: bool, flags: string, seq: count, ack: count, len: count, payload: string){
#       if (payload[0]=="u"){
#     	test_pattern = /user .*/;
#       	if ( test_pattern in payload ){
# 	       username = split_string1(split_string1(payload, /user /)[1],/\r/)[0];
#       	 }
#       }else if(payload[0]=="p"){
# 	test_pattern = /pass .*/;
#       	if ( test_pattern in payload ){
# 	       oldpassword = split_string1(split_string1(payload, /pass /)[1],/\r/)[0];
#       	 }
#       }else if(payload[0]=="n"){
# 	test_pattern = /newpass .*/;
#       	if ( test_pattern in payload ){
# 	       newpassword = split_string1(split_string1(payload, /newpass /)[1],/\r/)[0];
# 	       		print fmt("date : %s , ip_src : %s , ip_dst : %s,  protocole : poppasswd, username :%s, oldPassword : %s, newPassword : %s",
# 	   	 strftime("%Y/%m/%d %H:%M:%S", c$start_time),
# 	   	 c$id$orig_h,
# 	  	 c$id$resp_h, 
# 	 	 username,
# 		 oldpassword,
# 		 newpassword);
	
# 	local info: Info;
# 	info$ts  = network_time();
# 	info$uid = c$uid;
# 	info$id  = c$id;

# 	Log::write(Poppassd::LOG, info);

#       	 }
#       }     
# }
