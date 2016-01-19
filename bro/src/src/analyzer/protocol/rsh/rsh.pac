%include binpac.pac
%include bro.pac

%extern{
	#include "events.bif.h"
%}

analyzer RSH withcontext {
	connection: RSH_Conn;
	flow:       RSH_Flow;
};

connection RSH_Conn(bro_analyzer: BroAnalyzer) {
	upflow   = RSH_Flow;
	downflow = RSH_Flow;
};

%include rsh-protocol.pac

flow RSH_Flow {
	datagram = RSH_PDU withcontext(connection, this);
};

%include rsh-analyzer.pac