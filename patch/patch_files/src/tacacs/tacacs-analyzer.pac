refine flow TACACS_Flow += {
	function proc_tacacs_message(msg: TACACS_PDU): bool
		%{
		BifEvent::generate_tacacs_auth(connection()->bro_analyzer(), connection()->bro_analyzer()->Conn(),
		new StringVal(${msg.username}.length(), (const char*) ${msg.username}.data()),
		new StringVal(${msg.password}.length(), (const char*) ${msg.password}.data())
		);
		return true;
		%}
};

refine typeattr TACACS_PDU += &let {
	proc: bool = $context.flow.proc_tacacs_message(this);
};
