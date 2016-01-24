# bro-dsniff

*Final Year project at ENSEIRB MATMECA.*

This project is intended to sniff username and password from the lan as dsniff do by using the Bro ID.
Also some new dissectors will be added to bro.

Here's the list of protocols where bro-dsniff can sniff password :

    -SMTP
    -IRC
    -SNMP
    -POP
    -SOCKS
    -HTTP Basic Authentication
    -IMAP
    -PostgreSQL
    -CVS
    -NNTP
    -Rlogin
    -Telnet
    -poppassd
    -LDAP
    -TACACS

You can etheir use the bro directory and compile it to get bro-dsniff

    >./configure && make && make install

Or you can use the path under the directory patch.



