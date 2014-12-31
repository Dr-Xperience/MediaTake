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

#include "databaseoperations.h"


DatabaseOperations::DatabaseOperations(QObject *parent) :
    QThread(parent)
{

    try {
        mDBConnection.connect("localhost");
    } catch( const mongo::DBException &e )
    {
        QMessageBox::information(NULL,"Database Connection Error",QString(e.what()));

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



