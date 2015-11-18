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
    cbMNT=NULL;
    cbGPX=NULL;

}

void MainWindow::on_Action_ouvrirMNT_triggered()
{


    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open MNT"), "/home/gtsi/DDDgpx/", tr("All files  (*.xyz)"));
    if(fileName=="") return;

    cbMNT=new QCheckBox(fileName,this);

    cbMNT->move(10,100);
    cbMNT->show();

    ui->widgetZoneVisu->leMnt=new Mnt();

    ui->widgetZoneVisu->leMnt->loadMnt(fileName.toStdString());


}

void MainWindow::on_actionOuvrir_GPX_triggered()
{

    if(ui->widgetZoneVisu->leMnt==NULL) return;
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open MNT"), "/home/gtsi/DDDgpx/", tr("All files  (*.gpx)"));
    if(fileName=="") return;

    cbGPX=new QCheckBox(fileName,this);

    cbGPX->move(10,120);
    cbGPX->show();
    //récupération des coordonnées des points à partir du fichier chargé
    //ui->widgetZoneVisu->loadMnt();


    //bounds de GPX : voir Romain...
       /* Point BoundsMin;
        BoundsMin.x=0.1;

        BoundsMin.y=-0.75;

        Point BoundsMax;
        BoundsMax.x= 0.9;

        BoundsMax.y= -0.1;
                */

        Point BoundsMin;
        BoundsMin.x=900111;

        BoundsMin.y=1900026;

        Point BoundsMax;
        BoundsMax.x= 900511;

        BoundsMax.y= 1900126;


        ui->widgetZoneVisu->leGpx=new gpx();
        ui->widgetZoneVisu->leGpx->loadGpx("");
        ui->widgetZoneVisu->leGpx->minlat=BoundsMin.y;
        ui->widgetZoneVisu->leGpx->minlon=BoundsMin.x;
        ui->widgetZoneVisu->leGpx->maxlat=BoundsMax.y;
        ui->widgetZoneVisu->leGpx->maxlon=BoundsMax.x;
        ui->widgetZoneVisu->leGpx->CalculateBoundsDalle(*(ui->widgetZoneVisu->leMnt));

        ui->widgetZoneVisu->leGpx->CalculateIndicePointsDalle(*(ui->widgetZoneVisu->leMnt));

        ui->widgetZoneVisu->leGpx->BuildTriangles(*(ui->widgetZoneVisu->leMnt));
        //Construire la trajectoire
        ui->widgetZoneVisu->leGpx->CalculateTrajectoire(*(ui->widgetZoneVisu->leMnt));

         // creation du rondonneur et affectation de la trajectoire
        ui->widgetZoneVisu->gentilhomme = new Randonneur();
        ui->widgetZoneVisu->gentilhomme->randonnee=ui->widgetZoneVisu->leGpx->trajectoire;


}

MainWindow::~MainWindow()
{
    delete cbMNT;
    delete cbGPX;
    delete ui;

}
