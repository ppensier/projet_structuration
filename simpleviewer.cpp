#include "simpleviewer.h"
#include <QKeyEvent>

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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   //setBackgroundColor(QColor(0,1,0,100));
    if( leGpx!=NULL)
    {
        glPointSize(10.0);
        if(leGpx->isDisplayed)
        {
            afficheTriangleCouleur(leGpx);
           // afficheQuadsTexture(leGpx);

            if(gentilhomme!=NULL)
            {
                glBegin(GL_POINTS);
                gentilhomme->draw();
                glEnd();

            }
        }
    }
     if(leMnt!=NULL )
     {
        if(leMnt->isDisplayed )
        {


            gpx_dalle_mnt=new gpx();
            gpx_dalle_mnt->loadGpx("");
            gpx_dalle_mnt->minlat=leMnt->MIN_MNT.y;
            gpx_dalle_mnt->minlon=leMnt->MIN_MNT.x;
            gpx_dalle_mnt->maxlat=leMnt->MAX_MNT.y;
            gpx_dalle_mnt->maxlon=leMnt->MAX_MNT.x;
            gpx_dalle_mnt->CalculateBoundsDalle(*leMnt);

            gpx_dalle_mnt->CalculateIndicePointsDalle(*leMnt);

            gpx_dalle_mnt->BuildTriangles(*leMnt);
            afficheTriangleCouleur(gpx_dalle_mnt);

            updateView(gpx_dalle_mnt);

        }
     }


}
void SimpleViewer::afficheTriangleCouleur( gpx *leGpx)
{
    float ratio;
    float delta=leGpx->gpx_dalle.z_max_ses_triangles-leGpx->gpx_dalle.z_min_ses_triangles;

    /*glBegin(GL_TRIANGLES);
    for(int i=0; i<leGpx->gpx_dalle.sesTriangles.size();i++)
    {
        ratio=(leGpx->gpx_dalle.sesTriangles[i].z_moy/delta)-(leGpx->gpx_dalle.z_max_ses_triangles/delta)+1;


        glColor3f(ratio,ratio,ratio); //blue color


        glVertex3f(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getZ());

        glVertex3f(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getZ());


        glVertex3f(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getZ());

    }
    glEnd();
    */
    std::vector <qglviewer::Vec> tab_triangles;
    std::vector <qglviewer::Vec> tab_quads_color;
    for(int i=0; i<leGpx->gpx_dalle.sesTriangles.size();i++)
    {

              tab_triangles.push_back(qglviewer::Vec(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getZ()));
              tab_triangles.push_back(qglviewer::Vec(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getZ()));

              tab_triangles.push_back(qglviewer::Vec(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getZ()));
              ratio=(leGpx->gpx_dalle.sesTriangles[i].z_moy/delta)-(leGpx->gpx_dalle.z_max_ses_triangles/delta)+1;
              tab_quads_color.push_back(qglviewer::Vec(ratio,ratio,ratio));
              /*tab_quads_color.push_back(qglviewer::Vec(ratio,ratio,ratio));

              tab_quads_color.push_back(qglviewer::Vec(ratio,ratio,ratio));
*/

    }
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);



    glVertexPointer(3, GL_FLOAT, 0, tab_triangles.data());
    glColorPointer(3,GL_FLOAT,3,tab_quads_color.data());

    //glTexCoordPointer(2,GL_FLOAT,0,tab_quads_color.data());

    glDrawArrays(GL_TRIANGLES, 0, tab_triangles.size());


    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    cout << "dessin" << endl;




}
void SimpleViewer::afficheMNT()
{
    float ratio;
    float delta=leMnt->z_max_ses_triangles-leMnt->z_min_ses_triangles;


     glBegin(GL_TRIANGLES);
    for(int i=0; i<leGpx->gpx_dalle.sesTriangles.size();i++)
    {
        ratio=(leMnt->lesTriangles[i].z_moy/delta)-(leMnt->z_max_ses_triangles/delta)+1;


        glColor3f(ratio,ratio,ratio); //blue color


        glVertex3f(leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet1)-1].getX(),leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet1)-1].getY(),leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet1)-1].getZ());

        glVertex3f(leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet2)-1].getX(),leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet2)-1].getY(),leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet2)-1].getZ());

        glVertex3f(leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet3)-1].getX(),leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet3)-1].getY(),leMnt->lesPoints[(leMnt->lesTriangles[i].id_Sommet3)-1].getZ());

    }
    glEnd();

}
void SimpleViewer::afficheQuadsTexture(gpx *leGpx)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    textureSol->bind();
    for(int i=0; i<leGpx->gpx_dalle.sesTriangles.size();i++)
    {

        if(i%2==0 )
        {
            glBegin(GL_QUADS);

            glTexCoord2d(0,1);  glVertex3f(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getZ());
            glTexCoord2d(1,1);  glVertex3f(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getZ());
            glTexCoord2d(1,0);  glVertex3f(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i+1].id_Sommet3)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i+1].id_Sommet3)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i+1].id_Sommet3)-1].getZ());
            glTexCoord2d(0,0);  glVertex3f(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getZ());

            glEnd();
            cout<<"sommet1 "<<leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getX()<<","<<leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getY()<<" , "<<leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getZ()<<endl;
            cout<<"sommet2 "<<leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getX()<<","<<leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getY()<<" , "<<leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getZ()<<endl;
            cout<<"sommet3 "<<leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i+1].id_Sommet3)-1].getX()<<","<<leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i+1].id_Sommet3)-1].getY()<<" , "<<leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i+1].id_Sommet3)-1].getZ()<<endl;
            cout<<"sommet4 "<<leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getX()<<","<<leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getY()<<" , "<<leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getZ()<<endl;



        }

    }

    glDisable(GL_TEXTURE_2D);



    /******methode 2****
    std::vector <qglviewer::Vec> tab_quads;
    for(int i=0; i<leGpx->gpx_dalle.sesTriangles.size();i++)
    {

        if(i%2==0 )
        {


              tab_quads.push_back(qglviewer::Vec(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet1)-1].getZ()));
              tab_quads.push_back(qglviewer::Vec(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet2)-1].getZ()));
              tab_quads.push_back(qglviewer::Vec(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i+1].id_Sommet3)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i+1].id_Sommet3)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i+1].id_Sommet3)-1].getZ()));
              tab_quads.push_back(qglviewer::Vec(leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getX(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getY(),leMnt->lesPoints[(leGpx->gpx_dalle.sesTriangles[i].id_Sommet3)-1].getZ()));


        }

    }
    std::vector <qglviewer::Vec> tab_quads_texture;
    for (int i=0;i<(leGpx->gpx_dalle.sesTriangles.size())/2;i++)
         {
             tab_quads_texture.push_back(qglviewer::Vec(0,1,0));
             tab_quads_texture.push_back(qglviewer::Vec(1,1,0));
             tab_quads_texture.push_back(qglviewer::Vec(1,0,0));
             tab_quads_texture.push_back(qglviewer::Vec(0,0,0));

         }


        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        glBindTexture( GL_TEXTURE_2D, textureSol->textureId());

        glVertexPointer(3, GL_FLOAT, 0, tab_quads.data());
        glTexCoordPointer(2,GL_FLOAT,0,tab_quads_texture.data());

        glDrawArrays(GL_QUADS, 0, tab_quads.size());


        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
        cout << "dessin" << endl;*/


}
void SimpleViewer::animate()
{
    if(leGpx!=NULL) gentilhomme->bouge();
}

