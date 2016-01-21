/* Old libpcap versions (< 0.6.1) need defining pcap_freecode and
   pcap_compile_nopcap */
/* #undef DONT_HAVE_LIBPCAP_PCAP_FREECODE */

/* should explicitly declare socket() and friends */
/* #undef DO_SOCK_DECL */

/* Define if you have the <getopt.h> header file. */
#define HAVE_GETOPT_H

/* Define if you have the `getopt_long' function. */
#define HAVE_GETOPT_LONG

/* We are on a Linux system */
#define HAVE_LINUX

/* Define if you have the `mallinfo' function. */
#define HAVE_MALLINFO

/* Define if you have the <memory.h> header file. */
#define HAVE_MEMORY_H

/* Define if you have the <netinet/if_ether.h> header file. */
#define HAVE_NETINET_IF_ETHER_H

/* Define if you have the <netinet/ip6.h> header file. */
#define HAVE_NETINET_IP6_H

/* Define if you have the <net/ethernet.h> header file. */
#define HAVE_NET_ETHERNET_H

/* Define if you have the <net/ethertypes.h> header file. */
/* #undef HAVE_NET_ETHERTYPES_H */

/* have os-proto.h */
/* #undef HAVE_OS_PROTO_H */

/* Define if you have the <pcap-int.h> header file. */
/* #undef HAVE_PCAP_INT_H */

/* line editing & history powers */
/* #undef HAVE_READLINE */

/* Define if you have the `sigaction' function, but not `sigset'. */
/* #undef HAVE_SIGACTION */

/* Define if you have the `sigset' function. */
#define HAVE_SIGSET

/* Define if you have the `strcasestr' function. */
#define HAVE_STRCASESTR

/* Define if you have the `strerror' function. */
#define HAVE_STRERROR

/* Define if you have the `strsep' function. */
#define HAVE_STRSEP

/* Define if you have the <sys/ethernet.h> header file. */
/* #undef HAVE_SYS_ETHERNET_H */

/* Some libpcap versions use an extra parameter (error) in pcap_compile_nopcap
   */
/* #undef LIBPCAP_PCAP_COMPILE_NOPCAP_HAS_ERROR_PARAMETER */

/* Include krb5.h */
/* #undef NEED_KRB5_H */

/* Compatibility for Darwin */
/* #undef NEED_NAMESER_COMPAT_H */

/* d2i_x509 uses const char** */
#define OPENSSL_D2I_X509_USES_CONST_CHAR

/* Define as the return type of signal handlers (`int' or `void'). */
#define RETSIGTYPE void

/* signal function return value */
#define RETSIGVAL 

/* have sin_len field in sockaddr_in */
/* #undef SIN_LEN */

/* The size of `long int', as computed by sizeof. */
#define SIZEOF_LONG_INT 8

/* The size of `long long', as computed by sizeof. */
#define SIZEOF_LONG_LONG 8

/* The size of `void *', as computed by sizeof. */
#define SIZEOF_VOID_P 8

/* should we declare syslog() and openlog() */
/* #undef SYSLOG_INT */

/* Define if you have <sys/time.h> */
#define HAVE_SYS_TIME_H

/* Define if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME

/* GeoIP geographic lookup functionality */
/* #undef USE_GEOIP */

/* Whether the found GeoIP API supports IPv6 Country Edition */
/* #undef HAVE_GEOIP_COUNTRY_EDITION_V6 */

/* Whether the found GeoIP API supports IPv6 City Edition */
/* #undef HAVE_GEOIP_CITY_EDITION_REV0_V6 */

/* Use Google's perftools */
/* #undef USE_PERFTOOLS_DEBUG */

/* Analyze Mobile IPv6 traffic */
/* #undef ENABLE_MOBILE_IPV6 */

/* Use libCurl. */
/* #undef USE_CURL */

/* Use the DataSeries writer. */
/* #undef USE_DATASERIES */

/* Use the ElasticSearch writer. */
/* #undef USE_ELASTICSEARCH */

/* Version number of package */
#define VERSION "2.4.1"

/* whether words are stored with the most significant byte first */
/* #undef WORDS_BIGENDIAN */

/* whether htonll/ntohll is defined in <arpa/inet.h> */
/* #undef HAVE_BYTEORDER_64 */

/* ultrix can't hack const */
/* #undef NEED_ULTRIX_CONST_HACK */
#ifdef NEED_ULTRIX_CONST_HACK
#define const
#endif

/* Define int32_t */
/* #undef int32_t */

/* use sigset() instead of signal() */
#ifdef HAVE_SIGSET
#define signal sigset
#endif

/* define to int if socklen_t not available */
/* #undef socklen_t */

/* Define u_int16_t */
/* #undef u_int16_t */

/* Define u_int32_t */
/* #undef u_int32_t */

/* Define u_int8_t */
/* #undef u_int8_t */

/* OpenBSD's bpf.h may not declare this data link type, but it's supposed to be
   used consistently for the same purpose on all platforms. */
#define HAVE_DLT_PPP_SERIAL
#ifndef HAVE_DLT_PPP_SERIAL
#define DLT_PPP_SERIAL 
#endif

/* IPv6 Next Header values defined by RFC 3542 */
#define HAVE_IPPROTO_HOPOPTS
#ifndef HAVE_IPPROTO_HOPOPTS
#define IPPROTO_HOPOPTS 0
#endif
#define HAVE_IPPROTO_IPV6
#ifndef HAVE_IPPROTO_IPV6
#define IPPROTO_IPV6 41
#endif
/* #undef HAVE_IPPROTO_IPV4 */
#ifndef HAVE_IPPROTO_IPV4
#define IPPROTO_IPV4 4
#endif
#define HAVE_IPPROTO_ROUTING
#ifndef HAVE_IPPROTO_ROUTING
#define IPPROTO_ROUTING 43
#endif
#define HAVE_IPPROTO_FRAGMENT
#ifndef HAVE_IPPROTO_FRAGMENT
#define IPPROTO_FRAGMENT 44
#endif
#define HAVE_IPPROTO_ESP
#ifndef HAVE_IPPROTO_ESP
#define IPPROTO_ESP 50
#endif
#define HAVE_IPPROTO_AH
#ifndef HAVE_IPPROTO_AH
#define IPPROTO_AH 51
#endif
#define HAVE_IPPROTO_ICMPV6
#ifndef HAVE_IPPROTO_ICMPV6
#define IPPROTO_ICMPV6 58
#endif
#define HAVE_IPPROTO_NONE
#ifndef HAVE_IPPROTO_NONE
#define IPPROTO_NONE 59
#endif
#define HAVE_IPPROTO_DSTOPTS
#ifndef HAVE_IPPROTO_DSTOPTS
#define IPPROTO_DSTOPTS 60
#endif

/* IPv6 options structure defined by RFC 3542 */
#define HAVE_IP6_OPT

/* Common IPv6 extension structure */
#define HAVE_IP6_EXT

/* String with host architecture (e.g., "linux-x86_64") */
#define HOST_ARCHITECTURE "linux-x86_64"

/* String with extension of dynamic libraries (e.g., ".so") */
#define DYNAMIC_PLUGIN_SUFFIX ".so"

/* True if we're building outside of the main Bro source code tree. */
#ifndef BRO_PLUGIN_INTERNAL_BUILD
#define BRO_PLUGIN_INTERNAL_BUILD true
#endif
