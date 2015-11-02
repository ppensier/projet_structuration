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
      /*glBegin(GL_POINTS);

      for(int i=0; i<leMnt->lesPoints.size();i++)
      {
          glVertex3f(leMnt->lesPoints[i].getX(), leMnt->lesPoints[i].getY(), leMnt->lesPoints[i].getZ());
      }*/
      glBegin(GL_TRIANGLES);

            for(int i=0; i<leMnt->lesTriangles.size();i++)
            { if(i%3==1)
                    glColor3f(0.0f,0.0f,1.0f); //blue color
              if(i%3==2)
                    glColor3f(0.0f,1.0f,0.0f); //green color
              if(i%3==0)
                    glColor3f(1.0f,0.0f,1.0f); //red color
              //glVertex3f(leMnt->lesPoints[leMnt->lesTriangles[i].Sommet1].getX(),leMnt->lesPoints[leMnt->lesTriangles[i].Sommet1].getY(),leMnt->lesPoints[leMnt->lesTriangles[i].Sommet1].getZ());
              glVertex3f(leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet1)-1].getX(),leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet1)-1].getY(),leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet1)-1].getZ());

              glVertex3f(leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet2)-1].getX(),leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet2)-1].getY(),leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet2)-1].getZ());
              glVertex3f(leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet3)-1].getX(),leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet3)-1].getY(),leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet3)-1].getZ());


            }
           /* glVertex3f(-1.0f,-0.25f,1.0f);//triangle one first vertex
            glVertex3f(-0.5f,-0.25f,-1.0f);//triangle one second vertex
            glVertex3f(-0.75f,0.25f,0.5f);
            glColor3f(0.0f,1.0f,0.0f); //blue color
            glVertex3f(-0.5f,-0.25f,-1.0f);//triangle one second vertex
            glVertex3f(-0.75f,0.25f,0.5f);
            glVertex3f(0.75f,0.25f,0.0f);*/
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
