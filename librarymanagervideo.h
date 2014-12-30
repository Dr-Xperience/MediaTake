#ifndef LIBRARYMANAGERVIDEO_H
#define LIBRARYMANAGERVIDEO_H
#include <QtCore>
#include <queue>

#include "filefindervideo.h"

using std::queue;

class LibraryManagerVideo : public FileFinderVideo
{
    Q_OBJECT
    queue<bool> isInitiatorOnline;
    queue<bool> isDestroyerOnline;
    queue<bool> isManagerOnline;
    queue<QString> mPathDestroyer;
    void run();
    QFile *mFile;

protected:

    void destroyer();
    void manager();

public:
    explicit LibraryManagerVideo(QObject *parent = 0);
    
    void setInitiatorPath(QString);
    void setDestroyerPath(QString);
    void setManagerOnline();

signals:
    
public slots:
    
};

#endif // LIBRARYMANAGERVIDEO_H
