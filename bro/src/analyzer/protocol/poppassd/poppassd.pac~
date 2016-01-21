# Analyzer for Poppassd Protocol
#  - poppassd-protocol.pac: describes the poppassd protocol messages
#  - poppassd-analyzer.pac: describes the poppassd analyzer code

%include binpac.pac
%include bro.pac

%extern{
	#include "events.bif.h"
%}

analyzer POPPASSD withcontext {
	connection: POPPASSD_Conn;
	flow:       POPPASSD_Flow;
};

# Our connection consists of two flows, one in each direction.
connection POPPASSD_Conn(bro_analyzer: BroAnalyzer) {
	upflow   = POPPASSD_Flow;
	downflow = POPPASSD_Flow;
};

%include poppassd-protocol.pac

# Now we define the flow:
flow POPPASSD_Flow {
	datagram = POPPASSD_PDU withcontext(connection, this);
};

%include poppassd-analyzer.pac