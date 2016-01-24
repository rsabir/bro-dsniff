type POSTGRESQL_PDU = record {
	firsthex : uint8;
	suite : case firsthex of{
	      112 -> password_pdu: PASSWORD_PDU;
	      default -> infos_pdu : INFOS_PDU;
	};
	##	restofdata : bytestring &restofdata;
} &byteorder=bigendian;

type PASSWORD_PDU = record{
     len : uint32;
     ## password : bytestring &restofdata;
     password: bytestring &length=len-5;
     restofdata : bytestring &restofdata;
} &byteorder=bigendian;

type INFOS_PDU = record{
     length : uint8[3];
     unknown : uint8[4];
     userquery: RE/user/;
     dot1: uint8;
     user: RE/[a-zA-Z0-9]+/;
     dot2: uint8;
     ## databasequery: RE/database/;
     ## dot2: uint8;
     ## database: RE/[a-zA-Z0-9]+\./;
     restofdata : bytestring &restofdata;
} &byteorder=bigendian;
