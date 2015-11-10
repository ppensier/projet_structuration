#include "simpleviewer.h"

using namespace std;

SimpleViewer::SimpleViewer()
{
}
SimpleViewer::SimpleViewer(QWidget *parent)
{
    this->setParent(parent);
}
// Draws a spiral
void SimpleViewer::draw()
{
    qglviewer::Vec boundingMin;
    qglviewer::Vec boundingMax;
    //
    boundingMin.x=leGpx->gpx_dalle.debut.x;
    boundingMin.y=leGpx->gpx_dalle.debut.y;
    boundingMin.z=leGpx->gpx_dalle.z_min;
    //
    boundingMax.x=leGpx->gpx_dalle.fin.x;
    boundingMax.y=leGpx->gpx_dalle.fin.y;
    boundingMax.z=leGpx->gpx_dalle.z_max;

    SimpleViewer::setSceneBoundingBox(boundingMin,boundingMax);
    SimpleViewer::showEntireScene();
      glPointSize(10.0);
      /*glBegin(GL_POINTS);

      for(int i=0; i<leMnt->lesPoints.size();i++)
      {
          glVertex3f(leMnt->lesPoints[i].getX(), leMnt->lesPoints[i].getY(), leMnt->lesPoints[i].getZ());
      }*/
      float ratio;
      float delta=leGpx->gpx_dalle.z_max_ses_triangles-leGpx->gpx_dalle.z_min_ses_triangles;
      glBegin(GL_TRIANGLES);

            for(int i=0; i<leGpx->gpx_dalle.sesTriangles.size();i++)
            {
                ratio=(leGpx->gpx_dalle.sesTriangles[i].z_moy/delta)-(leGpx->gpx_dalle.z_max_ses_triangles/delta)+1;

               // if(i%3==1)
                    glColor3f(ratio,ratio,ratio); //blue color
               /* if(i%3==2)
                    glColor3f(0.65247,0.65247,0.65247); //green color
                if(i%3==0)
                    glColor3f(0.65248,0.65248,0.65248);*/ //red color
              //glVertex3f(leMnt->lesPoints[leMnt->lesTriangles[i].Sommet1].getX(),leMnt->lesPoints[leMnt->lesTriangles[i].Sommet1].getY(),leMnt->lesPoints[leMnt->lesTriangles[i].Sommet1].getZ());
               glVertex3f(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getZ());

               glVertex3f(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getZ());
               glVertex3f(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getZ());


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
    delete leGpx;
}

