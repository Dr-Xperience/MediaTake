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
