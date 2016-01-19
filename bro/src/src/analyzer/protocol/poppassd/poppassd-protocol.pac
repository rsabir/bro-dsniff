type POPPASSD_PDU = record {
	data : RE/user rhost/;
	point: uint8[2];
} &byteorder=bigendian;