void SimpleViewer::loadTexture()
{
    QImage myGround("/home/gtsi/DDDgpx/terrain",".jpg");
    textureSol=new QOpenGLTexture(myGround,QOpenGLTexture::DontGenerateMipMaps);


}
void SimpleViewer::init()
{
    // Restore previous viewer state.
    restoreStateFromFile();
    help();
    loadTexture();
    setAnimationPeriod(100);


    //


}
void SimpleViewer::updateView(gpx *leGpx)
{
    if(leGpx!=NULL)
    {qglviewer::Vec boundingMin;
        qglviewer::Vec boundingMax;

        boundingMin.x=leGpx->gpx_dalle.debut.x;
        boundingMin.y=leGpx->gpx_dalle.debut.y;
        boundingMin.z=leGpx->gpx_dalle.z_min;
        //
        boundingMax.x=leGpx->gpx_dalle.fin.x;
        boundingMax.y=leGpx->gpx_dalle.fin.y;
        boundingMax.z=leGpx->gpx_dalle.z_max;

        SimpleViewer::setSceneBoundingBox(boundingMin,boundingMax);
        SimpleViewer::showEntireScene();
    }

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
void SimpleViewer::keyPressEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_Q)
    {
        if(gentilhomme!=NULL)

        {
            this->camera()->setPosition(gentilhomme->pos_+qglviewer::Vec(0,0,1));

            this->camera()->setOrientation(0,-3.141592/2);
            this->camera()->lookAt(gentilhomme->nextSommet_+qglviewer::Vec(0,0,1));
        }

    }
    if(event->key()==Qt::Key_S)
        updateView(leGpx);

}

