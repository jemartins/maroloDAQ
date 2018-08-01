%define rc_ver          1
%define rel 		1
%define rc_name         1rc1
%if %{rc_ver}
%define tarballver      %{version}-%{rc_name}
%define tarballdir      %{version}-%{rc_name}
%define release		%mkrel %{rc_name}.%{rel}
%else
%define tarballver      %{version}
%define tarballdir      v%{version}
%define release		%mkrel %{rel}
%endif

Summary:	Data analysis and scientific plotting
Name:		maroloDAQ
Version:	1.0.0
Release:	%{release}
License:	GPLv3+
Group:		Sciences/Other
Url:		https://github.com/jemartins/maroloDAQ
Source0:	https://github.com/jemartins/maroloDAQ/archive/%{tarballdir}/maroloDAQ-%{tarballver}.tar.gz
BuildRequires:	qt5-devel >= 5.9.4
BuildRequires:	icoutils
BuildRequires:	imagemagick
BuildRequires:	qt5serialport-devel >= 5.9.4
BuildRequires:	grace-devel
Requires:	lib64qt5serialport5 >= 5.9.4
Requires:	lib64qt5gui5 >= 5.9.4
Requires:	lib64qt5xcbqpa5 >= 5.9.4
Requires:	grace

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
cat > %{buildroot}%{_datadir}/applications/%{name}.desktop << EOF
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

mkdir -p %{buildroot}%{_bindir}
cp maroloDAQ %{buildroot}%{_bindir}/
mkdir -p %{buildroot}%{_libdir}/%{name}
mkdir -p %{buildroot}%{_libdir}/%{name}/fw_maroloDAQ
cp fw_maroloDAQ/fw_maroloDAQ.ino %{buildroot}/%{_libdir}/%{name}/fw_%{name}/fw_maroloDAQ.ino

cd icons
mkdir -p %{buildroot}{%{_liconsdir},%{_iconsdir},%{_miconsdir}}
convert -scale 128 marolodaq_icon.png %{buildroot}%{_liconsdir}/%{name}.png
convert -scale 64 marolodaq_icon.png %{buildroot}%{_liconsdir}/%{name}.png
convert -scale 48 marolodaq_icon.png %{buildroot}%{_liconsdir}/%{name}.png
convert -scale 32 marolodaq_icon.png %{buildroot}%{_iconsdir}/%{name}.png
convert -scale 16 marolodaq_icon.png %{buildroot}%{_miconsdir}/%{name}.png

mkdir -p %{buildroot}%{_iconsdir}/hicolor/16x16/apps/
convert -geometry 16x16 marolodaq_icon.png %{buildroot}%{_iconsdir}/hicolor/16x16/apps/%{name}.png
mkdir -p %{buildroot}%{_iconsdir}/hicolor/32x32/apps/
convert -geometry 32x32 marolodaq_icon.png %{buildroot}%{_iconsdir}/hicolor/32x32/apps/%{name}.png
mkdir -p %{buildroot}%{_iconsdir}/hicolor/48x48/apps/
convert -geometry 48x48 marolodaq_icon.png %{buildroot}%{_iconsdir}/hicolor/48x48/apps/%{name}.png
mkdir -p %{buildroot}%{_iconsdir}/hicolor/64x64/apps/
convert -geometry 64x64 marolodaq_icon.png %{buildroot}%{_iconsdir}/hicolor/64x64/apps/%{name}.png
mkdir -p %{buildroot}%{_iconsdir}/hicolor/128x128/apps/
convert -geometry 128x128 marolodaq_icon.png %{buildroot}%{_iconsdir}/hicolor/128x128/apps/%{name}.png

rm -fr %buildroot/usr/local

%files
%{_bindir}/maroloDAQ
%doc README
%doc AUTHORS
%doc COPYING
%doc INSTALL
%doc LICENSE
%{_libdir}
%{_datadir}/applications/%{name}.desktop
%{_liconsdir}/%{name}.png
%{_iconsdir}/%{name}.png
%{_miconsdir}/%{name}.png
%{_iconsdir}/hicolor/*/apps/*.png

%changelog
* Tue Jul 31 2018 jemartins <jemartins@fis.unb.br> 1.0.0-1rc1.1.mga6
- Initial package

