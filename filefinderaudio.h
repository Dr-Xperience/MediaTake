#ifndef FILEFINDERAUDIO_H
#define FILEFINDERAUDIO_H

#include <QtCore>
#include <QtGui>
#include <queue>
using std::queue;

#include"databaseoperationsaudio.h"

class FileFinderAudio : public DatabaseOperationsAudio
{
    Q_OBJECT

    QDir *mDir;
    queue<QString> mFileQueue;

    queue<QString> mPathDestructor;

protected:
    explicit FileFinderAudio(QObject *parent = 0);

    queue<QString> mPath;
    void setPath(QString);
    void getDirTree();
    void initiator();
    virtual void destroyer()=0;
    virtual void manager()=0;
signals:
    
public slots:
    
};

#endif // FILEFINDERAUDIO_H
