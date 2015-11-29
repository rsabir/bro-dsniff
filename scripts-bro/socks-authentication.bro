global tmp : table[addr,addr] of string;


event socks_login_userpass_request(c: connection, user: string, password: string){
	     	print fmt("date : %s , ip_src : %s , ip_dst : %s,  user : %s , password : %s",
		      strftime("%Y/%m/%d %H:%M:%S", c$start_time),
		      c$id$orig_h,
		      c$id$resp_h, 
		      user,
		      password);
     
}