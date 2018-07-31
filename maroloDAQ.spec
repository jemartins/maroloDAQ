Summary:	Data analysis and scientific plotting
Name:		maroloDAQ
Version:	1.0.0
Release:	%mkrel 1
License:	GPLv3+
Group:		Sciences/Other
Url:		http://soft.proindependent.com/maroloDAQ.html
Source0:	http://download.berlios.de/maroloDAQ/%{name}-%{version}.tar.gz

#BuildRequires:	python-devel
BuildRequires:	qt4-devel >= 4.4.0
BuildRequires:	qt-assistant-adp-devel
#BuildRequires:	libqwtplot3d-devel
BuildRequires:	gsl-devel
BuildRequires:	icoutils
#BuildRequires:	muparser-devel >= 1.32
#BuildRequires:	libqwt-devel >= 5.2.0
#BuildRequires:	python-qt4 >= 4.4.4
BuildRequires:	imagemagick
BuildRequires:	docbook-utils
BuildRequires:	docbook-dtd44-xml
Requires:	qt-assistant-adp
#Requires:	python-qt4 >= 4.4.4

%description
Data analysis and scientific plotting.
Free clone of Origin.

%prep
%setup -q
#popd

%build
%configure --disable-shared --enable-static
%make_build
#%qmake \
#	%if "%{_lib}" != "lib"
#		libsuff=64 \
#	%endif
#	-o Makefile

%install
make install INSTALL_ROOT=%{buildroot}

mkdir -p %{buildroot}%{_datadir}/applications
cat > %{buildroot}%{_datadir}/applications/%{_real_vendor}-%{name}.desktop << EOF
[Desktop Entry]
Name=maroloDAQ
Comment=Data analysis and scientific plotting
Exec=maroloDAQ
Icon=maroloDAQ
Terminal=false
Type=Application
Categories=Qt;Science;DataVisualization;
StartupNotify=true
EOF

mkdir -p %{buildroot}%{_bindir}
cp maroloDAQ %{buildroot}%{_bindir}/maroloDAQ
#mkdir -p %{buildroot}%{_docdir}
#cp README.md %{buildroot}%{_docdir}/README

cd icons
mkdir -p %{buildroot}{%{_liconsdir},%{_iconsdir},%{_miconsdir}}
convert -scale 48 marolodaq_icon_edited.jpeg %{buildroot}%{_liconsdir}/%{name}.png
convert -scale 32 marolodaq_icon_edited.jpeg %{buildroot}%{_iconsdir}/%{name}.png
convert -scale 16 marolodaq_icon_edited.jpeg %{buildroot}%{_miconsdir}/%{name}.png

mkdir -p %{buildroot}%{_iconsdir}/hicolor/16x16/apps/
convert -geometry 16x16 marolodaq_icon_edited.jpeg %{buildroot}%{_iconsdir}/hicolor/16x16/apps/%{name}.png
mkdir -p %{buildroot}%{_iconsdir}/hicolor/32x32/apps/
convert -geometry 32x32 marolodaq_icon_edited.jpeg %{buildroot}%{_iconsdir}/hicolor/32x32/apps/%{name}.png
mkdir -p %{buildroot}%{_iconsdir}/hicolor/48x48/apps/
convert -geometry 48x48 marolodaq_icon_edited.jpeg %{buildroot}%{_iconsdir}/hicolor/48x48/apps/%{name}.png

rm -fr %buildroot/usr/local

