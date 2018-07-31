%define rc_ver          1
%define rc_name         1rc1
%if %{rc_ver}
%define tarballver      %{version}-%{rc_name}
%define tarballdir      %{version}-%{rc_name}
%define release		%mkrel -c %{rc_name} %{rel}
%else
%define tarballver      %{version}
%define tarballdir      v%{version}
%define release		%mkrel %{rel}
%endif

%define rel 	1

Summary:	Data analysis and scientific plotting
Name:		maroloDAQ
Version:	1.0.0
Release:	%mkrel -c %{rc_name} %{rel}
License:	GPLv3+
Group:		Sciences/Other
Url:		https://github.com/jemartins/maroloDAQ
Source0:	https://github.com/jemartins/maroloDAQ/archive/%{tarballdir}/maroloDAQ-%{tarballver}.tar.gz
BuildRequires:	qt5-devel >= 4.4.0
BuildRequires:	icoutils
BuildRequires:	imagemagick
BuildRequires:	qt5serialport-devel
Requires:	qt5serialport

%description
Data Logger with Arduino Board

%prep
%setup -qn maroloDAQ-%{tarballver}

%build
%configure 
%make_build

%install
make install INSTALL_ROOT=%{buildroot}

mkdir -p %{buildroot}%{_datadir}/applications
cat > %{buildroot}%{_datadir}/applications/%{_real_vendor}-%{name}.desktop << EOF
[Desktop Entry]
Name=maroloDAQ
Comment=Data Logger with Arduino Board 
Exec=maroloDAQ
Icon=maroloDAQ
Terminal=false
Type=Application
Categories=Qt;Science;DataVisualization;
StartupNotify=true
EOF

mkdir -p %{buildroot}%{_libdir}/maroloDAQ
cp maroloDAQ %{buildroot}%{_libdir}/maroloDAQ/maroloDAQ
mkdir -p %{buildroot}%{_bindir}
ln -sf %{buildroot}%{_libdir}/maroloDAQ/maroloDAQ %{buildroot}%{_bindir}
mkdir -p %{buildroot}%{_libdir}/maroloDAQ/fw_maroloDAQ
cp fw_maroloDAQ/fw_maroloDAQ.ino %{buildroot}/%{_libdir}/maroloDAQ/fw_maroloDAQ/fw_maroloDAQ.ino

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
%doc AUTHORS
%doc COPYING
%doc INSTALL
%doc LICENSE
%{_libdir}
#%{_libdir}/maroloDAQ
%{_datadir}/applications/%{_real_vendor}-%{name}.desktop
%{_liconsdir}/%{name}.png
%{_iconsdir}/%{name}.png
%{_miconsdir}/%{name}.png
%{_iconsdir}/hicolor/*/apps/*.png
#%{_libdir}/maroloDAQ/fw_maroloDAQ/fw_maroloDAQ.ino

%changelog
* Tue Jul 31 2018 jemartins <jemartins@fis.unb.br> 1.0.0-1rc1.1.mga6
- Initial package

