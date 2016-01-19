type RSH_PDU = record {
	clientUsername : RE/[a-zA-Z0-9]*/;
	pointO    : uint8 &check(pointO == ".");
	serverUsername : RE/[a-zA-Z0-9]*/;
	pointT    : uint8 &check(pointT == ".");
	restOfData : RE/(.*)\/(.*)/;
} &byteorder=bigendian;