type LDAP_PDU = record {
     options :  uint8[12];
     username : RE/cn=[a-zA-Z]*,dc=[a-zA-Z]*(,dc=[a-zA-Z]*)*/;
     optionspass: uint8[2];
     password : bytestring &restofdata;
} &byteorder=bigendian;
