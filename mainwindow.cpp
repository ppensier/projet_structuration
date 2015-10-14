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
    leMnt=NULL;
    glWZone3D=NULL;
    glWZone3D = new GLWidget;
    glWZone3D->setParent(this);
    glWZone3D->setGeometry(200,80,380,300);
    glWZone3D->show();


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
    loadMnt(fileName.toStdString());

}

MainWindow::~MainWindow()
{
    delete cbMNT;
    delete ui;
    delete leMnt;
}

void MainWindow::loadMnt(std::string filePath)
{


    //2- initialisation du MNT
    leMnt=new Mnt(filePath);

    //3-lecture du fichier , création des points et ajout des points à l'objet mnt
}
