/* These autoconf variables are obsolete; it's portable to assume C89
   and signal handlers that return void */
#define RETSIGTYPE void
#define RETSIGVAL 

/* Define if you have the `sigaction' function. */
/* #undef HAVE_SIGACTION */

/* Define if you have the `sigset' function. */
#define HAVE_SIGSET

/* Define if you have the <memory.h> header file. */
#define HAVE_MEMORY_H

/* Define if you have the `strerror' function. */
#define HAVE_STRERROR

/* should explicitly declare socket() and friends */
/* #undef DO_SOCK_DECL */

/* Compatibility for Darwin */
/* #undef NEED_NAMESER_COMPAT_H */

/* have os-proto.h */
/* #undef HAVE_OS_PROTO_H */

/* have sin_len field in sockaddr_in */
/* #undef SIN_LEN */
