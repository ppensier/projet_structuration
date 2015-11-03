#include "mainwindow.h"
#include <QApplication>
#include <QtOpenGL>
#include<iostream>
#include <fstream>
#include <sstream>
using namespace std;

//#include <QOpenGLWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
