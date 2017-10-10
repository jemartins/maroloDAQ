#############################################################################
# Makefile for building: maroloDAQ
# Generated by qmake (3.0) (Qt 5.6.2)
# Project:  maroloDAQ.pro
# Template: app
# Command: /bin/qmake -o Makefile maroloDAQ.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_SERIALPORT_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -g -pipe -Wformat -Werror=format-security -Wp,-D_FORTIFY_SOURCE=2 -fstack-protector --param=ssp-buffer-size=4 -fno-strict-aliasing -DPIC -fPIC -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -std=gnu++0x -O2 -g -pipe -Wformat -Werror=format-security -Wp,-D_FORTIFY_SOURCE=2 -fstack-protector --param=ssp-buffer-size=4 -fno-strict-aliasing -DPIC -fPIC -std=gnu++0x -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -I/usr/lib64/qt5/include -I/usr/lib64/qt5/include/QtWidgets -I/usr/lib64/qt5/include/QtGui -I/usr/lib64/qt5/include/QtSerialPort -I/usr/lib64/qt5/include/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++
QMAKE         = /bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = maroloDAQ1.0.0
DISTDIR = /home/jemartins/Projects/maroloDAQ/.tmp/maroloDAQ1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS) -lQt5Widgets -lQt5Gui -lQt5SerialPort -lQt5Core -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		maroloDAQ.cpp \
		comserial.cpp moc_maroloDAQ.cpp
OBJECTS       = main.o \
		maroloDAQ.o \
		comserial.o \
		moc_maroloDAQ.o
DIST          = /usr/lib64/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib64/qt5/mkspecs/common/unix.conf \
		/usr/lib64/qt5/mkspecs/common/linux.conf \
		/usr/lib64/qt5/mkspecs/common/sanitize.conf \
		/usr/lib64/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt5/mkspecs/common/g++-base.conf \
		/usr/lib64/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt5/mkspecs/qconfig.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_serialport.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_serialport_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_svg.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_svg_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib64/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt5/mkspecs/features/qt_config.prf \
		/usr/lib64/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib64/qt5/mkspecs/features/spec_post.prf \
		/usr/lib64/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt5/mkspecs/features/default_pre.prf \
		/usr/lib64/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib64/qt5/mkspecs/features/default_post.prf \
		/usr/lib64/qt5/mkspecs/features/warn_on.prf \
		/usr/lib64/qt5/mkspecs/features/qt.prf \
		/usr/lib64/qt5/mkspecs/features/resources.prf \
		/usr/lib64/qt5/mkspecs/features/moc.prf \
		/usr/lib64/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib64/qt5/mkspecs/features/uic.prf \
		/usr/lib64/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt5/mkspecs/features/file_copies.prf \
		/usr/lib64/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib64/qt5/mkspecs/features/exceptions.prf \
		/usr/lib64/qt5/mkspecs/features/yacc.prf \
		/usr/lib64/qt5/mkspecs/features/lex.prf \
		maroloDAQ.pro maroloDAQ.h \
		comserial.h main.cpp \
		maroloDAQ.cpp \
		comserial.cpp
QMAKE_TARGET  = maroloDAQ
DESTDIR       = 
TARGET        = maroloDAQ


first: all
####### Build rules

$(TARGET): ui_maroloDAQ.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: maroloDAQ.pro /usr/lib64/qt5/mkspecs/linux-g++/qmake.conf /usr/lib64/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib64/qt5/mkspecs/common/unix.conf \
		/usr/lib64/qt5/mkspecs/common/linux.conf \
		/usr/lib64/qt5/mkspecs/common/sanitize.conf \
		/usr/lib64/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt5/mkspecs/common/g++-base.conf \
		/usr/lib64/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt5/mkspecs/qconfig.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_serialport.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_serialport_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_svg.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_svg_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib64/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt5/mkspecs/features/qt_config.prf \
		/usr/lib64/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib64/qt5/mkspecs/features/spec_post.prf \
		/usr/lib64/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt5/mkspecs/features/default_pre.prf \
		/usr/lib64/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib64/qt5/mkspecs/features/default_post.prf \
		/usr/lib64/qt5/mkspecs/features/warn_on.prf \
		/usr/lib64/qt5/mkspecs/features/qt.prf \
		/usr/lib64/qt5/mkspecs/features/resources.prf \
		/usr/lib64/qt5/mkspecs/features/moc.prf \
		/usr/lib64/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib64/qt5/mkspecs/features/uic.prf \
		/usr/lib64/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt5/mkspecs/features/file_copies.prf \
		/usr/lib64/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib64/qt5/mkspecs/features/exceptions.prf \
		/usr/lib64/qt5/mkspecs/features/yacc.prf \
		/usr/lib64/qt5/mkspecs/features/lex.prf \
		maroloDAQ.pro \
		/usr/lib64/libQt5Widgets.prl \
		/usr/lib64/libQt5Gui.prl \
		/usr/lib64/libQt5SerialPort.prl \
		/usr/lib64/libQt5Core.prl
	$(QMAKE) -o Makefile maroloDAQ.pro
