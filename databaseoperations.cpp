#include "databaseoperations.h"


DatabaseOperations::DatabaseOperations(QObject *parent) :
    QThread(parent)
{

    try {
        mDBConnection.connect("localhost");
    } catch( const mongo::DBException &e )
    {
        QMessageBox::information(NULL,"Database Connection Error",QString(e.what()));
//        mBSONObjBuilder = new mongo::BSONObjBuilder;
//        mBSONObjBuilder->append("shutdown","1");
//        mBSONObj=mBSONObjBuilder->obj();
//        mongo::BSONObj vTemp;
//        try
//        {
//        mDBConnection.runCommand("admin",mBSONObj,vTemp);
//        }
//        catch( const mongo::DBException &e )
//        {
//            QMessageBox::information(NULL,"Database Connection Error",QString(e.what()));
//        }

    }
}
DatabaseOperations::~DatabaseOperations()
{
    mBSONObjBuilder = new mongo::BSONObjBuilder;
    mBSONObjBuilder->append("shutdown","1");
    mBSONObj=mBSONObjBuilder->obj();
    mongo::BSONObj vTemp;
    try
    {
    mDBConnection.runCommand("admin",mBSONObj,vTemp);
    }
    catch( const mongo::DBException &e )
    {

    }
}



