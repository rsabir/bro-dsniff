
// A work-around the problem that for static libraries unused globals
// aren't linked into the final binary. CMake automatically inserts
// code here to reference the globals that initializes each of the
// statically compiled plugins.
//
// Note: This won't be necessary anymore once we can assume CMake >2.8.8
// as a required depencendy. If so, switch bro_HAVE_OBJECT_LIBRARIES
// in src/CMakeLists.txt to TRUE and remove this.

#include <stdlib.h>

namespace plugin { namespace Bro_ARP { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_AYIYA { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_BackDoor { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_BitTorrent { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_ConnSize { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_DCE_RPC { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_DHCP { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_DNP3 { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_DNS { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_File { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_Finger { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_FTP { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_Gnutella { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_GTPv1 { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_HTTP { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_ICMP { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_Ident { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_InterConn { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_IRC { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_KRB { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_LDAP { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_Login { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_LOL { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_MIME { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_Modbus { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_MySQL { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_NCP { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_NetBIOS { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_NTP { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_PIA { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_POP3 { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_POPPASSD { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_POSTGRESQL { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_RADIUS { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_RDP { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_RLOGIN_ { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_RPC { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_SIP { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_SMB { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_SMTP { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_SNMP { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_SOCKS { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_SSH { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_SSL { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_SteppingStone { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_Syslog { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_TCP { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_Teredo { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_UDP { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_ZIP { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_FileDataEvent { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_FileExtract { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_FileHash { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_PE { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_Unified2 { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_X509 { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_AsciiReader { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_BenchmarkReader { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_BinaryReader { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_RawReader { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_SQLiteReader { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_Pcap { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_AsciiWriter { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_NoneWriter { class Plugin; extern Plugin plugin; } };
namespace plugin { namespace Bro_SQLiteWriter { class Plugin; extern Plugin plugin; } };


size_t __make_sure_to_use_plugin_globals()
{
    // This function is never actually called.

	size_t i = 0;
    i += (size_t)(&(plugin::Bro_ARP::plugin));
i += (size_t)(&(plugin::Bro_AYIYA::plugin));
i += (size_t)(&(plugin::Bro_BackDoor::plugin));
i += (size_t)(&(plugin::Bro_BitTorrent::plugin));
i += (size_t)(&(plugin::Bro_ConnSize::plugin));
i += (size_t)(&(plugin::Bro_DCE_RPC::plugin));
i += (size_t)(&(plugin::Bro_DHCP::plugin));
i += (size_t)(&(plugin::Bro_DNP3::plugin));
i += (size_t)(&(plugin::Bro_DNS::plugin));
i += (size_t)(&(plugin::Bro_File::plugin));
i += (size_t)(&(plugin::Bro_Finger::plugin));
i += (size_t)(&(plugin::Bro_FTP::plugin));
i += (size_t)(&(plugin::Bro_Gnutella::plugin));
i += (size_t)(&(plugin::Bro_GTPv1::plugin));
i += (size_t)(&(plugin::Bro_HTTP::plugin));
i += (size_t)(&(plugin::Bro_ICMP::plugin));
i += (size_t)(&(plugin::Bro_Ident::plugin));
i += (size_t)(&(plugin::Bro_InterConn::plugin));
i += (size_t)(&(plugin::Bro_IRC::plugin));
i += (size_t)(&(plugin::Bro_KRB::plugin));
i += (size_t)(&(plugin::Bro_LDAP::plugin));
i += (size_t)(&(plugin::Bro_Login::plugin));
i += (size_t)(&(plugin::Bro_LOL::plugin));
i += (size_t)(&(plugin::Bro_MIME::plugin));
i += (size_t)(&(plugin::Bro_Modbus::plugin));
i += (size_t)(&(plugin::Bro_MySQL::plugin));
i += (size_t)(&(plugin::Bro_NCP::plugin));
i += (size_t)(&(plugin::Bro_NetBIOS::plugin));
i += (size_t)(&(plugin::Bro_NTP::plugin));
i += (size_t)(&(plugin::Bro_PIA::plugin));
i += (size_t)(&(plugin::Bro_POP3::plugin));
i += (size_t)(&(plugin::Bro_POPPASSD::plugin));
i += (size_t)(&(plugin::Bro_POSTGRESQL::plugin));
i += (size_t)(&(plugin::Bro_RADIUS::plugin));
i += (size_t)(&(plugin::Bro_RDP::plugin));
i += (size_t)(&(plugin::Bro_RLOGIN_::plugin));
i += (size_t)(&(plugin::Bro_RPC::plugin));
i += (size_t)(&(plugin::Bro_SIP::plugin));
i += (size_t)(&(plugin::Bro_SMB::plugin));
i += (size_t)(&(plugin::Bro_SMTP::plugin));
i += (size_t)(&(plugin::Bro_SNMP::plugin));
i += (size_t)(&(plugin::Bro_SOCKS::plugin));
i += (size_t)(&(plugin::Bro_SSH::plugin));
i += (size_t)(&(plugin::Bro_SSL::plugin));
i += (size_t)(&(plugin::Bro_SteppingStone::plugin));
i += (size_t)(&(plugin::Bro_Syslog::plugin));
i += (size_t)(&(plugin::Bro_TCP::plugin));
i += (size_t)(&(plugin::Bro_Teredo::plugin));
i += (size_t)(&(plugin::Bro_UDP::plugin));
i += (size_t)(&(plugin::Bro_ZIP::plugin));
i += (size_t)(&(plugin::Bro_FileDataEvent::plugin));
i += (size_t)(&(plugin::Bro_FileExtract::plugin));
i += (size_t)(&(plugin::Bro_FileHash::plugin));
i += (size_t)(&(plugin::Bro_PE::plugin));
i += (size_t)(&(plugin::Bro_Unified2::plugin));
i += (size_t)(&(plugin::Bro_X509::plugin));
i += (size_t)(&(plugin::Bro_AsciiReader::plugin));
i += (size_t)(&(plugin::Bro_BenchmarkReader::plugin));
i += (size_t)(&(plugin::Bro_BinaryReader::plugin));
i += (size_t)(&(plugin::Bro_RawReader::plugin));
i += (size_t)(&(plugin::Bro_SQLiteReader::plugin));
i += (size_t)(&(plugin::Bro_Pcap::plugin));
i += (size_t)(&(plugin::Bro_AsciiWriter::plugin));
i += (size_t)(&(plugin::Bro_NoneWriter::plugin));
i += (size_t)(&(plugin::Bro_SQLiteWriter::plugin));

	return i;
}
