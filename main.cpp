#include "mainwindow.h"
#include <QApplication>
//#include <Qt5GStreamer/QGst/Init>
#include <QtGStreamer/QGst/Init>
#include <cstdlib>
int main(int argc, char *argv[])
{
//    std::system("chmod 777 ./mongolinux/*");
//    std::system("./mongolinux/mongod --config /etc/mongodb.conf")
//            std::system("mongod --config /etc/mongodb.conf");
    std::system("./mongolinux/mongod --config ./mongolinux/db/mongodb.conf --smallfiles");
    QApplication a(argc, argv);
    QGst::init(&argc, &argv);
    MainWindow w;
    w.show();

    return a.exec();
}
