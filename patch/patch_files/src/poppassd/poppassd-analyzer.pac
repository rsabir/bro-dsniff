refine flow POPPASSD_Flow += {

%member{
   	StringVal* username;
       	StringVal* password;
	StringVal* newpassword;
%}

	# function used to save the username
	function proc_poppassd_username(msg: USERNAME_PDU): bool
		%{
		username =  new StringVal(${msg.username}.length(),(const char*)${msg.username}.begin());
		return true;
		%}

	# function used to save the old password
	function proc_poppassd_oldpassword(msg: OLDPASSWORD_PDU): bool
		%{
		password = new StringVal(${msg.password}.length(),(const char*)${msg.password}.begin());
		return true;
		%}
	
	# function used to fire the poppassd_event
	function proc_poppassd_password(msg: PASSWORD_PDU): bool
		%{
		newpassword = new StringVal(${msg.newpassword}.length(),(const char*)${msg.newpassword}.begin());
		BifEvent::generate_poppassd_event(connection()->bro_analyzer(), connection()->bro_analyzer()->Conn() ,
		username,
		password,
		newpassword
		);
		return true;
		%}


};
	

refine typeattr USERNAME_PDU += &let {
	proc: bool = $context.flow.proc_poppassd_username(this);
};


refine typeattr OLDPASSWORD_PDU += &let {
	proc: bool = $context.flow.proc_poppassd_oldpassword(this);
};


refine typeattr PASSWORD_PDU += &let {
	proc: bool = $context.flow.proc_poppassd_password(this);
};