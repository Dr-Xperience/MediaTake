#ifndef LIBRARYMANAGERAUDIO_H
#define LIBRARYMANAGERAUDIO_H

#include <QtCore>
#include <queue>

#include"filefinderaudio.h"

using std::queue;

class LibraryManagerAudio : public FileFinderAudio
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
    explicit LibraryManagerAudio(QObject *parent = 0);    

    void setInitiatorPath(QString);
    void setDestroyerPath(QString);
    void setManagerOnline();

signals:
    
public slots:
    
};

#endif // LIBRARYMANAGERAUDIO_H
