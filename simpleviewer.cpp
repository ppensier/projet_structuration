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
{if(leMnt!=NULL && leGpx!=NULL)
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

       textureSol->bind();
       glEnable(GL_TEXTURE_2D);


      float ratio;
      float delta=leGpx->gpx_dalle.z_max_ses_triangles-leGpx->gpx_dalle.z_min_ses_triangles;
      glBegin(GL_TRIANGLES);

            for(int i=0; i<leGpx->gpx_dalle.sesTriangles.size();i++)
            {
                ratio=(leGpx->gpx_dalle.sesTriangles[i].z_moy/delta)-(leGpx->gpx_dalle.z_max_ses_triangles/delta)+1;


                    //glColor3f(ratio,ratio,ratio); //blue color

               glTexCoord2d(0,0);  glVertex3f(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getZ());

               glTexCoord2d(1,0);  glVertex3f(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getZ());
               glTexCoord2d(1,1);  glVertex3f(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getZ());


            }

      glEnd();
     /* this->camera()->setPosition(gentilhomme->pos_);

            this->camera()->setOrientation(0,-3.141592/2);
            this->camera()->lookAt(gentilhomme->nextSommet_);
              glBegin(GL_POINTS);

                gentilhomme->draw();
            glEnd();*/



    }

}
void SimpleViewer::animate()
{
 if(leGpx!=NULL) gentilhomme->bouge();
}

void SimpleViewer::loadTexture()
{
    QImage myGround("/home/gtsi/DDDgpx/ground_light",".jpg");
    textureSol=new QOpenGLTexture(myGround,QOpenGLTexture::DontGenerateMipMaps);


}
void SimpleViewer::init()
{
  // Restore previous viewer state.
  restoreStateFromFile();
  help();
  loadTexture();
  startAnimation();

}

QString SimpleViewer::helpString() const
{
    return "ok";
}


SimpleViewer::~SimpleViewer()
{
    delete leMnt;
    delete leGpx;
    delete gentilhomme;
}

