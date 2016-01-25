type TELNET__PDU(is_orig: bool) = record {
	data: bytestring &restofdata;
} &byteorder=bigendian;