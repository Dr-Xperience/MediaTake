#ifndef DATABASEOPERATIONSAUDIO_H
#define DATABASEOPERATIONSAUDIO_H

#include "databaseoperations.h"
class DatabaseOperationsAudio : public DatabaseOperations
{
    Q_OBJECT
public:

    void getSource();
protected:
    explicit DatabaseOperationsAudio(QObject *parent = 0);

    void removeFromDB(QString);
    void updateDB(QString,QFileInfo,QFileInfoList);
    void updateTreeView();
    void updateSource(QString);
    virtual void initiator()=0;
    virtual void destroyer()=0;
    virtual void manager()=0;
    
signals:
    void updateTreeWidgetLibraryDisplay(vector < vector < QString> >);
    void updatePath(QString);

    
public slots:
    
};

#endif // DATABASEOPERATIONSAUDIO_H
