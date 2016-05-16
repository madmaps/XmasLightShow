#############################################################################
# Makefile for building: XmasTest
# Generated by qmake (3.0) (Qt 5.6.0)
# Project:  XmasTest.pro
# Template: app
# Command: /bin/qmake-qt5 -o Makefile XmasTest.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_MULTIMEDIA_LIB -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_SERIALPORT_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -march=i686 -mtune=generic -O2 -pipe -fstack-protector-strong -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -march=i686 -mtune=generic -O2 -pipe -fstack-protector-strong -std=gnu++0x -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -isystem /usr/include/qt -isystem /usr/include/qt/QtMultimedia -isystem /usr/include/qt/QtWidgets -isystem /usr/include/qt/QtGui -isystem /usr/include/qt/QtNetwork -isystem /usr/include/qt/QtSerialPort -isystem /usr/include/qt/QtCore -I. -I. -I/usr/lib/qt/mkspecs/linux-g++
QMAKE         = /bin/qmake-qt5
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
DISTNAME      = XmasTest1.0.0
DISTDIR = /home/matt/Desktop/Temp/XmasLightShow/.tmp/XmasTest1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-O1,--sort-common,--as-needed,-z,relro
LIBS          = $(SUBLIBS) -lQt5Multimedia -lQt5Widgets -lQt5Gui -lQt5Network -lQt5SerialPort -lQt5Core -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		track.cpp \
		binarytrack.cpp \
		visualdisplay.cpp \
		channeloptions.cpp \
		channelcolordisplay.cpp \
		module.cpp \
		moduledialog.cpp \
		serialportoptions.cpp \
		playlist.cpp moc_mainwindow.cpp \
		moc_track.cpp \
		moc_visualdisplay.cpp \
		moc_channeloptions.cpp \
		moc_channelcolordisplay.cpp \
		moc_moduledialog.cpp \
		moc_serialportoptions.cpp \
		moc_playlist.cpp
OBJECTS       = main.o \
		mainwindow.o \
		track.o \
		binarytrack.o \
		visualdisplay.o \
		channeloptions.o \
		channelcolordisplay.o \
		module.o \
		moduledialog.o \
		serialportoptions.o \
		playlist.o \
		moc_mainwindow.o \
		moc_track.o \
		moc_visualdisplay.o \
		moc_channeloptions.o \
		moc_channelcolordisplay.o \
		moc_moduledialog.o \
		moc_serialportoptions.o \
		moc_playlist.o
DIST          = /usr/lib/qt/mkspecs/features/spec_pre.prf \
		/usr/lib/qt/mkspecs/common/unix.conf \
		/usr/lib/qt/mkspecs/common/linux.conf \
		/usr/lib/qt/mkspecs/common/sanitize.conf \
		/usr/lib/qt/mkspecs/common/gcc-base.conf \
		/usr/lib/qt/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/qt/mkspecs/common/g++-base.conf \
		/usr/lib/qt/mkspecs/common/g++-unix.conf \
		/usr/lib/qt/mkspecs/qconfig.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_clucene_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designer.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designer_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_help.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_help_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_location.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_location_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimedia_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_positioning.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_positioning_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sensors.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sensors_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_serialport.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_serialport_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uiplugin.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uitools.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uitools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webchannel.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webchannel_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkit.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkit_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkitwidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		/usr/lib/qt/mkspecs/features/qt_functions.prf \
		/usr/lib/qt/mkspecs/features/qt_config.prf \
		/usr/lib/qt/mkspecs/linux-g++/qmake.conf \
		/usr/lib/qt/mkspecs/features/spec_post.prf \
		/usr/lib/qt/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt/mkspecs/features/default_pre.prf \
		/usr/lib/qt/mkspecs/features/resolve_config.prf \
		/usr/lib/qt/mkspecs/features/default_post.prf \
		/usr/lib/qt/mkspecs/features/warn_on.prf \
		/usr/lib/qt/mkspecs/features/qt.prf \
		/usr/lib/qt/mkspecs/features/resources.prf \
		/usr/lib/qt/mkspecs/features/moc.prf \
		/usr/lib/qt/mkspecs/features/unix/opengl.prf \
		/usr/lib/qt/mkspecs/features/uic.prf \
		/usr/lib/qt/mkspecs/features/unix/thread.prf \
		/usr/lib/qt/mkspecs/features/testcase_targets.prf \
		/usr/lib/qt/mkspecs/features/exceptions.prf \
		/usr/lib/qt/mkspecs/features/yacc.prf \
		/usr/lib/qt/mkspecs/features/lex.prf \
		XmasTest.pro mainwindow.h \
		track.h \
		binarytrack.h \
		visualdisplay.h \
		channeloptions.h \
		channelcolordisplay.h \
		module.h \
		moduledialog.h \
		serialportoptions.h \
		playlist.h main.cpp \
		mainwindow.cpp \
		track.cpp \
		binarytrack.cpp \
		visualdisplay.cpp \
		channeloptions.cpp \
		channelcolordisplay.cpp \
		module.cpp \
		moduledialog.cpp \
		serialportoptions.cpp \
		playlist.cpp
