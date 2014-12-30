#-------------------------------------------------
#
# Project created by QtCreator 2013-11-14T02:19:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

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
        -lboost_thread\
        -lboost_filesystem\
        -lboost_program_options\
        -lboost_system\


QMAKE_CXXFLAGS += -std=c++11 -pthread -Wno-deprecated #-fpermissive -pedantic
LIBS += -pthread

LIBS += -ltag\
#        -lQtGStreamer-0.10 -lQtGLib-2.0 -lQtCore -lQtGStreamerUi-0.10 -lQtGStreamerUtils-0.10\
#        -L/usr/local/Qt5.2.0/Qt5.2.0/gcc_64/lib\
        -L/usr/local/lib

INCLUDEPATH+= /usr/local/include
#INCLUDEPATH+= /usr/local/Qt5.0.1/5.0.1/gcc_64/include/

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

RESOURCES += \
    UiResources.qrc

