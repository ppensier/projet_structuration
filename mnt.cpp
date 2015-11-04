#include "mnt.h"
#include <math.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;
Mnt::Mnt()
{
    MIN_MNT.z=100000000;
    MAX_MNT.z=-100000;
    pasX=-1;
    pasY=-1;
    MIN_MNT.x=100000000;
    MIN_MNT.y=100000000;

    MAX_MNT.x=-100000;
    MAX_MNT.y=-100000;
}

void Mnt::loadMnt(string fileName)
{
    //Lecture du fichier et construction des points et initialisation des bounds et pas
    std::cout << "loading " <<fileName << " : debut..." << std::endl;
    ifstream fichier( fileName.data() );
    int nb=0;
    int compteur=0;
    Point p;
    if(!fichier)
    {
        cout<<"une erreur s'est produite lors de l'ouverture du MNT"<<endl;
        return;
    }
    while(!fichier.eof())
    {
        //if(compteur%4==0)
        {

        if(fichier >> p.x>> p.y>>p.z)
        {
            nb++;
            p.id_point=nb;
            lesPoints.push_back(p);
            if(p.z<MIN_MNT.z) MIN_MNT.z=p.z;
            if(p.z>MAX_MNT.z) MAX_MNT.z=p.z;
            /*****/
            if(p.x<MIN_MNT.x) MIN_MNT.x=p.x;
            if(p.x>MAX_MNT.x) MAX_MNT.x=p.x;
            /*****/
            if(p.y<MIN_MNT.y) MIN_MNT.y=p.y;
            if(p.y>MAX_MNT.y) MAX_MNT.y=p.y;

            if(nb>=2 && (pasX==-1 || pasY==-1)) //initialisation du pas à la deuxième itération
            {
                if(p.x!=lesPoints[nb-2].x && pasX==-1) pasX=fabs(fabs(p.x)-fabs(lesPoints[0].x));
                if(p.y!=lesPoints[nb-2].y && pasY==-1) pasY=fabs(fabs(p.y)-fabs(lesPoints[0].y));
            }


        }

        }
        compteur++;

    }

    cout << "fin de lecture du fichier :"<<endl;
    cout << lesPoints.size()<<" Points construits"<<endl;
    fichier.close();

  }
void Mnt::initializBounding()
{
    //initiation des limites de l'étendu
    MIN_MNT.x=lesPoints[0].x;
    MIN_MNT.y=lesPoints[0].y;

    MAX_MNT.x=lesPoints[lesPoints.size()-1].x;
    MAX_MNT.y=lesPoints[lesPoints.size()-1].y;


}
void Mnt::BuildTriangles()
{
    ///Construction des triangles

   int nbr_triangle=1;
   //initializBounding();
   int nL= ((MAX_MNT.y-MIN_MNT.y)/pasY)+1;
   int nC= ((MAX_MNT.x-MIN_MNT.x)/pasX)+1;
    for(int j=0;j<nL-1;j++)
        {   for(int i=0;i<nC-1;i++)
            {
                Triangle t1,t2;
                t1.id_Triangle=nbr_triangle;
                t1.id_Sommet1=lesPoints[i+(j*nL)].id_point;
                t1.id_Sommet2=lesPoints[i+1+(j*nL)].id_point;
                t1.id_Sommet3=lesPoints[i+nC+(j*nL)].id_point;
                lesTriangles.push_back(t1);
                nbr_triangle++;
                //cout << "mon triangle"<<t1.id_Triangle<<" : "<<t1.id_Sommet1<<" "<<t1.id_Sommet2<<" "<<t1.id_Sommet3<<endl;
                t2.id_Triangle=nbr_triangle;
                t2.id_Sommet1=lesPoints[i+1+(j*nL)].id_point;
                t2.id_Sommet2=lesPoints[i+nC+(j*nL)].id_point;
                t2.id_Sommet3=lesPoints[i+1+nC+(j*nL)].id_point;
                lesTriangles.push_back(t2);
                //cout << "mon triangle "<<t2.id_Triangle<<" : "<<t2.id_Sommet1<<" "<<t2.id_Sommet2<<" "<<t2.id_Sommet3<<endl;
                nbr_triangle++;
            }

        }

    cout<<"le nombre de triangles crées :"<<lesTriangles.size();

}
