#ifndef EDITEURTERRAIN_H
#define EDITEURTERRAIN_H

#include <vector>

using std::vector;

class editeurTerrain
{
    const int VIDE=0;
    const int DEBRIS=1;
    const int JOUEURNORMAL=21;
    const int JOUEUREXPERT=22;
    const int ROBOT1G=31;
    const int ROBOT2G=32;
    public:
        editeurTerrain(int largeur,int hauteur);
        void initialiserTerrain();
        void affichageEditeur();
        void editeur(int largeur, int hauteur);
    private:
        vector <vector<int> > d_terrain;
        int d_largeur,d_hauteur;
};

#endif // EDITEURTERRAIN_H
