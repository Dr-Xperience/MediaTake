#ifndef DATABASEOPERATIONS_H
#define DATABASEOPERATIONS_H

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <QtCore>
#include <QMessageBox>

#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <taglib/tpropertymap.h>

//#include <taglib/tbytevector.h>
//#include <taglib/mpegfile.h>

//#include <taglib/id3v2tag.h>
//#include <taglib/id3v2frame.h>
//#include <taglib/id3v2header.h>

//#include <taglib/id3v1tag.h>
//#include <taglib/apetag.h>

#include <mongo/client/dbclient.h>

using std::vector;
class DatabaseOperations : public QThread
{
    Q_OBJECT

public:

    void getSetting();
    virtual void getSource()=0;

protected:
    mongo::DBClientConnection mDBConnection;
    mongo::auto_ptr<mongo::DBClientCursor> mCursor;


    mongo::BSONObjBuilder *mBSONObjBuilder;
    mongo::BSONObj mBSONObj;

    TagLib::FileRef *mFile;
    TagLib::Tag *mTag;
    TagLib::AudioProperties *mAudioProp;
    //    TagLib::ID3v2::Tag mID3Tag;

    vector < vector < QString > > mFileProp;

    QMutex mMutex;

    explicit DatabaseOperations(QObject *parent = 0);
    virtual ~DatabaseOperations();
    virtual void removeFromDB(QString)=0;
    virtual void updateDB(QString,QFileInfo,QFileInfoList)=0;
    virtual void updateTreeView()=0;
    virtual void updateSource(QString)=0;

    virtual void initiator()=0;
    virtual void destroyer()=0;
    virtual void manager()=0;
    void setSetting();

signals:
    
    virtual void updateTreeWidgetLibraryDisplay(vector < vector < QString> >)=0;
    virtual void updatePath(QString)=0;

public slots:


};

#endif // DATABASEOPERATIONS_H
