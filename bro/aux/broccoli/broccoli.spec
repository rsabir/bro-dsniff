Summary: The Bro Client Communications Library
Name: broccoli
Version: 1.92
Release: 9
License: BSD
Group: Development/Libraries
URL: http://www.bro.org
Source: http://www.bro.org/downloads/release/%{name}-%{version}.tar.gz
Packager: Derek Ditch <derek.ditch@gmail.com> 

Requires: openssl >= 0.9.7a, python-libs, libpcap

BuildRequires:	cmake >= 2.6.3, openssl-devel >= 0.9.7a, flex, bison, python-devel, swig, libpcap-devel

%description
Broccoli enables your applications to speak the Bro communication protocol,
allowing you to compose, send, request, and receive events. You can register
your own event handlers. You can talk to other Broccoli applications or Bro
agents -- Bro agents cannot tell whether they are talking to another
Bro or a Broccoli application. Communications can be SSL-encrypted. Broccoli
turns Bro into a distributed policy-controlled event management system.

%prep
%setup -q

%build
./configure --prefix=%{_prefix} --libdir=%{_libdir} --conf-files-dir=%{_sysconfdir}/bro --python-install-dir=%{python_sitearch}
make %{?_smp_mflags}

%install
rm -rf %{buildroot}
make DESTDIR=%{buildroot} install
install -m 755 -d %{buildroot}/%{_bindir}

%clean
rm -rf %{buildroot}

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%defattr(-,root,root,-)
%doc AUTHORS COPYING README TODO
%{_libdir}/lib*.so.*
%{_libdir}/libbroccoli.so
%{_libdir}/lib*a
%{python_sitearch}/_broccoli_intern.so
%{python_sitearch}/broccoli.py*
%{_prefix}/include/broccoli.h
%{_prefix}/bin/bro*
/etc/bro/broccoli.conf

%changelog
* Sun Aug 11 2013 Derek Ditch <derek.ditch@gmail.com>
- Updated severely outdated spec file
* Mon Dec 06 2004 Christian Kreibich <christian@whoop.org> 
- Added spec file to tree.
