/****************************************************************************
    Media Take : A Qt and GStreamer Based cross platform Media Player for PC
    Copyright (C) 2010 Marco Ballesio <gibrovacco@gmail.com>
    Copyright (C) 2011 Collabora Ltd. @author George Kiagiadakis <george.kiagiadakis@collabora.co.uk>
    Copyright (C) 2013  Anubhav Arun <dr.xperience@gmail.com>

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

#ifndef QTGSTREAMERDRIVER_H
#define QTGSTREAMERDRIVER_H

#include <QtCore>
#include <Qt5GStreamer/QGst/Pipeline>
#include <Qt5GStreamer/QGst/Ui/VideoWidget>
#include <Qt5GStreamer/QGlib/Connect>
#include <Qt5GStreamer/QGlib/Error>
#include <Qt5GStreamer/QGst/Pipeline>
#include <Qt5GStreamer/QGst/ElementFactory>
#include <Qt5GStreamer/QGst/Bus>
#include <Qt5GStreamer/QGst/Message>
#include <Qt5GStreamer/QGst/Query>
#include <Qt5GStreamer/QGst/ClockTime>
#include <Qt5GStreamer/QGst/Event>
#include <Qt5GStreamer/QGst/StreamVolume>

class QtGStreamerDriver: public QGst::Ui::VideoWidget
{
    Q_OBJECT

    void onBusMessage(QGst::MessagePtr);
    void handlePipelineStateChange(QGst::StateChangedMessagePtr);

    QGst::PipelinePtr mPipelinePtr;
    QTimer mPositionTimer;

public:
    QtGStreamerDriver(QWidget *parent = 0);
    ~QtGStreamerDriver();

    //Accessors
    int getVolume();
    QTime getPosition();
    QTime getDuration();
    QGst::State getState();

    //Mutators
    void setPath(QString);
    void setPosition(QTime );


public slots:
    void play();
    void pause();
    void stop();
    void setVolume(int volume);

signals:
    void positionChanged();
    void stateChanged();


};

#endif // QTGSTREAMERDRIVER_H
