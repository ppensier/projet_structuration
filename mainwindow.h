#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <glwidget.h>
#include <mnt.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();
    QCheckBox *cbMNT ;
    QCheckBox *cbGPX ;

    /*****Les méthodes******/




signals:
     void clicked();


private slots:
     void on_Action_ouvrirMNT_triggered();
     void on_actionOuvrir_GPX_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
