refine flow LDAP_Flow += {
	function proc_ldap_message(msg: LDAP_PDU): bool
		%{
		BifEvent::generate_ldap_simple_bind(connection()->bro_analyzer(), 
		connection()->bro_analyzer()->Conn(),
        	new StringVal(${msg.username}.length(), (const char*) ${msg.username}.begin()),
	        new StringVal(${msg.password}.length(), (const char*) ${msg.password}.begin())
		);
		return true;
		%}
};

refine typeattr LDAP_PDU += &let {
	proc: bool = $context.flow.proc_ldap_message(this);
};