/usr/lib64/qt5/mkspecs/features/spec_pre.prf:
/usr/lib64/qt5/mkspecs/common/unix.conf:
/usr/lib64/qt5/mkspecs/common/linux.conf:
/usr/lib64/qt5/mkspecs/common/sanitize.conf:
/usr/lib64/qt5/mkspecs/common/gcc-base.conf:
/usr/lib64/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib64/qt5/mkspecs/common/g++-base.conf:
/usr/lib64/qt5/mkspecs/common/g++-unix.conf:
/usr/lib64/qt5/mkspecs/qconfig.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qml.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qml_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quick.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quick_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_serialport.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_serialport_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_svg.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_svg_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib64/qt5/mkspecs/features/qt_functions.prf:
/usr/lib64/qt5/mkspecs/features/qt_config.prf:
/usr/lib64/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib64/qt5/mkspecs/features/spec_post.prf:
/usr/lib64/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib64/qt5/mkspecs/features/default_pre.prf:
/usr/lib64/qt5/mkspecs/features/resolve_config.prf:
/usr/lib64/qt5/mkspecs/features/default_post.prf:
/usr/lib64/qt5/mkspecs/features/warn_on.prf:
/usr/lib64/qt5/mkspecs/features/qt.prf:
/usr/lib64/qt5/mkspecs/features/resources.prf:
/usr/lib64/qt5/mkspecs/features/moc.prf:
/usr/lib64/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib64/qt5/mkspecs/features/uic.prf:
/usr/lib64/qt5/mkspecs/features/unix/thread.prf:
/usr/lib64/qt5/mkspecs/features/file_copies.prf:
/usr/lib64/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib64/qt5/mkspecs/features/exceptions.prf:
/usr/lib64/qt5/mkspecs/features/yacc.prf:
/usr/lib64/qt5/mkspecs/features/lex.prf:
maroloDAQ.pro:
/usr/lib64/libQt5Widgets.prl:
/usr/lib64/libQt5Gui.prl:
/usr/lib64/libQt5SerialPort.prl:
/usr/lib64/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile maroloDAQ.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents maroloDAQ.h comserial.h $(DISTDIR)/
	$(COPY_FILE) --parents main.cpp maroloDAQ.cpp comserial.cpp $(DISTDIR)/
	$(COPY_FILE) --parents maroloDAQ.ui $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all: moc_maroloDAQ.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_maroloDAQ.cpp
