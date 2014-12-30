#ifndef FILEFINDERVIDEO_H
#define FILEFINDERVIDEO_H

#include <QtCore>
#include <QtGui>
#include <queue>
#include "databaseoperationsvideo.h"
using std::queue;

class FileFinderVideo : public DatabaseOperationsVideo
{
    Q_OBJECT

    QDir *mDir;
    queue<QString> mFileQueue;


protected:
    explicit FileFinderVideo(QObject *parent = 0);

    queue<QString> mPath;
    void setPath(QString);
    void getDirTree();
    void initiator();
    virtual void destroyer()=0;
    virtual void manager()=0;
signals:
    
public slots:
    
};

#endif // FILEFINDERVIDEO_H
