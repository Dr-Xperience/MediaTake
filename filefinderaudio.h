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

#ifndef FILEFINDERAUDIO_H
#define FILEFINDERAUDIO_H

#include <QtCore>
#include <QtGui>
#include <queue>
using std::queue;

#include"databaseoperationsaudio.h"

class FileFinderAudio : public DatabaseOperationsAudio
{
    Q_OBJECT

    QDir *mDir;
    queue<QString> mFileQueue;

    queue<QString> mPathDestructor;

protected:
    explicit FileFinderAudio(QObject *parent = 0);

    queue<QString> mPath;
    void setPath(QString);
    void getDirTree();
    void initiator();
    virtual void destroyer()=0;
    virtual void manager()=0;
signals:
    
public slots:
    
};

#endif // FILEFINDERAUDIO_H
