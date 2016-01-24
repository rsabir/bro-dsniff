type RLOGIN__PDU = record {
	clientUsername : RE/[a-zA-Z0-9]+/;
	pointO    : uint8 &check(pointO == ".");
	serverUsername : RE/[a-zA-Z0-9]+/;
	pointT    : uint8 &check(pointT == ".");
	restOfData : RE/([a-zA-Z0-9]+)\/([0-9]{2,})/;
} &byteorder=bigendian;

type RLOGIN_PASSWORD = record{
      data : RE/Password\:.*/;
} &byteorder=bigendian;

type RLOGIN_DATA = record{
        data : bytestring &restofdata;
} &byteorder=bigendian;
