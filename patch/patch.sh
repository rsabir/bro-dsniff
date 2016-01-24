if [[ -v BRO_HOME ]];
then
    # install the necessary dependencies for bin-pac
    apt-get install python-jinja2 python-docopt
    # set the variable BINPAC_HOME
    BINPAC_HOME=binpac_quickstart
    export BINPAC_HOME;
    cd $BINPAC_HOME
    python start.py IMAP "IMAP Protocol" $BRO_HOME --tcp --buffered
    python start.py postgresql "PostgreSQL Protocol" $BRO_HOME --tcp --buffered
    python start.py cvs "CVS Protocol" $BRO_HOME --tcp --buffered
    python start.py NNTP "NNTP Protocol" $BRO_HOME --tcp --buffered
    python start.py Rlogin_ "Rlogin_ Protocol" $BRO_HOME --tcp --buffered
    python start.py POPPASSD "POPPASSD Protocol" $BRO_HOME --tcp --buffered
    python start.py LDAP  "LDAP Protocol" $BRO_HOME --tcp --buffered
    python start.py TELNET_  "Telnet_ Protocol" $BRO_HOME --tcp --buffered
    python start.py TACACS  "Tacacs Protocol" $BRO_HOME --tcp --buffered
    # return to the root of the patch directory 
    cd -
    cp -r patch_files/src/* $BRO_HOME/src/analyzer/protocol/
    cp -r patch_files/base/* $BRO_HOME/scripts/base/
else
    echo "Please set the var BRO_HOME : export BRO_HOME=/path/to/bro/";
fi
