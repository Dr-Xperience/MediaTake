/****************************************************************************
    Media Take : A Qt and GStreamer Based cross platform Media Player for PC
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <vector>
#include <QSlider>
#include <QTreeWidgetItem>
#include "selectfiledialog.h"
#include "qtgstreamerdriver.h"
#include "videosink.h"

#include "librarymanageraudio.h"
#include "librarymanagervideo.h"

using std::vector;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    LibraryManagerAudio *mDBAudio;
    LibraryManagerVideo *mDBVideo;

    enum treeWidgetSortStatesAudio
    {
        Folder,
        Artist,
        Album,
        Genre,
        Year
    };

    enum treeWidgetSortStatesVideo
    {
        FolderVideo
    };

    int mSortStateAudio=Folder;
    int mSortStateVideo=FolderVideo;
    QTreeWidgetItem *mNowPlaying = NULL;


    vector < vector < QString > > mTreeViewDataAudio;
    vector < vector < QString > > mTreeViewDataVideo;



    QtGStreamerDriver *mGstDriver;

    bool isPlaying=false;
    bool isParentAudio=true;

    QIcon mPlay ;
    QIcon mPause;
    QIcon mVolume;
    QIcon mVolumeMuted;

    QTime mPlayBacklength;
    QTime mPlayBackcurpos;
    QTimer mManagerTimer;
    unsigned long long mManagerTimerValue = 180000;
    int mManagerTimerCounter=1;
    long mTempTime;

    VideoSink *mVideoWidget;

    bool isVideoModeON=false;

    int mCurrentVolume;

public:

    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    int getSortStateAudio();
    void setSortStateAudio(treeWidgetSortStatesAudio vState);

    int getSortStateVideo();
    void setSortStateVideo(treeWidgetSortStatesVideo vState);

signals:
    void setPlayState();
    void setPauseState();
    void setStopState();
    void setVideoWidgetToAudio(bool);
    void goFullScreen();
    void setVolumeAtVideo(int);
    void setNowPlayingVideo(QString);

private slots:

    void getSelectedAudioPath(QString);
    void getSelectedVideoPath(QString);

    void pushButtonAddAudio_clicked();

    void pushButtonRemoveAudio_clicked();

    void pushButtonAddVideo_clicked();

    void pushButtonRemoveVideo_clicked();

    void updateTreeViewAudio(vector< vector<QString> >);

    void updateTreeViewVideo(vector< vector<QString> >);

    void onStateChanged();

    void onPositionChanged();

    void setPlayPause_clicked();
    void setNext_clicked();
    void setPrevious_clicked();


    void positionSliderMoved(int);
    void setVolume(int);

    void treeLibraryDisplay_doubleClicked();
    void treeLibraryDisplay_Addto_Queue();
    void treeLibraryDisplay_itemClicked(QTreeWidgetItem *, int);

    void treeWidgetQueue_onDoubleClicked(QTreeWidgetItem*);

    void treeCategoryChosser_doubleClicked();

    void toggleMute();
    void toFullScreen();
    void toVideoMode();


    void setVideoMode(bool);

    void shutdown();

    void pushButtonUpdate_clicked();

    void runManager();

    void toolButtonClearQueue_Clicked();

    void treeQueue_RemoveFromQueue();
private:
    Ui::MainWindow *ui;
    SelectFileDialog *mDialog;

    void sortTreeViewAudio();
    void sortTreeViewVideo();
    int setSliderOnClick(QSlider *, int);
//    bool caseInsensitiveLessThan(QTreeWidgetItem * s1 , QTreeWidgetItem * s2);
    //    void closeEvent(QCloseEvent *);
};

#endif // MAINWINDOW_H
