#include "mnt.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;
Mnt::Mnt()
{
}

void Mnt::loadMnt(string fileName)
{       std::cout << "loading " <<fileName << " : debut..." << std::endl;
        ifstream fichier( fileName.data() );
        char line[TAILLE_MAX + 1] = "";
        if (! fichier) {
            std::cout<<"probleme lecture fichier : "<<fileName<<"inexistant ou deja ouvert\n";
            return;
        }
        // ce test &#65533;choue si le fichier n'est pas ouvert
      /*  string ligne; // variable contenant chaque ligne lue
int nb=0;
        // cette boucle s'arr&#65533;te d&#65533;s qu'une erreur de lecture survient
        while ( getline( fichier, ligne ) && nb<10 )
        {
            // afficher la ligne &#65533; l'&#65533;cran
            strcpy(line, ligne.data());
            Point p;
            int col_count = sscanf(line, "%f\t%f\t%f", &p.x, &p.y, &p.z);
            //if (col_count == 3)
            {
                lesPoints.push_back(p);
                cout << p.x<<" "<<p.y<<" "<<p.z<<endl;

            }

 nb++;
        }
        fichier.close();
        cout << "fin lecture !" << endl<<nb;*/
    while(!fichier.eof())
    {
        Point p;

        if(fichier >> p.x>> p.y>>p.z){
            //extracts 2 floating point values seperated by whitespace
        lesPoints.push_back(p);
        // do something with them
        cout << p.x<<" "<<p.y<<" "<<p.z<<endl;
        }


    }
    cout << "fsfsfdsf"<<endl;
        for(int i=0; i<lesPoints.size();i++)
        {
            cout << lesPoints[i].x<<" "<<lesPoints[i].y<<" "<<lesPoints[i].z<<endl;
        }
}