%files
%{_bindir}/maroloDAQ
%doc README
#%{_mandir}/man1/maroloDAQ.1.*
#%{_libdir}/maroloDAQ/plugins
#%{_datadir}/maroloDAQ
%{_datadir}/applications/%{_real_vendor}-%{name}.desktop
%{_liconsdir}/%{name}.png
%{_iconsdir}/%{name}.png
%{_miconsdir}/%{name}.png
%{_iconsdir}/hicolor/*/apps/*.png


%changelog
* Tue Jan 26 2016 luigiwalser <luigiwalser> 0.9.8.5-12.mga6
+ Revision: 927770
- add patches from debian to fix build with gsl version 2 and a stack overflow
- rebuild for gsl

* Wed Oct 21 2015 danf <danf> 0.9.8.5-11.mga6
+ Revision: 893176
- Fixed build by packaging docs

* Thu Aug 27 2015 cjw <cjw> 0.9.8.5-10.mga6
+ Revision: 870149
- rebuild with gcc 5

* Wed Oct 15 2014 umeabot <umeabot> 0.9.8.5-9.mga5
+ Revision: 749384
- Second Mageia 5 Mass Rebuild

* Tue Sep 16 2014 umeabot <umeabot> 0.9.8.5-8.mga5
+ Revision: 688547
- Mageia 5 Mass Rebuild

* Fri Jun 06 2014 wally <wally> 0.9.8.5-7.mga5
+ Revision: 634206
- rebuild for new muparser

* Thu Jan 02 2014 danf <danf> 0.9.8.5-6.mga4
+ Revision: 563992
- Added private-members.patch to fix building by making some private
  class member functions protected

  + umeabot <umeabot>
    - Mageia 4 Mass Rebuild

* Sat Mar 23 2013 wally <wally> 0.9.8.5-5.mga3
+ Revision: 404708
- fix desktop file name
- replace obsolete py_requires macro
- clean .spec a bit

* Thu Jan 17 2013 sander85 <sander85> 0.9.8.5-4.mga3
+ Revision: 389185
- Fix build

  + umeabot <umeabot>
    - Mass Rebuild - https://wiki.mageia.org/en/Feature:Mageia3MassRebuild

* Thu May 12 2011 mikala <mikala> 0.9.8.5-3.mga1
+ Revision: 97565
- Rebuild for 'new' muparser (mga#1251)

* Mon May 02 2011 mikala <mikala> 0.9.8.5-2.mga1
+ Revision: 94240
- Remove BuildRoot tag
- Remove mdk macros
- imported package maroloDAQ


* Sat Mar 19 2011 Funda Wang <fwang@mandriva.org> 0.9.8.5-1mdv2011.0
+ Revision: 646499
- drop conditioned plugins
- New version 0.9.8.5

* Fri Mar 18 2011 Funda Wang <fwang@mandriva.org> 0.9.8.4-1
+ Revision: 646290
- build static qwtplot3d
- rework build patch
- add tamu-anova tarball to build
- new version 0.9.8.4
- new versino 0.9.8.3

* Thu Sep 02 2010 Funda Wang <fwang@mandriva.org> 0.9.8.2-1mdv2011.0
+ Revision: 575356
- new version 0.9.8.2

* Sat Aug 28 2010 Funda Wang <fwang@mandriva.org> 0.9.8.1-1mdv2011.0
+ Revision: 573758
- fix build with gcc 4.5
- new version 0.9.8.1

* Tue Aug 24 2010 Funda Wang <fwang@mandriva.org> 0.9.8-4mdv2011.0
+ Revision: 572588
- rebuild for new boost

* Thu Aug 05 2010 Funda Wang <fwang@mandriva.org> 0.9.8-3mdv2011.0
+ Revision: 566279
- rebuild for new boost

* Sat Jul 31 2010 Funda Wang <fwang@mandriva.org> 0.9.8-2mdv2011.0
+ Revision: 563956
- BR qt-assistant-adp

* Sun Jul 11 2010 Funda Wang <fwang@mandriva.org> 0.9.8-1mdv2011.0
+ Revision: 550646
- new version 0.9.8

* Fri Apr 23 2010 Funda Wang <fwang@mandriva.org> 0.9.7.14-2mdv2010.1
+ Revision: 538051
- bump rel
- new version 0.9.7.14

* Thu Mar 18 2010 Funda Wang <fwang@mandriva.org> 0.9.7.13-1mdv2010.1
+ Revision: 524987
- new version 0.9.7.13

* Thu Feb 11 2010 Funda Wang <fwang@mandriva.org> 0.9.7.12-1mdv2010.1
+ Revision: 504355
- bump muparser req
- build fixes
- New version 0.9.7.12

* Mon Feb 08 2010 Anssi Hannula <anssi@mandriva.org> 0.9.7.11-5mdv2010.1
+ Revision: 501882
- rebuild for new boost

* Wed Feb 03 2010 Funda Wang <fwang@mandriva.org> 0.9.7.11-4mdv2010.1
+ Revision: 500085
- rebuild for new boost

* Wed Jan 06 2010 J√©r√¥me Brenier <incubusss@mandriva.org> 0.9.7.11-3mdv2010.1
+ Revision: 486945
- rework Patch0 for a more complete install
- clean specfile
- remove old gcc44 patch from sources

* Tue Jan 05 2010 Funda Wang <fwang@mandriva.org> 0.9.7.11-1mdv2010.1
+ Revision: 486427
- New version 0.9.7.11
- New version 0.9.7.10
- rebuild

* Sun Sep 20 2009 Funda Wang <fwang@mandriva.org> 0.9.7.9-1mdv2010.0
+ Revision: 444825
- New version 0.9.7.9
- New version 0.9.7.8

* Fri May 01 2009 Funda Wang <fwang@mandriva.org> 0.9.7.7-1mdv2010.0
+ Revision: 369388
- New version 0.9.7.7

* Fri Mar 13 2009 Funda Wang <fwang@mandriva.org> 0.9.7.5-1mdv2009.1
+ Revision: 354458
- use boundled qwt and qwtplot3d
- New version 0.9.7.5
- update patches
- new version 0.9.7.4
- New version 0.9.7.3

  + Oden Eriksson <oeriksson@mandriva.com>
    - lowercase ImageMagick

* Sat Oct 11 2008 Funda Wang <fwang@mandriva.org> 0.9.7.2-1mdv2009.1
+ Revision: 291885
- New version 0.7.7.2

* Tue Aug 05 2008 Funda Wang <fwang@mandriva.org> 0.9.7-2mdv2009.0
+ Revision: 263960
- rebuild for new compile flags

* Tue Jul 22 2008 Funda Wang <fwang@mandriva.org> 0.9.7-1mdv2009.0
+ Revision: 240438
- add gcc 4.3 patch
- New version 0.9.7

  + Pixel <pixel@mandriva.com>
    - rpm filetriggers deprecates update_menus/update_scrollkeeper/update_mime_database/update_icon_cache/update_desktop_database/post_install_gconf_schemas

* Tue May 20 2008 Funda Wang <fwang@mandriva.org> 0.9.6.2-1mdv2009.0
+ Revision: 209545
- New version 0.9.6.2

* Thu May 15 2008 Funda Wang <fwang@mandriva.org> 0.9.6-1mdv2009.0
+ Revision: 207532
- install binaries
- Increase versioned BR
- New version 0.9.6

* Sat Mar 08 2008 Funda Wang <fwang@mandriva.org> 0.9.3-1mdv2008.1
+ Revision: 182066
- New version 0.9.3
- BR docbook-dtd44-xml
- BR docbook-utils
- Disable parallel build
- New version 0.9.3 rc3
- rediff patch0

  + Olivier Blin <oblin@mandriva.com>
    - restore BuildRoot

* Tue Dec 18 2007 Funda Wang <fwang@mandriva.org> 0.9.3-0.rc2.1mdv2008.1
+ Revision: 131997
- New version 0.9.3 rc2

  + Thierry Vignaud <tv@mandriva.org>
    - kill re-definition of %%buildroot on Pixel's request

* Fri Nov 30 2007 Funda Wang <fwang@mandriva.org> 0.9.2-1mdv2008.1
+ Revision: 114071
- update to new version 0.9.2

* Wed Nov 14 2007 Funda Wang <fwang@mandriva.org> 0.9.1-1mdv2008.1
+ Revision: 108699
- New version 0.9.1

* Fri Oct 12 2007 Funda Wang <fwang@mandriva.org> 0.9-1mdv2008.1
+ Revision: 97266
- Use system muparser
- BR muparser
- More work on compile patch
- BR python-devel
- BR python-qt4
- New version 0.9
- Rediff patch

  + Thierry Vignaud <tv@mandriva.org>
    - kill desktop-file-validate's 'warning: key "Encoding" in group "Desktop Entry" is deprecated'

* Sat Jul 21 2007 Funda Wang <fwang@mandriva.org> 0.9-0.rc3.1mdv2008.0
+ Revision: 54292
- fix build on x86_64
- fix desktop entry location
- use xdg menu item and icon theme
- SILNET: do not build python plugin
- Compile against system-wide libraries
- BR qt4 rather than qt3
- New version
- Correct tarball dir
  remove old menu
- Renew tarball

  + Tomasz Pawel Gajc <tpg@mandriva.org>
    - update to the latest version


* Sat Sep 16 2006 Stefan van der Eijk <stefan@mandriva.org> 0.8.7-1
- 0.8.7
- Mon Jul 24 2006 Saint-michel laurent <laurent.saintmichel@gmail.com> 0.8.5-1
- New release 0.8.5
- Update of the spec and adapt to XDG menu

* Thu Jan 26 2006 Lenny Cartier <lenny@mandriva.com> 0.7.7-1mdk
- 0.7.7

* Tue Jan 17 2006 Lenny Cartier <lenny@mandriva.com> 0.7.6-1mdk
- 0.7.6

* Wed Dec 21 2005 Lenny Cartier <lenny@mandriva.com> 0.7.5-1mdk
- 0.7.5

* Wed Dec 14 2005 Lenny Cartier <lenny@mandriva.com> 0.7.4-1mdk
- 0.7.4

* Wed Nov 16 2005 Nicolas LÈcureuil <neoclust@mandriva.org> 0.7.2-1mdk
- New release 0.7.2

* Mon Oct 17 2005 Lenny Cartier <lenny@mandriva.com> 0.7-1mdk
- 0.7

* Mon Aug 08 2005 Nicolas LÈcureuil <neoclust@mandriva.org> 0.6.6-1mdk
- New release 0.6.6

* Fri Jul 29 2005 Nicolas LÈcureuil <neoclust@mandriva.org> 0.6.4-2mdk
- Rebuild

* Tue Jul 26 2005 Per √òyvind Karlsen <pkarlsen@mandriva.com> 0.6.4-1mdk
- import to contrib with adaptions

* Wed Apr 06 2005 Olivier Lahaye <olivier.lahaye1@free.fr> 0.5.8-3.2mdk
- Added Desktop menus and icons.

* Wed Apr 06 2005 Olivier Lahaye <olivier.lahaye1@free.fr> 0.5.8-3.1mdk
- Upgrade to V 0.5.8-3

* Wed Mar 02 2005 Olivier Lahaye <olivier.lahaye1@free.fr> 0.5.6-1mdk
- Initial package

