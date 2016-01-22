type IMAP_PDU(is_orig: bool) = record {
        request_tag : RE/A0001/;
	space : uint8;
	login : RE/LOGIN/;
	space_login : uint8;
	username : RE/[A-Za-z0-9_]+/;
	space_username : uint8;
	password : RE/[A-Za-z0-9_]+/;
	enter : uint8[2];
} &byteorder=bigendian;