# Analyzer for Ldap Protocol
#  - ldap-protocol.pac: describes the ldap protocol messages
#  - ldap-analyzer.pac: describes the ldap analyzer code

%include binpac.pac
%include bro.pac

%extern{
	#include "events.bif.h"
%}

analyzer LDAP withcontext {
	connection: LDAP_Conn;
	flow:       LDAP_Flow;
};

# Our connection consists of two flows, one in each direction.
connection LDAP_Conn(bro_analyzer: BroAnalyzer) {
	upflow   = LDAP_Flow;
	downflow = LDAP_Flow;
};

%include ldap-protocol.pac

# Now we define the flow:
flow LDAP_Flow {

	# flowunit = LDAP_PDU(is_orig) withcontext(connection, this);
	datagram = LDAP_PDU withcontext(connection, this);

};

%include ldap-analyzer.pac