global tmp : table[addr,addr] of string;


event snmp_get_request (c: connection, is_orig: bool, header: SNMP::Header, pdu: SNMP::PDU){

      print "lol";
      print header$version;
      if (header$version == 0)
      	 print fmt("date : %s , ip_src : %s , ip_dst : %s,  protocole : snmp, version : 1 , community : %s",
	    strftime("%Y/%m/%d %H:%M:%S", c$start_time),
	    c$id$orig_h,
	    c$id$resp_h, 
	    header$v1$community);

}