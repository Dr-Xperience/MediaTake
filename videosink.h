#ifndef VIDEOSINK_H
#define VIDEOSINK_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QSlider>
#include <QMouseEvent>
#include "qtgstreamerdriver.h"

namespace Ui {
class VideoSink;
}

class VideoSink : public QMainWindow
{
    Q_OBJECT

    QtGStreamerDriver *mGstDriver;
    QIcon mPlay ;
    QIcon mPause;
    QIcon mVolume;
    QIcon mVolumeMuted;
    long long mTempTime;

    QTime mPlayBacklength,mPlayBackcurpos;

    bool isPlaying;
    int mCurrentVolume;

    QTimer mShowControlsTimer;

public:
    explicit VideoSink(QWidget *parent = 0);
    explicit VideoSink(QWidget *,QtGStreamerDriver *);
    bool eventFilter(QObject *obj, QEvent *event);
    ~VideoSink();

signals:
    void closeMain();
    void nextClicked();
    void prevClicked();
    void setPauseState();
    void setPlayState();
    void setVolumeAtMain(int);
    void setVideoMode(bool);

private slots:

    void onStateChanged();
    void onPositionChanged();
    void setPlayPause_clicked();
    void setNext_clicked();
    void setPrevious_clicked();
    void positionSliderMoved(int);
    void setVolume(int);
    void toggleMute();
    void toFullScreen();
    void toLibraryMode();
    void setVolumeSlider(int);
    void setNowPlaying(QString);
    void hideControls();


private:
    Ui::VideoSink *ui;
    void closeEvent(QCloseEvent *);
    int setSliderOnClick(QSlider * , int );
    void showControls();
protected:
    //    void mouseMoveEvent(QMouseEvent *event);
};

#endif // VIDEOSINK_H
