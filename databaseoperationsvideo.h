#ifndef DATABASEOPERATIONSVIDEO_H
#define DATABASEOPERATIONSVIDEO_H

#include "databaseoperations.h"

class DatabaseOperationsVideo : public DatabaseOperations
{
    Q_OBJECT

public:

    void getSource();
protected:
    explicit DatabaseOperationsVideo(QObject *parent = 0);

    void removeFromDB(QString);
    void updateDB(QString,QFileInfo,QFileInfoList);
    void updateTreeView();
    void updateSource(QString);
    void setSetting();
    virtual void initiator()=0;
    virtual void destroyer()=0;
    virtual void manager()=0;
signals:
    void updateTreeWidgetLibraryDisplay(vector < vector < QString> >);
    void updatePath(QString);

public slots:
    
};

#endif // DATABASEOPERATIONSVIDEO_H
