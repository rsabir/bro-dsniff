
# Analyzer for RLOGIN Protocol 2
#  - rlogin_-protocol.pac: describes the rlogin_ protocol messages
#  - rlogin_-analyzer.pac: describes the rlogin_ analyzer code

%include binpac.pac
%include bro.pac

%extern{
	#include "events.bif.h"
%}

analyzer RLOGIN_ withcontext {
	connection: RLOGIN__Conn;
	flow:       RLOGIN__Flow;
};

# Our connection consists of two flows, one in each direction.
connection RLOGIN__Conn(bro_analyzer: BroAnalyzer) {
	upflow   = RLOGIN__Flow;
	downflow = RLOGIN__Flow;
};

%include rlogin_-protocol.pac

# Now we define the flow:
flow RLOGIN__Flow {

	# ## TODO: Determine if you want flowunit or datagram parsing:

	# Using flowunit will cause the anlayzer to buffer incremental input.
	# This is needed for &oneline and &length. If you don't need this, you'll
	# get better performance with datagram.

	# flowunit = RLOGIN__PDU(is_orig) withcontext(connection, this);
	datagram = RLOGIN__PDU withcontext(connection, this);

};

%include rlogin_-analyzer.pac