QMAKE_TARGET  = XmasTest
DESTDIR       = 
TARGET        = XmasTest


first: all
####### Build rules

$(TARGET): ui_mainwindow.h ui_moduledialog.h ui_serialportoptions.h ui_playlist.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: XmasTest.pro /usr/lib/qt/mkspecs/linux-g++/qmake.conf /usr/lib/qt/mkspecs/features/spec_pre.prf \
		/usr/lib/qt/mkspecs/common/unix.conf \
		/usr/lib/qt/mkspecs/common/linux.conf \
		/usr/lib/qt/mkspecs/common/sanitize.conf \
		/usr/lib/qt/mkspecs/common/gcc-base.conf \
		/usr/lib/qt/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/qt/mkspecs/common/g++-base.conf \
		/usr/lib/qt/mkspecs/common/g++-unix.conf \
		/usr/lib/qt/mkspecs/qconfig.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_clucene_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designer.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designer_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_help.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_help_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_location.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_location_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimedia_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_positioning.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_positioning_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sensors.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sensors_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_serialport.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_serialport_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uiplugin.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uitools.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uitools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webchannel.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webchannel_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkit.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkit_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkitwidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		/usr/lib/qt/mkspecs/features/qt_functions.prf \
		/usr/lib/qt/mkspecs/features/qt_config.prf \
		/usr/lib/qt/mkspecs/linux-g++/qmake.conf \
		/usr/lib/qt/mkspecs/features/spec_post.prf \
		/usr/lib/qt/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt/mkspecs/features/default_pre.prf \
		/usr/lib/qt/mkspecs/features/resolve_config.prf \
		/usr/lib/qt/mkspecs/features/default_post.prf \
		/usr/lib/qt/mkspecs/features/warn_on.prf \
		/usr/lib/qt/mkspecs/features/qt.prf \
		/usr/lib/qt/mkspecs/features/resources.prf \
		/usr/lib/qt/mkspecs/features/moc.prf \
		/usr/lib/qt/mkspecs/features/unix/opengl.prf \
		/usr/lib/qt/mkspecs/features/uic.prf \
		/usr/lib/qt/mkspecs/features/unix/thread.prf \
		/usr/lib/qt/mkspecs/features/testcase_targets.prf \
		/usr/lib/qt/mkspecs/features/exceptions.prf \
		/usr/lib/qt/mkspecs/features/yacc.prf \
		/usr/lib/qt/mkspecs/features/lex.prf \
		XmasTest.pro \
		/usr/lib/libQt5Multimedia.prl \
		/usr/lib/libQt5Widgets.prl \
		/usr/lib/libQt5Gui.prl \
		/usr/lib/libQt5Network.prl \
		/usr/lib/libQt5SerialPort.prl \
		/usr/lib/libQt5Core.prl
	$(QMAKE) -o Makefile XmasTest.pro
