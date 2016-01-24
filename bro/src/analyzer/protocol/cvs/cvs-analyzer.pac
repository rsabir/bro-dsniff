refine flow CVS_Flow += {

	function process_CVS_PDU(m: CVS_PDU): bool
		%{
		BifEvent::generate_CVS_Message(connection()->bro_analyzer(),
		                                  connection()->bro_analyzer()->Conn(),
new StringVal(${m.username}.length(), (const char*) ${m.username}.begin()),
new StringVal(${m.password}.length(), (const char*) ${m.password}.begin())
		);
		return true;
		%}

};

refine typeattr CVS_PDU += &let {
	proc_CVS_PDU = $context.flow.process_CVS_PDU(this);
};
