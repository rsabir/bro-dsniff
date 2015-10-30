global tmp : table[addr,addr] of string;

event smtp_request(c:connection,is_orig:bool,command:string,arg:string){
	

		if ( command == "**" ){
			if ( [c$id$orig_h,c$id$resp_h] in tmp ){
				print fmt("date : %s , ip_src : %s , ip_dst : %s, user : %s , password : %s",
				strftime("%Y/%m/%d %H:%M:%S", c$start_time),
				c$id$orig_h,
				c$id$resp_h,
				tmp[c$id$orig_h,c$id$resp_h],
				decode_base64(arg));
			}
			else 
				tmp[c$id$orig_h,c$id$resp_h] = decode_base64(arg);
		}
		else
			return ;
		
	
}
