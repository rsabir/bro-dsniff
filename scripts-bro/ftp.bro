global tmp : table[addr,addr] of string;


event ftp_request(c:connection,command:string,arg:string){

     if ( command == "USER" ){
     	tmp[c$id$orig_h,c$id$resp_h] = arg;
     }
     if ( command == "PASS" ) {
     	if ( [c$id$orig_h,c$id$resp_h] in tmp ){
	     	print fmt("date : %s , ip_src : %s , ip_dst : %s,  user : %s , password : %s",
		      strftime("%Y/%m/%d %H:%M:%S", c$start_time),
		      c$id$orig_h,
		      c$id$resp_h, 
		      tmp[c$id$orig_h,c$id$resp_h],
		      arg);
	}
	else
	  	return ;
     } 
     
}
