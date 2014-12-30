/****************************************************************************
    Media Take : A Qt and GStreamer Based cross platform Media Player for PC
    Copyright (C) 2013  Anubhav Arun

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*****************************************************************************/

#-------------------------------------------------
#
# Project created by QtCreator 2013-11-14T02:19:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MediaTake
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    selectfiledialog.cpp \
    databaseoperations.cpp \
    qtgstreamerdriver.cpp \
    videosink.cpp \
    databaseoperationsaudio.cpp \
    databaseoperationsvideo.cpp \
    filefinderaudio.cpp \
    filefindervideo.cpp \
    librarymanageraudio.cpp \
    librarymanagervideo.cpp

HEADERS  += mainwindow.h \
    selectfiledialog.h \
    databaseoperations.h \
    qtgstreamerdriver.h \
    videosink.h \
    databaseoperationsaudio.h \
    databaseoperationsvideo.h \
    filefinderaudio.h \
    filefindervideo.h \
    librarymanageraudio.h \
    librarymanagervideo.h

FORMS    += mainwindow.ui \
    selectfiledialog.ui \
    videosink.ui


unix{
LIBS += -lmongoclient\
        -lboost_thread-mt\
        -lboost_filesystem\
        -lboost_program_options\
        -lboost_system\


QMAKE_CXXFLAGS += -std=c++11 -pthread -Wno-deprecated #-fpermissive -pedantic
LIBS += -pthread

LIBS += -ltag\
#        -lQt5GStreamer-0.10 -lQt5GLib-2.0 -lQt5Core -lQt5GStreamerUi-0.10 -lQt5GStreamerUtils-0.10\
#        -L/usr/local/Qt5.0.1/5.0.1/gcc_64/lib\
        -L/usr/local/lib

INCLUDEPATH+= /usr/local/include

#CONFIG += link_pkgconfig
#PKGCONFIG += gstreamer-1.0

#CONFIG += link_pkgconfig
#PKGCONFIG += \
#Qt5GLib-2.0\  #- the libraries needed to use QtGLib
#Qt5GStreamer-0.10\ #- the libraries needed to use QtGStreamer
#Qt5GStreamerUi-0.10\   #- the libraries needed to use QtGStreamerUi
#Qt5GStreamerUtils-0.10\  #-the libraries needed to use QtGStreamerUtils

CONFIG += link_pkgconfig
PKGCONFIG += \
QtGLib-2.0\  #- the libraries needed to use QtGLib
QtGStreamer-0.10\ #- the libraries needed to use QtGStreamer
QtGStreamerUi-0.10\   #- the libraries needed to use QtGStreamerUi
QtGStreamerUtils-0.10\  #-the libraries needed to use QtGStreamerUtils

}

win32{
INCLUDEPATH += boost_1_55_0/
                C:\gstreamer-sdk\0.10\x86\include/

LIBS += #-lmongoclient\
        #-lboost_thread-mt\
        #-lboost_filesystem\
        #-lboost_program_options\
        #-lboost_system\
        /LIBPATH:boost_1_55_0\stage\lib;C:\gstreamer-sdk\0.10\x86\lib

#QMAKE_CXXFLAGS += -std=c++11 -pthread -Wno-deprecated #-fpermissive -pedantic
CONFIG += c++11
}

RESOURCES += \
    UiResources.qrc