moc_maroloDAQ.cpp: /usr/lib64/qt5/include/QtWidgets/QMainWindow \
		/usr/lib64/qt5/include/QtWidgets/qmainwindow.h \
		/usr/lib64/qt5/include/QtWidgets/qwidget.h \
		/usr/lib64/qt5/include/QtGui/qwindowdefs.h \
		/usr/lib64/qt5/include/QtCore/qglobal.h \
		/usr/lib64/qt5/include/QtCore/qconfig.h \
		/usr/lib64/qt5/include/QtCore/qfeatures.h \
		/usr/lib64/qt5/include/QtCore/qsystemdetection.h \
		/usr/lib64/qt5/include/QtCore/qprocessordetection.h \
		/usr/lib64/qt5/include/QtCore/qcompilerdetection.h \
		/usr/lib64/qt5/include/QtCore/qtypeinfo.h \
		/usr/lib64/qt5/include/QtCore/qtypetraits.h \
		/usr/lib64/qt5/include/QtCore/qisenum.h \
		/usr/lib64/qt5/include/QtCore/qsysinfo.h \
		/usr/lib64/qt5/include/QtCore/qlogging.h \
		/usr/lib64/qt5/include/QtCore/qflags.h \
		/usr/lib64/qt5/include/QtCore/qatomic.h \
		/usr/lib64/qt5/include/QtCore/qbasicatomic.h \
		/usr/lib64/qt5/include/QtCore/qatomic_bootstrap.h \
		/usr/lib64/qt5/include/QtCore/qgenericatomic.h \
		/usr/lib64/qt5/include/QtCore/qatomic_cxx11.h \
		/usr/lib64/qt5/include/QtCore/qatomic_gcc.h \
		/usr/lib64/qt5/include/QtCore/qatomic_msvc.h \
		/usr/lib64/qt5/include/QtCore/qatomic_armv7.h \
		/usr/lib64/qt5/include/QtCore/qatomic_armv6.h \
		/usr/lib64/qt5/include/QtCore/qatomic_armv5.h \
		/usr/lib64/qt5/include/QtCore/qatomic_ia64.h \
		/usr/lib64/qt5/include/QtCore/qatomic_x86.h \
		/usr/lib64/qt5/include/QtCore/qatomic_unix.h \
		/usr/lib64/qt5/include/QtCore/qglobalstatic.h \
		/usr/lib64/qt5/include/QtCore/qmutex.h \
		/usr/lib64/qt5/include/QtCore/qnumeric.h \
		/usr/lib64/qt5/include/QtCore/qversiontagging.h \
		/usr/lib64/qt5/include/QtCore/qobjectdefs.h \
		/usr/lib64/qt5/include/QtCore/qnamespace.h \
		/usr/lib64/qt5/include/QtCore/qobjectdefs_impl.h \
		/usr/lib64/qt5/include/QtGui/qwindowdefs_win.h \
		/usr/lib64/qt5/include/QtCore/qobject.h \
		/usr/lib64/qt5/include/QtCore/qstring.h \
		/usr/lib64/qt5/include/QtCore/qchar.h \
		/usr/lib64/qt5/include/QtCore/qbytearray.h \
		/usr/lib64/qt5/include/QtCore/qrefcount.h \
		/usr/lib64/qt5/include/QtCore/qarraydata.h \
		/usr/lib64/qt5/include/QtCore/qstringbuilder.h \
		/usr/lib64/qt5/include/QtCore/qlist.h \
		/usr/lib64/qt5/include/QtCore/qalgorithms.h \
		/usr/lib64/qt5/include/QtCore/qiterator.h \
		/usr/lib64/qt5/include/QtCore/qhashfunctions.h \
		/usr/lib64/qt5/include/QtCore/qpair.h \
		/usr/lib64/qt5/include/QtCore/qbytearraylist.h \
		/usr/lib64/qt5/include/QtCore/qstringlist.h \
		/usr/lib64/qt5/include/QtCore/qregexp.h \
		/usr/lib64/qt5/include/QtCore/qstringmatcher.h \
		/usr/lib64/qt5/include/QtCore/qcoreevent.h \
		/usr/lib64/qt5/include/QtCore/qscopedpointer.h \
		/usr/lib64/qt5/include/QtCore/qmetatype.h \
		/usr/lib64/qt5/include/QtCore/qvarlengtharray.h \
		/usr/lib64/qt5/include/QtCore/qcontainerfwd.h \
		/usr/lib64/qt5/include/QtCore/qobject_impl.h \
		/usr/lib64/qt5/include/QtCore/qmargins.h \
		/usr/lib64/qt5/include/QtGui/qpaintdevice.h \
		/usr/lib64/qt5/include/QtCore/qrect.h \
		/usr/lib64/qt5/include/QtCore/qsize.h \
		/usr/lib64/qt5/include/QtCore/qpoint.h \
		/usr/lib64/qt5/include/QtGui/qpalette.h \
		/usr/lib64/qt5/include/QtGui/qcolor.h \
		/usr/lib64/qt5/include/QtGui/qrgb.h \
		/usr/lib64/qt5/include/QtGui/qrgba64.h \
		/usr/lib64/qt5/include/QtGui/qbrush.h \
		/usr/lib64/qt5/include/QtCore/qvector.h \
		/usr/lib64/qt5/include/QtGui/qmatrix.h \
		/usr/lib64/qt5/include/QtGui/qpolygon.h \
		/usr/lib64/qt5/include/QtGui/qregion.h \
		/usr/lib64/qt5/include/QtCore/qdatastream.h \
		/usr/lib64/qt5/include/QtCore/qiodevice.h \
		/usr/lib64/qt5/include/QtCore/qline.h \
		/usr/lib64/qt5/include/QtGui/qtransform.h \
		/usr/lib64/qt5/include/QtGui/qpainterpath.h \
		/usr/lib64/qt5/include/QtGui/qimage.h \
		/usr/lib64/qt5/include/QtGui/qpixelformat.h \
		/usr/lib64/qt5/include/QtGui/qpixmap.h \
		/usr/lib64/qt5/include/QtCore/qsharedpointer.h \
		/usr/lib64/qt5/include/QtCore/qshareddata.h \
		/usr/lib64/qt5/include/QtCore/qhash.h \
		/usr/lib64/qt5/include/QtCore/qsharedpointer_impl.h \
		/usr/lib64/qt5/include/QtGui/qfont.h \
		/usr/lib64/qt5/include/QtGui/qfontmetrics.h \
		/usr/lib64/qt5/include/QtGui/qfontinfo.h \
		/usr/lib64/qt5/include/QtWidgets/qsizepolicy.h \
		/usr/lib64/qt5/include/QtGui/qcursor.h \
		/usr/lib64/qt5/include/QtGui/qkeysequence.h \
		/usr/lib64/qt5/include/QtGui/qevent.h \
		/usr/lib64/qt5/include/QtCore/qvariant.h \
		/usr/lib64/qt5/include/QtCore/qmap.h \
		/usr/lib64/qt5/include/QtCore/qdebug.h \
		/usr/lib64/qt5/include/QtCore/qtextstream.h \
		/usr/lib64/qt5/include/QtCore/qlocale.h \
		/usr/lib64/qt5/include/QtCore/qset.h \
		/usr/lib64/qt5/include/QtCore/qcontiguouscache.h \
		/usr/lib64/qt5/include/QtCore/qurl.h \
		/usr/lib64/qt5/include/QtCore/qurlquery.h \
		/usr/lib64/qt5/include/QtCore/qfile.h \
		/usr/lib64/qt5/include/QtCore/qfiledevice.h \
		/usr/lib64/qt5/include/QtGui/qvector2d.h \
		/usr/lib64/qt5/include/QtGui/qtouchdevice.h \
		/usr/lib64/qt5/include/QtWidgets/qtabwidget.h \
		/usr/lib64/qt5/include/QtGui/qicon.h \
		/usr/lib64/qt5/include/QtWidgets/QApplication \
		/usr/lib64/qt5/include/QtWidgets/qapplication.h \
		/usr/lib64/qt5/include/QtCore/qcoreapplication.h \
		/usr/lib64/qt5/include/QtCore/qeventloop.h \
		/usr/lib64/qt5/include/QtWidgets/qdesktopwidget.h \
		/usr/lib64/qt5/include/QtGui/qguiapplication.h \
		/usr/lib64/qt5/include/QtGui/qinputmethod.h \
		/usr/lib64/qt5/include/QtWidgets/QActionGroup \
		/usr/lib64/qt5/include/QtWidgets/qactiongroup.h \
		/usr/lib64/qt5/include/QtWidgets/qaction.h \
		comserial.h \
		/usr/lib64/qt5/include/QtCore/QDebug \
		/usr/lib64/qt5/include/QtSerialPort/QSerialPort \
		/usr/lib64/qt5/include/QtSerialPort/qserialport.h \
		/usr/lib64/qt5/include/QtSerialPort/qserialportglobal.h \
		/usr/lib64/qt5/include/QtSerialPort/QSerialPortInfo \
		/usr/lib64/qt5/include/QtSerialPort/qserialportinfo.h \
		maroloDAQ.h
	/usr/lib64/qt5/bin/moc $(DEFINES) -I/usr/lib64/qt5/mkspecs/linux-g++ -I/home/jemartins/Projects/maroloDAQ -I/usr/lib64/qt5/include -I/usr/lib64/qt5/include/QtWidgets -I/usr/lib64/qt5/include/QtGui -I/usr/lib64/qt5/include/QtSerialPort -I/usr/lib64/qt5/include/QtCore -I/usr/include/c++/5.4.0 -I/usr/include/c++/5.4.0/x86_64-mageia-linux-gnu -I/usr/include/c++/5.4.0/backward -I/usr/lib/gcc/x86_64-mageia-linux-gnu/5.4.0/include -I/usr/local/include -I/usr/include maroloDAQ.h -o moc_maroloDAQ.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_maroloDAQ.h
