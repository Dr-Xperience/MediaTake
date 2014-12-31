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

#ifndef DATABASEOPERATIONS_H
#define DATABASEOPERATIONS_H

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <QtCore>
#include <QMessageBox>

//#include <taglib/tag.h>
//#include <taglib/fileref.h>
//#include <taglib/tpropertymap.h>

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
//    TagLib::Tag *mTag;
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
