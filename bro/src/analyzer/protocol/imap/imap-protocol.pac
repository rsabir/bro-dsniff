type IMAP_PDU(is_orig: bool) = record {
        request_tag : RE/A0001/;
	space : uint8;
	login : RE/LOGIN/;
	space_login : uint8;
	username : RE/[a-zA-Z0-9$*ù.:;!§*%=+()\[\]\{\}\\"#~_-]+/;
	space_username : uint8;
	password : RE/[a-zA-Z0-9$*ù.:;!§*%=+()\[\]\{\}\\"#~_-]+/;
	enter : uint8[2];
} &byteorder=bigendian;