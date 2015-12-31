refine flow RSH_Flow += {
       	function proc_rsh_username(msg: RSH_PDU): bool
		%{
		BifEvent::generate_rsh_username(connection()->bro_analyzer(),
		 connection()->bro_analyzer()->Conn(),
       		 new StringVal(${msg.clientUsername}.length(), (const char*) ${msg.clientUsername}.begin()),
	        new StringVal(${msg.serverUsername}.length(), (const char*) ${msg.serverUsername}.begin()));
		return true;
		%}
};

refine typeattr RSH_PDU += &let {
	proc: bool = $context.flow.proc_rsh_username(this);
};