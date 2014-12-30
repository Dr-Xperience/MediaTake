#ifndef QTGSTREAMERDRIVER_H
#define QTGSTREAMERDRIVER_H

#include <QtCore>
#include <QtGStreamer/QGst/Pipeline>
#include <QtGStreamer/QGst/Ui/VideoWidget>
#include <QtGStreamer/QGlib/Connect>
#include <QtGStreamer/QGlib/Error>
#include <QtGStreamer/QGst/Pipeline>
#include <QtGStreamer/QGst/ElementFactory>
#include <QtGStreamer/QGst/Bus>
#include <QtGStreamer/QGst/Message>
#include <QtGStreamer/QGst/Query>
#include <QtGStreamer/QGst/ClockTime>
#include <QtGStreamer/QGst/Event>
#include <QtGStreamer/QGst/StreamVolume>

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
