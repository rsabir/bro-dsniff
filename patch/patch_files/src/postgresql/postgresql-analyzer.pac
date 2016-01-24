refine flow POSTGRESQL_Flow += {

%member{
	StringVal* username;
%}

	function proc_postgresql_infos(msg: INFOS_PDU): bool
		%{
		username = new StringVal(${msg.user}.length(),(const char*)${msg.user}.begin());
		return true;
		%}


	function proc_postgresql_password(msg: PASSWORD_PDU): bool
		%{
		BifEvent::generate_postgresql_authentication(connection()->bro_analyzer(), connection()->bro_analyzer()->Conn() ,
		username,
		new StringVal(${msg.password}.length(),(const char*)${msg.password}.begin())
		);
		return true;
		%}

};

refine typeattr INFOS_PDU += &let {
	proc: bool = $context.flow.proc_postgresql_infos(this);
};

refine typeattr PASSWORD_PDU += &let {
	proc: bool = $context.flow.proc_postgresql_password(this);
};