compiler_uic_clean:
	-$(DEL_FILE) ui_maroloDAQ.h
ui_maroloDAQ.h: maroloDAQ.ui
	/usr/lib64/qt5/bin/uic maroloDAQ.ui -o ui_maroloDAQ.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp maroloDAQ.h \
		/usr/lib64/qt5/include/QtWidgets/QMainWindow \
		/usr/lib64/qt5/include/QtWidgets/qmainwindow.h \
		/usr/lib64/qt5/include/QtWidgets/qwidget.h \
		/usr/lib64/qt5/include/QtGui/qwindowdefs.h \
		/usr/lib64/qt5/include/QtCore/qglobal.h \
		/usr/lib64/qt5/include/QtCore/qconfig.h \
		/usr/lib64/qt5/include/QtCore/qfeatures.h \
		/usr/lib64/qt5/include/QtCore/qsystemdetection.h \
		/usr/lib64/qt5/include/QtCore/qprocessordetection.h \
		/usr/lib64/qt5/include/QtCore/qcompilerdetection.h \
		/usr/lib64/qt5/include/QtCore/qtypeinfo.h \
		/usr/lib64/qt5/include/QtCore/qtypetraits.h \
		/usr/lib64/qt5/include/QtCore/qisenum.h \
		/usr/lib64/qt5/include/QtCore/qsysinfo.h \
		/usr/lib64/qt5/include/QtCore/qlogging.h \
		/usr/lib64/qt5/include/QtCore/qflags.h \
		/usr/lib64/qt5/include/QtCore/qatomic.h \
		/usr/lib64/qt5/include/QtCore/qbasicatomic.h \
		/usr/lib64/qt5/include/QtCore/qatomic_bootstrap.h \
		/usr/lib64/qt5/include/QtCore/qgenericatomic.h \
		/usr/lib64/qt5/include/QtCore/qatomic_cxx11.h \
		/usr/lib64/qt5/include/QtCore/qatomic_gcc.h \
		/usr/lib64/qt5/include/QtCore/qatomic_msvc.h \
		/usr/lib64/qt5/include/QtCore/qatomic_armv7.h \
		/usr/lib64/qt5/include/QtCore/qatomic_armv6.h \
		/usr/lib64/qt5/include/QtCore/qatomic_armv5.h \
		/usr/lib64/qt5/include/QtCore/qatomic_ia64.h \
		/usr/lib64/qt5/include/QtCore/qatomic_x86.h \
		/usr/lib64/qt5/include/QtCore/qatomic_unix.h \
		/usr/lib64/qt5/include/QtCore/qglobalstatic.h \
		/usr/lib64/qt5/include/QtCore/qmutex.h \
		/usr/lib64/qt5/include/QtCore/qnumeric.h \
		/usr/lib64/qt5/include/QtCore/qversiontagging.h \
		/usr/lib64/qt5/include/QtCore/qobjectdefs.h \
		/usr/lib64/qt5/include/QtCore/qnamespace.h \
		/usr/lib64/qt5/include/QtCore/qobjectdefs_impl.h \
		/usr/lib64/qt5/include/QtGui/qwindowdefs_win.h \
		/usr/lib64/qt5/include/QtCore/qobject.h \
		/usr/lib64/qt5/include/QtCore/qstring.h \
		/usr/lib64/qt5/include/QtCore/qchar.h \
		/usr/lib64/qt5/include/QtCore/qbytearray.h \
		/usr/lib64/qt5/include/QtCore/qrefcount.h \
		/usr/lib64/qt5/include/QtCore/qarraydata.h \
		/usr/lib64/qt5/include/QtCore/qstringbuilder.h \
		/usr/lib64/qt5/include/QtCore/qlist.h \
		/usr/lib64/qt5/include/QtCore/qalgorithms.h \
		/usr/lib64/qt5/include/QtCore/qiterator.h \
		/usr/lib64/qt5/include/QtCore/qhashfunctions.h \
		/usr/lib64/qt5/include/QtCore/qpair.h \
		/usr/lib64/qt5/include/QtCore/qbytearraylist.h \
		/usr/lib64/qt5/include/QtCore/qstringlist.h \
		/usr/lib64/qt5/include/QtCore/qregexp.h \
		/usr/lib64/qt5/include/QtCore/qstringmatcher.h \
		/usr/lib64/qt5/include/QtCore/qcoreevent.h \
		/usr/lib64/qt5/include/QtCore/qscopedpointer.h \
		/usr/lib64/qt5/include/QtCore/qmetatype.h \
		/usr/lib64/qt5/include/QtCore/qvarlengtharray.h \
		/usr/lib64/qt5/include/QtCore/qcontainerfwd.h \
		/usr/lib64/qt5/include/QtCore/qobject_impl.h \
		/usr/lib64/qt5/include/QtCore/qmargins.h \
		/usr/lib64/qt5/include/QtGui/qpaintdevice.h \
		/usr/lib64/qt5/include/QtCore/qrect.h \
		/usr/lib64/qt5/include/QtCore/qsize.h \
		/usr/lib64/qt5/include/QtCore/qpoint.h \
		/usr/lib64/qt5/include/QtGui/qpalette.h \
		/usr/lib64/qt5/include/QtGui/qcolor.h \
		/usr/lib64/qt5/include/QtGui/qrgb.h \
		/usr/lib64/qt5/include/QtGui/qrgba64.h \
		/usr/lib64/qt5/include/QtGui/qbrush.h \
		/usr/lib64/qt5/include/QtCore/qvector.h \
		/usr/lib64/qt5/include/QtGui/qmatrix.h \
		/usr/lib64/qt5/include/QtGui/qpolygon.h \
		/usr/lib64/qt5/include/QtGui/qregion.h \
		/usr/lib64/qt5/include/QtCore/qdatastream.h \
		/usr/lib64/qt5/include/QtCore/qiodevice.h \
		/usr/lib64/qt5/include/QtCore/qline.h \
		/usr/lib64/qt5/include/QtGui/qtransform.h \
		/usr/lib64/qt5/include/QtGui/qpainterpath.h \
		/usr/lib64/qt5/include/QtGui/qimage.h \
		/usr/lib64/qt5/include/QtGui/qpixelformat.h \
		/usr/lib64/qt5/include/QtGui/qpixmap.h \
		/usr/lib64/qt5/include/QtCore/qsharedpointer.h \
		/usr/lib64/qt5/include/QtCore/qshareddata.h \
		/usr/lib64/qt5/include/QtCore/qhash.h \
		/usr/lib64/qt5/include/QtCore/qsharedpointer_impl.h \
		/usr/lib64/qt5/include/QtGui/qfont.h \
		/usr/lib64/qt5/include/QtGui/qfontmetrics.h \
		/usr/lib64/qt5/include/QtGui/qfontinfo.h \
		/usr/lib64/qt5/include/QtWidgets/qsizepolicy.h \
		/usr/lib64/qt5/include/QtGui/qcursor.h \
		/usr/lib64/qt5/include/QtGui/qkeysequence.h \
		/usr/lib64/qt5/include/QtGui/qevent.h \
		/usr/lib64/qt5/include/QtCore/qvariant.h \
		/usr/lib64/qt5/include/QtCore/qmap.h \
		/usr/lib64/qt5/include/QtCore/qdebug.h \
		/usr/lib64/qt5/include/QtCore/qtextstream.h \
		/usr/lib64/qt5/include/QtCore/qlocale.h \
		/usr/lib64/qt5/include/QtCore/qset.h \
		/usr/lib64/qt5/include/QtCore/qcontiguouscache.h \
		/usr/lib64/qt5/include/QtCore/qurl.h \
		/usr/lib64/qt5/include/QtCore/qurlquery.h \
		/usr/lib64/qt5/include/QtCore/qfile.h \
		/usr/lib64/qt5/include/QtCore/qfiledevice.h \
		/usr/lib64/qt5/include/QtGui/qvector2d.h \
		/usr/lib64/qt5/include/QtGui/qtouchdevice.h \
		/usr/lib64/qt5/include/QtWidgets/qtabwidget.h \
		/usr/lib64/qt5/include/QtGui/qicon.h \
		/usr/lib64/qt5/include/QtWidgets/QApplication \
		/usr/lib64/qt5/include/QtWidgets/qapplication.h \
		/usr/lib64/qt5/include/QtCore/qcoreapplication.h \
		/usr/lib64/qt5/include/QtCore/qeventloop.h \
		/usr/lib64/qt5/include/QtWidgets/qdesktopwidget.h \
		/usr/lib64/qt5/include/QtGui/qguiapplication.h \
		/usr/lib64/qt5/include/QtGui/qinputmethod.h \
		/usr/lib64/qt5/include/QtWidgets/QActionGroup \
		/usr/lib64/qt5/include/QtWidgets/qactiongroup.h \
		/usr/lib64/qt5/include/QtWidgets/qaction.h \
		comserial.h \
		/usr/lib64/qt5/include/QtCore/QDebug \
		/usr/lib64/qt5/include/QtSerialPort/QSerialPort \
		/usr/lib64/qt5/include/QtSerialPort/qserialport.h \
		/usr/lib64/qt5/include/QtSerialPort/qserialportglobal.h \
		/usr/lib64/qt5/include/QtSerialPort/QSerialPortInfo \
		/usr/lib64/qt5/include/QtSerialPort/qserialportinfo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