/usr/lib/qt/mkspecs/features/spec_pre.prf:
/usr/lib/qt/mkspecs/common/unix.conf:
/usr/lib/qt/mkspecs/common/linux.conf:
/usr/lib/qt/mkspecs/common/sanitize.conf:
/usr/lib/qt/mkspecs/common/gcc-base.conf:
/usr/lib/qt/mkspecs/common/gcc-base-unix.conf:
/usr/lib/qt/mkspecs/common/g++-base.conf:
/usr/lib/qt/mkspecs/common/g++-unix.conf:
/usr/lib/qt/mkspecs/qconfig.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_clucene_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_core.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_designer.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_designer_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_designercomponents_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_help.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_help_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_location.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_location_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_multimedia.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_multimedia_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_network.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_platformsupport_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_positioning.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_positioning_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qml.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qml_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qmldevtools_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qmltest.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qmltest_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quick.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quick_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quickparticles_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_sensors.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_sensors_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_serialport.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_serialport_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_uiplugin.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_uitools.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_uitools_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webchannel.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webchannel_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webkit.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webkit_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webkitwidgets.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webkitwidgets_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
/usr/lib/qt/mkspecs/features/qt_functions.prf:
/usr/lib/qt/mkspecs/features/qt_config.prf:
/usr/lib/qt/mkspecs/linux-g++/qmake.conf:
/usr/lib/qt/mkspecs/features/spec_post.prf:
/usr/lib/qt/mkspecs/features/exclusive_builds.prf:
/usr/lib/qt/mkspecs/features/default_pre.prf:
/usr/lib/qt/mkspecs/features/resolve_config.prf:
/usr/lib/qt/mkspecs/features/default_post.prf:
/usr/lib/qt/mkspecs/features/warn_on.prf:
/usr/lib/qt/mkspecs/features/qt.prf:
/usr/lib/qt/mkspecs/features/resources.prf:
/usr/lib/qt/mkspecs/features/moc.prf:
/usr/lib/qt/mkspecs/features/unix/opengl.prf:
/usr/lib/qt/mkspecs/features/uic.prf:
/usr/lib/qt/mkspecs/features/unix/thread.prf:
/usr/lib/qt/mkspecs/features/testcase_targets.prf:
/usr/lib/qt/mkspecs/features/exceptions.prf:
/usr/lib/qt/mkspecs/features/yacc.prf:
/usr/lib/qt/mkspecs/features/lex.prf:
XmasTest.pro:
/usr/lib/libQt5Multimedia.prl:
/usr/lib/libQt5Widgets.prl:
/usr/lib/libQt5Gui.prl:
/usr/lib/libQt5Network.prl:
/usr/lib/libQt5SerialPort.prl:
/usr/lib/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile XmasTest.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents mainwindow.h track.h binarytrack.h visualdisplay.h channeloptions.h channelcolordisplay.h module.h moduledialog.h serialportoptions.h playlist.h $(DISTDIR)/
	$(COPY_FILE) --parents main.cpp mainwindow.cpp track.cpp binarytrack.cpp visualdisplay.cpp channeloptions.cpp channelcolordisplay.cpp module.cpp moduledialog.cpp serialportoptions.cpp playlist.cpp $(DISTDIR)/
	$(COPY_FILE) --parents mainwindow.ui moduledialog.ui serialportoptions.ui playlist.ui $(DISTDIR)/


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

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all: moc_mainwindow.cpp moc_track.cpp moc_visualdisplay.cpp moc_channeloptions.cpp moc_channelcolordisplay.cpp moc_moduledialog.cpp moc_serialportoptions.cpp moc_playlist.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_track.cpp moc_visualdisplay.cpp moc_channeloptions.cpp moc_channelcolordisplay.cpp moc_moduledialog.cpp moc_serialportoptions.cpp moc_playlist.cpp
moc_mainwindow.cpp: channeloptions.h \
		channelcolordisplay.h \
		binarytrack.h \
		moduledialog.h \
		module.h \
		serialportoptions.h \
		playlist.h \
		mainwindow.h
	/usr/lib/qt/bin/moc $(DEFINES) -I/usr/lib/qt/mkspecs/linux-g++ -I/home/matt/Desktop/Temp/XmasLightShow -I/usr/include/qt -I/usr/include/qt/QtMultimedia -I/usr/include/qt/QtWidgets -I/usr/include/qt/QtGui -I/usr/include/qt/QtNetwork -I/usr/include/qt/QtSerialPort -I/usr/include/qt/QtCore -I/usr/include/c++/6.1.1 -I/usr/include/c++/6.1.1/i686-pc-linux-gnu -I/usr/include/c++/6.1.1/backward -I/usr/lib/gcc/i686-pc-linux-gnu/6.1.1/include -I/usr/local/include -I/usr/lib/gcc/i686-pc-linux-gnu/6.1.1/include-fixed -I/usr/include mainwindow.h -o moc_mainwindow.cpp

moc_track.cpp: binarytrack.h \
		track.h
	/usr/lib/qt/bin/moc $(DEFINES) -I/usr/lib/qt/mkspecs/linux-g++ -I/home/matt/Desktop/Temp/XmasLightShow -I/usr/include/qt -I/usr/include/qt/QtMultimedia -I/usr/include/qt/QtWidgets -I/usr/include/qt/QtGui -I/usr/include/qt/QtNetwork -I/usr/include/qt/QtSerialPort -I/usr/include/qt/QtCore -I/usr/include/c++/6.1.1 -I/usr/include/c++/6.1.1/i686-pc-linux-gnu -I/usr/include/c++/6.1.1/backward -I/usr/lib/gcc/i686-pc-linux-gnu/6.1.1/include -I/usr/local/include -I/usr/lib/gcc/i686-pc-linux-gnu/6.1.1/include-fixed -I/usr/include track.h -o moc_track.cpp

