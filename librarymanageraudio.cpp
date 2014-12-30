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

#include "librarymanageraudio.h"

LibraryManagerAudio::LibraryManagerAudio(QObject *parent) :
    FileFinderAudio(parent)
{
}

void LibraryManagerAudio::setInitiatorPath(QString vPath)
{
    FileFinderAudio::setPath(vPath);
    isInitiatorOnline.push(true);
}

void LibraryManagerAudio::setDestroyerPath(QString vPath)
{
    mPathDestroyer.push(vPath);
    isDestroyerOnline.push(true);
}

void LibraryManagerAudio::run()
{
    if(isInitiatorOnline.empty()==false && isInitiatorOnline.front()==true)
    {
        isInitiatorOnline.pop();
        FileFinderAudio::initiator();
    }
    else if(isDestroyerOnline.empty()==false && isDestroyerOnline.front()==true)
    {
        isDestroyerOnline.pop();
        destroyer();
    }
    else if(isManagerOnline.empty()==false && isManagerOnline.front()==true)
    {
        isManagerOnline.pop();
        manager();
    }
}

void LibraryManagerAudio::destroyer()
{
    removeFromDB(mPathDestroyer.front());
    mPathDestroyer.pop();
    updateTreeView();
}

void LibraryManagerAudio::setManagerOnline()
{
    isManagerOnline.push(true);
}

void LibraryManagerAudio::manager()
{
    mCursor = mDBConnection.query("MediaTake.FileListAudio", mongo::BSONObj());

    while(mCursor->more())
    {
        mBSONObj = mCursor->next();

        mFile = new QFile(QString::fromStdString(mBSONObj.getStringField("FilePath")));

        if(mFile->exists()==false)
        {
            mBSONObjBuilder = new mongo::BSONObjBuilder;
            mBSONObjBuilder->append("FilePath",mBSONObj.getStringField("FilePath"));
//            mBSONObj = mBSONObjBuilder->obj();
            mDBConnection.remove("MediaTake.FileListAudio",mongo::Query(mongo::BSONObj()=mBSONObjBuilder->obj()));
        }
    }
    mDBConnection.killCursor(mCursor->getCursorId());

    mCursor=mDBConnection.query("MediaTake.SourceAudio",mongo::Query());

    while(mCursor->more())
    {
        mBSONObj = mCursor->next();
        FileFinderAudio::setPath(mBSONObj.getStringField("SourcePath"));
        getDirTree();
        this->updateTreeView();
        mPath.pop();
    }
    mDBConnection.killCursor(mCursor->getCursorId());
}
