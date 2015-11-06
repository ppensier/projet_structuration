#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include <QFileDialog>
#include <QString>
#include <QCheckBox>
#include<QVBoxLayout>
#include <fstream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widgetZoneVisu->leMnt=new Mnt();
    ui->widgetZoneVisu->leMnt->loadMnt("//home//gtsi//Téléchargements//Ecrin.xyz");
    ui->widgetZoneVisu->leGpx=new gpx();
    ui->widgetZoneVisu->leMnt->BuildTriangles();

    ui->widgetZoneVisu->leGpx->troisLesPlusProches(*ui->widgetZoneVisu->leMnt, ui->widgetZoneVisu->leGpx->ptsGpx[0]);
}

void MainWindow::on_Action_ouvrirMNT_triggered()
{

/*
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open MNT"), "/home/jana", tr("All files  (*.xyz)"));

    std::cout<<fileName.toStdString();

    cbMNT=new QCheckBox(fileName,this);

    cbMNT->move(10,100);
    cbMNT->show();
    //récupération des coordonnées des points à partir du fichier chargé
    //ui->widgetZoneVisu->loadMnt(fileName.toStdString());
*/
}

MainWindow::~MainWindow()
{
   // delete cbMNT;
    delete ui;

}
