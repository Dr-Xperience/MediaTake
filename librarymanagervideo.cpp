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

#include "librarymanagervideo.h"

LibraryManagerVideo::LibraryManagerVideo(QObject *parent) :
    FileFinderVideo(parent)
{
}

void LibraryManagerVideo::setInitiatorPath(QString vPath)
{
    FileFinderVideo::setPath(vPath);
    isInitiatorOnline.push(true);
}

void LibraryManagerVideo::setDestroyerPath(QString vPath)
{
    mPathDestroyer.push(vPath);
    isDestroyerOnline.push(true);
}

void LibraryManagerVideo::run()
{
    if(isInitiatorOnline.empty()==false && isInitiatorOnline.front()==true)
    {
        isInitiatorOnline.pop();
        FileFinderVideo::initiator();
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

void LibraryManagerVideo::destroyer()
{
    removeFromDB(mPathDestroyer.front());
    mPathDestroyer.pop();
    updateTreeView();
}

void LibraryManagerVideo::setManagerOnline()
{
    isManagerOnline.push(true);
}

void LibraryManagerVideo::manager()
{
    mCursor = mDBConnection.query("MediaTake.FileListVideo", mongo::BSONObj());

    while(mCursor->more())
    {
        mBSONObj = mCursor->next();

        mFile = new QFile(QString::fromStdString(mBSONObj.getStringField("FilePath")));

        if(mFile->exists()==false)
        {
            mBSONObjBuilder = new mongo::BSONObjBuilder;
            mBSONObjBuilder->append("FilePath",mBSONObj.getStringField("FilePath"));
//            mBSONObj = mBSONObjBuilder->obj();
            mDBConnection.remove("MediaTake.FileListVideo",mongo::Query(mongo::BSONObj()=mBSONObjBuilder->obj()));
        }
    }
    mDBConnection.killCursor(mCursor->getCursorId());

    mCursor=mDBConnection.query("MediaTake.SourceVideo",mongo::Query());

    while(mCursor->more())
    {
        mBSONObj = mCursor->next();
        FileFinderVideo::setPath(mBSONObj.getStringField("SourcePath"));
        getDirTree();
        this->updateTreeView();
        mPath.pop();
    }
    mDBConnection.killCursor(mCursor->getCursorId());
}
