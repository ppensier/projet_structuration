#ifndef SIMPLEVIEWER_H
#define SIMPLEVIEWER_H

#include <QGLViewer/qglviewer.h>
#include <mnt.h>

class SimpleViewer : public QGLViewer
{

protected :
  virtual void draw();
  virtual void init();
  virtual QString helpString() const;
public :

    SimpleViewer();
    ~SimpleViewer();
    SimpleViewer(QWidget *parent = 0);
    Mnt *leMnt;


};

#endif
