# Analyzer for RLOGIN Protocol
#  - rlogin-protocol.pac: describes the rlogin protocol messages
#  - rlogin-analyzer.pac: describes the rlogin analyzer code

%include binpac.pac
%include bro.pac

%extern{
	#include "events.bif.h"
%}

analyzer RLOGIN withcontext {
	connection: RLOGIN_Conn;
	flow:       RLOGIN_Flow;
};

# Our connection consists of two flows, one in each direction.
connection RLOGIN_Conn(bro_analyzer: BroAnalyzer) {
	upflow   = RLOGIN_Flow;
	downflow = RLOGIN_Flow;
};

%include rlogin-protocol.pac

# Now we define the flow:
flow RLOGIN_Flow {

	# ## TODO: Determine if you want flowunit or datagram parsing:

	# Using flowunit will cause the anlayzer to buffer incremental input.
	# This is needed for &oneline and &length. If you don't need this, you'll
	# get better performance with datagram.

	# flowunit = RLOGIN_PDU(is_orig) withcontext(connection, this);
	datagram = RLOGIN_PDU withcontext(connection, this);

};

%include rlogin-analyzer.pac