maroloDAQ.o: maroloDAQ.cpp maroloDAQ.h \
		/usr/lib64/qt5/include/QtWidgets/QMainWindow \
		/usr/lib64/qt5/include/QtWidgets/qmainwindow.h \
		/usr/lib64/qt5/include/QtWidgets/qwidget.h \
		/usr/lib64/qt5/include/QtGui/qwindowdefs.h \
		/usr/lib64/qt5/include/QtCore/qglobal.h \
		/usr/lib64/qt5/include/QtCore/qconfig.h \
		/usr/lib64/qt5/include/QtCore/qfeatures.h \
		/usr/lib64/qt5/include/QtCore/qsystemdetection.h \
		/usr/lib64/qt5/include/QtCore/qprocessordetection.h \
		/usr/lib64/qt5/include/QtCore/qcompilerdetection.h \
		/usr/lib64/qt5/include/QtCore/qtypeinfo.h \
		/usr/lib64/qt5/include/QtCore/qtypetraits.h \
		/usr/lib64/qt5/include/QtCore/qisenum.h \
		/usr/lib64/qt5/include/QtCore/qsysinfo.h \
		/usr/lib64/qt5/include/QtCore/qlogging.h \
		/usr/lib64/qt5/include/QtCore/qflags.h \
		/usr/lib64/qt5/include/QtCore/qatomic.h \
		/usr/lib64/qt5/include/QtCore/qbasicatomic.h \
		/usr/lib64/qt5/include/QtCore/qatomic_bootstrap.h \
		/usr/lib64/qt5/include/QtCore/qgenericatomic.h \
		/usr/lib64/qt5/include/QtCore/qatomic_cxx11.h \
		/usr/lib64/qt5/include/QtCore/qatomic_gcc.h \
		/usr/lib64/qt5/include/QtCore/qatomic_msvc.h \
		/usr/lib64/qt5/include/QtCore/qatomic_armv7.h \
		/usr/lib64/qt5/include/QtCore/qatomic_armv6.h \
		/usr/lib64/qt5/include/QtCore/qatomic_armv5.h \
		/usr/lib64/qt5/include/QtCore/qatomic_ia64.h \
		/usr/lib64/qt5/include/QtCore/qatomic_x86.h \
		/usr/lib64/qt5/include/QtCore/qatomic_unix.h \
		/usr/lib64/qt5/include/QtCore/qglobalstatic.h \
		/usr/lib64/qt5/include/QtCore/qmutex.h \
		/usr/lib64/qt5/include/QtCore/qnumeric.h \
		/usr/lib64/qt5/include/QtCore/qversiontagging.h \
		/usr/lib64/qt5/include/QtCore/qobjectdefs.h \
		/usr/lib64/qt5/include/QtCore/qnamespace.h \
		/usr/lib64/qt5/include/QtCore/qobjectdefs_impl.h \
		/usr/lib64/qt5/include/QtGui/qwindowdefs_win.h \
		/usr/lib64/qt5/include/QtCore/qobject.h \
		/usr/lib64/qt5/include/QtCore/qstring.h \
		/usr/lib64/qt5/include/QtCore/qchar.h \
		/usr/lib64/qt5/include/QtCore/qbytearray.h \
		/usr/lib64/qt5/include/QtCore/qrefcount.h \
		/usr/lib64/qt5/include/QtCore/qarraydata.h \
		/usr/lib64/qt5/include/QtCore/qstringbuilder.h \
		/usr/lib64/qt5/include/QtCore/qlist.h \
		/usr/lib64/qt5/include/QtCore/qalgorithms.h \
		/usr/lib64/qt5/include/QtCore/qiterator.h \
		/usr/lib64/qt5/include/QtCore/qhashfunctions.h \
		/usr/lib64/qt5/include/QtCore/qpair.h \
		/usr/lib64/qt5/include/QtCore/qbytearraylist.h \
		/usr/lib64/qt5/include/QtCore/qstringlist.h \
		/usr/lib64/qt5/include/QtCore/qregexp.h \
		/usr/lib64/qt5/include/QtCore/qstringmatcher.h \
		/usr/lib64/qt5/include/QtCore/qcoreevent.h \
		/usr/lib64/qt5/include/QtCore/qscopedpointer.h \
		/usr/lib64/qt5/include/QtCore/qmetatype.h \
		/usr/lib64/qt5/include/QtCore/qvarlengtharray.h \
		/usr/lib64/qt5/include/QtCore/qcontainerfwd.h \
		/usr/lib64/qt5/include/QtCore/qobject_impl.h \
		/usr/lib64/qt5/include/QtCore/qmargins.h \
		/usr/lib64/qt5/include/QtGui/qpaintdevice.h \
		/usr/lib64/qt5/include/QtCore/qrect.h \
		/usr/lib64/qt5/include/QtCore/qsize.h \
		/usr/lib64/qt5/include/QtCore/qpoint.h \
		/usr/lib64/qt5/include/QtGui/qpalette.h \
		/usr/lib64/qt5/include/QtGui/qcolor.h \
		/usr/lib64/qt5/include/QtGui/qrgb.h \
		/usr/lib64/qt5/include/QtGui/qrgba64.h \
		/usr/lib64/qt5/include/QtGui/qbrush.h \
		/usr/lib64/qt5/include/QtCore/qvector.h \
		/usr/lib64/qt5/include/QtGui/qmatrix.h \
		/usr/lib64/qt5/include/QtGui/qpolygon.h \
		/usr/lib64/qt5/include/QtGui/qregion.h \
		/usr/lib64/qt5/include/QtCore/qdatastream.h \
		/usr/lib64/qt5/include/QtCore/qiodevice.h \
		/usr/lib64/qt5/include/QtCore/qline.h \
		/usr/lib64/qt5/include/QtGui/qtransform.h \
		/usr/lib64/qt5/include/QtGui/qpainterpath.h \
		/usr/lib64/qt5/include/QtGui/qimage.h \
		/usr/lib64/qt5/include/QtGui/qpixelformat.h \
		/usr/lib64/qt5/include/QtGui/qpixmap.h \
		/usr/lib64/qt5/include/QtCore/qsharedpointer.h \
		/usr/lib64/qt5/include/QtCore/qshareddata.h \
		/usr/lib64/qt5/include/QtCore/qhash.h \
		/usr/lib64/qt5/include/QtCore/qsharedpointer_impl.h \
		/usr/lib64/qt5/include/QtGui/qfont.h \
		/usr/lib64/qt5/include/QtGui/qfontmetrics.h \
		/usr/lib64/qt5/include/QtGui/qfontinfo.h \
		/usr/lib64/qt5/include/QtWidgets/qsizepolicy.h \
		/usr/lib64/qt5/include/QtGui/qcursor.h \
		/usr/lib64/qt5/include/QtGui/qkeysequence.h \
		/usr/lib64/qt5/include/QtGui/qevent.h \
		/usr/lib64/qt5/include/QtCore/qvariant.h \
		/usr/lib64/qt5/include/QtCore/qmap.h \
		/usr/lib64/qt5/include/QtCore/qdebug.h \
		/usr/lib64/qt5/include/QtCore/qtextstream.h \
		/usr/lib64/qt5/include/QtCore/qlocale.h \
		/usr/lib64/qt5/include/QtCore/qset.h \
		/usr/lib64/qt5/include/QtCore/qcontiguouscache.h \
		/usr/lib64/qt5/include/QtCore/qurl.h \
		/usr/lib64/qt5/include/QtCore/qurlquery.h \
		/usr/lib64/qt5/include/QtCore/qfile.h \
		/usr/lib64/qt5/include/QtCore/qfiledevice.h \
		/usr/lib64/qt5/include/QtGui/qvector2d.h \
		/usr/lib64/qt5/include/QtGui/qtouchdevice.h \
		/usr/lib64/qt5/include/QtWidgets/qtabwidget.h \
		/usr/lib64/qt5/include/QtGui/qicon.h \
		/usr/lib64/qt5/include/QtWidgets/QApplication \
		/usr/lib64/qt5/include/QtWidgets/qapplication.h \
		/usr/lib64/qt5/include/QtCore/qcoreapplication.h \
		/usr/lib64/qt5/include/QtCore/qeventloop.h \
		/usr/lib64/qt5/include/QtWidgets/qdesktopwidget.h \
		/usr/lib64/qt5/include/QtGui/qguiapplication.h \
		/usr/lib64/qt5/include/QtGui/qinputmethod.h \
		/usr/lib64/qt5/include/QtWidgets/QActionGroup \
		/usr/lib64/qt5/include/QtWidgets/qactiongroup.h \
		/usr/lib64/qt5/include/QtWidgets/qaction.h \
		comserial.h \
		/usr/lib64/qt5/include/QtCore/QDebug \
		/usr/lib64/qt5/include/QtSerialPort/QSerialPort \
		/usr/lib64/qt5/include/QtSerialPort/qserialport.h \
		/usr/lib64/qt5/include/QtSerialPort/qserialportglobal.h \
		/usr/lib64/qt5/include/QtSerialPort/QSerialPortInfo \
		/usr/lib64/qt5/include/QtSerialPort/qserialportinfo.h \
		ui_maroloDAQ.h \
		/usr/lib64/qt5/include/QtWidgets/QMessageBox \
		/usr/lib64/qt5/include/QtWidgets/qmessagebox.h \
		/usr/lib64/qt5/include/QtWidgets/qdialog.h \
		/usr/lib64/qt5/include/QtWidgets/QMenu \
		/usr/lib64/qt5/include/QtWidgets/qmenu.h \
		/usr/lib64/qt5/include/QtWidgets/QMenuBar \
		/usr/lib64/qt5/include/QtWidgets/qmenubar.h \
		/usr/lib64/qt5/include/QtWidgets/QStatusBar \
		/usr/lib64/qt5/include/QtWidgets/qstatusbar.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o maroloDAQ.o maroloDAQ.cpp

