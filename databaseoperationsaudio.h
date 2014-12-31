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
