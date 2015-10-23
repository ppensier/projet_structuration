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
{
    std::cout << "loading " <<fileName << " : debut..." << std::endl;
    ifstream fichier( fileName.data() );
    char line[TAILLE_MAX + 1] = "";
    if (! fichier) {
        std::cout<<"probleme lecture fichier : "<<fileName<<" inexistant ou deja ouvert\n";
        return;
    }
    // ce test �choue si le fichier n'est pas ouvert
    string ligne; // variable contenant chaque ligne lue

    // cette boucle s'arr�te d�s qu'une erreur de lecture survient
    while ( getline( fichier, ligne ) )
    {
        // afficher la ligne � l'�cran
        strcpy(line, ligne.data());
        Point p;
        float x,y,z;
        int col_count = sscanf(line, "%f %f %f", &x, &y, &z);
        p.setX(x);
        p.setY(y);
        p.setZ(z);
        if (col_count == 3)
        {
            lesPoints.push_back(p);
        }
        //cout << line << endl;
    }
}