comserial.o: comserial.cpp comserial.h \
		/usr/lib64/qt5/include/QtCore/QDebug \
		/usr/lib64/qt5/include/QtCore/qdebug.h \
		/usr/lib64/qt5/include/QtCore/qalgorithms.h \
		/usr/lib64/qt5/include/QtCore/qglobal.h \
		/usr/lib64/qt5/include/QtCore/qconfig.h \
		/usr/lib64/qt5/include/QtCore/qfeatures.h \
		/usr/lib64/qt5/include/QtCore/qsystemdetection.h \
		/usr/lib64/qt5/include/QtCore/qprocessordetection.h \
		/usr/lib64/qt5/include/QtCore/qcompilerdetection.h \
		/usr/lib64/qt5/include/QtCore/qtypeinfo.h \
		/usr/lib64/qt5/include/QtCore/qtypetraits.h \
		/usr/lib64/qt5/include/QtCore/qisenum.h \
		/usr/lib64/qt5/include/QtCore/qsysinfo.h \
		/usr/lib64/qt5/include/QtCore/qlogging.h \
		/usr/lib64/qt5/include/QtCore/qflags.h \
		/usr/lib64/qt5/include/QtCore/qatomic.h \
		/usr/lib64/qt5/include/QtCore/qbasicatomic.h \
		/usr/lib64/qt5/include/QtCore/qatomic_bootstrap.h \
		/usr/lib64/qt5/include/QtCore/qgenericatomic.h \
		/usr/lib64/qt5/include/QtCore/qatomic_cxx11.h \
		/usr/lib64/qt5/include/QtCore/qatomic_gcc.h \
		/usr/lib64/qt5/include/QtCore/qatomic_msvc.h \
		/usr/lib64/qt5/include/QtCore/qatomic_armv7.h \
		/usr/lib64/qt5/include/QtCore/qatomic_armv6.h \
		/usr/lib64/qt5/include/QtCore/qatomic_armv5.h \
		/usr/lib64/qt5/include/QtCore/qatomic_ia64.h \
		/usr/lib64/qt5/include/QtCore/qatomic_x86.h \
		/usr/lib64/qt5/include/QtCore/qatomic_unix.h \
		/usr/lib64/qt5/include/QtCore/qglobalstatic.h \
		/usr/lib64/qt5/include/QtCore/qmutex.h \
		/usr/lib64/qt5/include/QtCore/qnumeric.h \
		/usr/lib64/qt5/include/QtCore/qversiontagging.h \
		/usr/lib64/qt5/include/QtCore/qhash.h \
		/usr/lib64/qt5/include/QtCore/qchar.h \
		/usr/lib64/qt5/include/QtCore/qiterator.h \
		/usr/lib64/qt5/include/QtCore/qlist.h \
		/usr/lib64/qt5/include/QtCore/qrefcount.h \
		/usr/lib64/qt5/include/QtCore/qarraydata.h \
		/usr/lib64/qt5/include/QtCore/qhashfunctions.h \
		/usr/lib64/qt5/include/QtCore/qpair.h \
		/usr/lib64/qt5/include/QtCore/qbytearraylist.h \
		/usr/lib64/qt5/include/QtCore/qbytearray.h \
		/usr/lib64/qt5/include/QtCore/qnamespace.h \
		/usr/lib64/qt5/include/QtCore/qstring.h \
		/usr/lib64/qt5/include/QtCore/qstringbuilder.h \
		/usr/lib64/qt5/include/QtCore/qstringlist.h \
		/usr/lib64/qt5/include/QtCore/qregexp.h \
		/usr/lib64/qt5/include/QtCore/qstringmatcher.h \
		/usr/lib64/qt5/include/QtCore/qmap.h \
		/usr/lib64/qt5/include/QtCore/qtextstream.h \
		/usr/lib64/qt5/include/QtCore/qiodevice.h \
		/usr/lib64/qt5/include/QtCore/qobject.h \
		/usr/lib64/qt5/include/QtCore/qobjectdefs.h \
		/usr/lib64/qt5/include/QtCore/qobjectdefs_impl.h \
		/usr/lib64/qt5/include/QtCore/qcoreevent.h \
		/usr/lib64/qt5/include/QtCore/qscopedpointer.h \
		/usr/lib64/qt5/include/QtCore/qmetatype.h \
		/usr/lib64/qt5/include/QtCore/qvarlengtharray.h \
		/usr/lib64/qt5/include/QtCore/qcontainerfwd.h \
		/usr/lib64/qt5/include/QtCore/qobject_impl.h \
		/usr/lib64/qt5/include/QtCore/qlocale.h \
		/usr/lib64/qt5/include/QtCore/qvariant.h \
		/usr/lib64/qt5/include/QtCore/qshareddata.h \
		/usr/lib64/qt5/include/QtCore/qvector.h \
		/usr/lib64/qt5/include/QtCore/qpoint.h \
		/usr/lib64/qt5/include/QtCore/qset.h \
		/usr/lib64/qt5/include/QtCore/qcontiguouscache.h \
		/usr/lib64/qt5/include/QtSerialPort/QSerialPort \
		/usr/lib64/qt5/include/QtSerialPort/qserialport.h \
		/usr/lib64/qt5/include/QtSerialPort/qserialportglobal.h \
		/usr/lib64/qt5/include/QtSerialPort/QSerialPortInfo \
		/usr/lib64/qt5/include/QtSerialPort/qserialportinfo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o comserial.o comserial.cpp

moc_maroloDAQ.o: moc_maroloDAQ.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_maroloDAQ.o moc_maroloDAQ.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