moc_visualdisplay.cpp: binarytrack.h \
		visualdisplay.h
	/usr/lib/qt/bin/moc $(DEFINES) -I/usr/lib/qt/mkspecs/linux-g++ -I/home/matt/Desktop/Temp/XmasLightShow -I/usr/include/qt -I/usr/include/qt/QtMultimedia -I/usr/include/qt/QtWidgets -I/usr/include/qt/QtGui -I/usr/include/qt/QtNetwork -I/usr/include/qt/QtSerialPort -I/usr/include/qt/QtCore -I/usr/include/c++/6.1.1 -I/usr/include/c++/6.1.1/i686-pc-linux-gnu -I/usr/include/c++/6.1.1/backward -I/usr/lib/gcc/i686-pc-linux-gnu/6.1.1/include -I/usr/local/include -I/usr/lib/gcc/i686-pc-linux-gnu/6.1.1/include-fixed -I/usr/include visualdisplay.h -o moc_visualdisplay.cpp

moc_channeloptions.cpp: channelcolordisplay.h \
		channeloptions.h
	/usr/lib/qt/bin/moc $(DEFINES) -I/usr/lib/qt/mkspecs/linux-g++ -I/home/matt/Desktop/Temp/XmasLightShow -I/usr/include/qt -I/usr/include/qt/QtMultimedia -I/usr/include/qt/QtWidgets -I/usr/include/qt/QtGui -I/usr/include/qt/QtNetwork -I/usr/include/qt/QtSerialPort -I/usr/include/qt/QtCore -I/usr/include/c++/6.1.1 -I/usr/include/c++/6.1.1/i686-pc-linux-gnu -I/usr/include/c++/6.1.1/backward -I/usr/lib/gcc/i686-pc-linux-gnu/6.1.1/include -I/usr/local/include -I/usr/lib/gcc/i686-pc-linux-gnu/6.1.1/include-fixed -I/usr/include channeloptions.h -o moc_channeloptions.cpp

moc_channelcolordisplay.cpp: channelcolordisplay.h
	/usr/lib/qt/bin/moc $(DEFINES) -I/usr/lib/qt/mkspecs/linux-g++ -I/home/matt/Desktop/Temp/XmasLightShow -I/usr/include/qt -I/usr/include/qt/QtMultimedia -I/usr/include/qt/QtWidgets -I/usr/include/qt/QtGui -I/usr/include/qt/QtNetwork -I/usr/include/qt/QtSerialPort -I/usr/include/qt/QtCore -I/usr/include/c++/6.1.1 -I/usr/include/c++/6.1.1/i686-pc-linux-gnu -I/usr/include/c++/6.1.1/backward -I/usr/lib/gcc/i686-pc-linux-gnu/6.1.1/include -I/usr/local/include -I/usr/lib/gcc/i686-pc-linux-gnu/6.1.1/include-fixed -I/usr/include channelcolordisplay.h -o moc_channelcolordisplay.cpp

moc_moduledialog.cpp: module.h \
		binarytrack.h \
		moduledialog.h
	/usr/lib/qt/bin/moc $(DEFINES) -I/usr/lib/qt/mkspecs/linux-g++ -I/home/matt/Desktop/Temp/XmasLightShow -I/usr/include/qt -I/usr/include/qt/QtMultimedia -I/usr/include/qt/QtWidgets -I/usr/include/qt/QtGui -I/usr/include/qt/QtNetwork -I/usr/include/qt/QtSerialPort -I/usr/include/qt/QtCore -I/usr/include/c++/6.1.1 -I/usr/include/c++/6.1.1/i686-pc-linux-gnu -I/usr/include/c++/6.1.1/backward -I/usr/lib/gcc/i686-pc-linux-gnu/6.1.1/include -I/usr/local/include -I/usr/lib/gcc/i686-pc-linux-gnu/6.1.1/include-fixed -I/usr/include moduledialog.h -o moc_moduledialog.cpp

