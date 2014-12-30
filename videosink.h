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
