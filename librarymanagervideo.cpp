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
