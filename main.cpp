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

#include "mainwindow.h"
#include <QApplication>
#include <Qt5GStreamer/QGst/Init>
//#include <QtGStreamer/QGst/Init>
#include <cstdlib>
int main(int argc, char *argv[])
{
    std::system("mongod --config /etc/mongodb.conf");
    QApplication a(argc, argv);
    QGst::init(&argc, &argv);
    MainWindow w;
    w.show();

    return a.exec();
}
