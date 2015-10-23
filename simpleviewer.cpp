#include "simpleviewer.h"

using namespace std;

SimpleViewer::SimpleViewer()
{


}
SimpleViewer::SimpleViewer(QWidget *parent)
{
    //leMnt= NULL;
}
// Draws a spiral
void SimpleViewer::draw()
{
      glPointSize(10.0);
      glBegin(GL_POINTS);

      for(int i=0; i<leMnt->lesPoints.size();i++)
      {
          glVertex3f(leMnt->lesPoints[i].getX(), leMnt->lesPoints[i].getY(), leMnt->lesPoints[i].getZ());
      }
      glEnd();

}

void SimpleViewer::init()
{
  // Restore previous viewer state.
  restoreStateFromFile();

}

QString SimpleViewer::helpString() const
{
    return "ok";
}


SimpleViewer::~SimpleViewer()
{
    delete leMnt;
}
