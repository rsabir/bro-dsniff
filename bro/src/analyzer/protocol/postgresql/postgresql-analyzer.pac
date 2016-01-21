
refine flow POSTGRESQL_Flow += {

%member{
	StringVal* username;
%}

	function proc_postgresql_event(msg: POSTGRESQL_PDU): bool
		%{
		
		return true;
		%}

	function proc_postgresql_infos(msg: INFOS_PDU): bool
		%{
		username = new StringVal(${msg.user}.length(),(const char*)${msg.user}.begin());
		return true;
		%}


	function proc_postgresql_password(msg: PASSWORD_PDU): bool
		%{
		BifEvent::generate_postgresql_password(connection()->bro_analyzer(), connection()->bro_analyzer()->Conn() ,
		new StringVal(${msg.password}.length(),(const char*)${msg.password}.begin()),
		username
		);
		return true;
		%}
};

refine typeattr POSTGRESQL_PDU += &let {
	proc: bool = $context.flow.proc_postgresql_event(this);
};

refine typeattr INFOS_PDU += &let {
	proc: bool = $context.flow.proc_postgresql_infos(this);
};

refine typeattr PASSWORD_PDU += &let {
	proc: bool = $context.flow.proc_postgresql_password(this);
};