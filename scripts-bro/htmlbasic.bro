##global tmp : table[addr,addr] of string;


event http_header(c: connection, is_orig: bool, name: string, value: string){
    if (/AUTHORIZATION/ in name && /Basic/ in value){
        local auth = split1(decode_base64(sub_bytes(value, 7, |value|)), /:/);
       	print fmt("date : %s , ip_src : %s , ip_dst : %s,  protocole : http , user : %s, password : %s",
 	    strftime("%Y/%m/%d %H:%M:%S", c$start_time),
 	    c$id$orig_h,
 	    c$id$resp_h, 
 	    auth[1],
	    auth[2]
	    );
    }
}

