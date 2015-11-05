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


    ui->widgetZoneVisu->setParent(this);

    ui->widgetZoneVisu->leMnt=new Mnt();
    ui->widgetZoneVisu->leMnt->loadMnt("//home//gtsi//DDDgpx//ecrin10pt.xyz");
    ui->widgetZoneVisu->leMnt->BuildTriangles();

    //4-Retrouver les triangles de dalle à partir des points de la dalle : leMnt->setTriangles();
//bounds de GPX : voir Romain...
    Point BoundsMin;
    BoundsMin.x=0.5;
    BoundsMin.y=-0.75;
    Point BoundsMax;
    BoundsMax.x= 0.9;//990000;
    BoundsMax.y= -0.1;//1940000;
//1-Trouver les deux points délimitant la dalle leMnt-> ; leMnt->CalculateMaxDalle(maxBounds);
//2-Construire la dalle : leMnt->dalle.setBounds(p1,p2);

ui->widgetZoneVisu->leMnt->CalculateBoundsDalle(BoundsMin,BoundsMax);

//3-Définir les indices du maillage de la dalle : leMnt.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           Dalle();
ui->widgetZoneVisu->leMnt->CalculateIndicePointsDalle();

}

void MainWindow::on_Action_ouvrirMNT_triggered()
{


    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open MNT"), "/home/jana", tr("All files  (*.xyz)"));

    std::cout<<fileName.toStdString();

    cbMNT=new QCheckBox(fileName,this);

    cbMNT->move(10,100);
    cbMNT->show();
    //récupération des coordonnées des points à partir du fichier chargé
    //ui->widgetZoneVisu->loadMnt(fileName.toStdString());

}

MainWindow::~MainWindow()
{
   // delete cbMNT;
    delete ui;

}