moc_serialportoptions.cpp: serialportoptions.h
	/usr/lib/qt/bin/moc $(DEFINES) -I/usr/lib/qt/mkspecs/linux-g++ -I/home/matt/Desktop/Temp/XmasLightShow -I/usr/include/qt -I/usr/include/qt/QtMultimedia -I/usr/include/qt/QtWidgets -I/usr/include/qt/QtGui -I/usr/include/qt/QtNetwork -I/usr/include/qt/QtSerialPort -I/usr/include/qt/QtCore -I/usr/include/c++/6.1.1 -I/usr/include/c++/6.1.1/i686-pc-linux-gnu -I/usr/include/c++/6.1.1/backward -I/usr/lib/gcc/i686-pc-linux-gnu/6.1.1/include -I/usr/local/include -I/usr/lib/gcc/i686-pc-linux-gnu/6.1.1/include-fixed -I/usr/include serialportoptions.h -o moc_serialportoptions.cpp

moc_playlist.cpp: playlist.h
	/usr/lib/qt/bin/moc $(DEFINES) -I/usr/lib/qt/mkspecs/linux-g++ -I/home/matt/Desktop/Temp/XmasLightShow -I/usr/include/qt -I/usr/include/qt/QtMultimedia -I/usr/include/qt/QtWidgets -I/usr/include/qt/QtGui -I/usr/include/qt/QtNetwork -I/usr/include/qt/QtSerialPort -I/usr/include/qt/QtCore -I/usr/include/c++/6.1.1 -I/usr/include/c++/6.1.1/i686-pc-linux-gnu -I/usr/include/c++/6.1.1/backward -I/usr/lib/gcc/i686-pc-linux-gnu/6.1.1/include -I/usr/local/include -I/usr/lib/gcc/i686-pc-linux-gnu/6.1.1/include-fixed -I/usr/include playlist.h -o moc_playlist.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_moduledialog.h ui_serialportoptions.h ui_playlist.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_moduledialog.h ui_serialportoptions.h ui_playlist.h
ui_mainwindow.h: mainwindow.ui \
		track.h \
		visualdisplay.h \
		binarytrack.h \
		binarytrack.h
	/usr/lib/qt/bin/uic mainwindow.ui -o ui_mainwindow.h

ui_moduledialog.h: moduledialog.ui
	/usr/lib/qt/bin/uic moduledialog.ui -o ui_moduledialog.h

ui_serialportoptions.h: serialportoptions.ui
	/usr/lib/qt/bin/uic serialportoptions.ui -o ui_serialportoptions.h

ui_playlist.h: playlist.ui
	/usr/lib/qt/bin/uic playlist.ui -o ui_playlist.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		channeloptions.h \
		channelcolordisplay.h \
		binarytrack.h \
		moduledialog.h \
		module.h \
		serialportoptions.h \
		playlist.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		channeloptions.h \
		channelcolordisplay.h \
		binarytrack.h \
		moduledialog.h \
		module.h \
		serialportoptions.h \
		playlist.h \
		ui_mainwindow.h \
		track.h \
		visualdisplay.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

track.o: track.cpp track.h \
		binarytrack.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o track.o track.cpp

binarytrack.o: binarytrack.cpp binarytrack.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o binarytrack.o binarytrack.cpp

visualdisplay.o: visualdisplay.cpp visualdisplay.h \
		binarytrack.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o visualdisplay.o visualdisplay.cpp

channeloptions.o: channeloptions.cpp channeloptions.h \
		channelcolordisplay.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o channeloptions.o channeloptions.cpp

channelcolordisplay.o: channelcolordisplay.cpp channelcolordisplay.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o channelcolordisplay.o channelcolordisplay.cpp

module.o: module.cpp module.h \
		binarytrack.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o module.o module.cpp

moduledialog.o: moduledialog.cpp moduledialog.h \
		module.h \
		binarytrack.h \
		ui_moduledialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moduledialog.o moduledialog.cpp

serialportoptions.o: serialportoptions.cpp serialportoptions.h \
		ui_serialportoptions.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o serialportoptions.o serialportoptions.cpp

playlist.o: playlist.cpp playlist.h \
		ui_playlist.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o playlist.o playlist.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_track.o: moc_track.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_track.o moc_track.cpp

moc_visualdisplay.o: moc_visualdisplay.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_visualdisplay.o moc_visualdisplay.cpp

moc_channeloptions.o: moc_channeloptions.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_channeloptions.o moc_channeloptions.cpp

moc_channelcolordisplay.o: moc_channelcolordisplay.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_channelcolordisplay.o moc_channelcolordisplay.cpp

moc_moduledialog.o: moc_moduledialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_moduledialog.o moc_moduledialog.cpp

moc_serialportoptions.o: moc_serialportoptions.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_serialportoptions.o moc_serialportoptions.cpp

moc_playlist.o: moc_playlist.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_playlist.o moc_playlist.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

