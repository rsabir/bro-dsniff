# Patch bro-dsniff
To install the patch, you have to get the root privilege and to follow these steps :
 - Set the BRO_HOME value to the path of the BRO's directory. For example : 
 
    >export BRO_HOME=/root/Downloads/bro/
 - run the script path.sh :
 
    >*./patch.sh*
 - rebuild bro :
 
    >cd $BRO_HOME && ./configure && make && make install && export PATH=/usr/local/bro/bin:$PATH

 - And now you can test the patch by using pcaps files in **patch_files/pcap/**. For example: 
 
    >bro -r patch_files/pcap/cvs.pcapng 
