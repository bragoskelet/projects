#ifndef EDITEURTERRAIN_H
#define EDITEURTERRAIN_H

#include <vector>

using std::vector;

class editeurTerrain
{
    enum types{VIDE,DEBRIS,JOUEUR_NORMAL,JOUEUR_EXPERT,ROBOT_1G,ROBOT_2G};
    const int NB_TYPES=6;

    public:
        editeurTerrain();
        editeurTerrain(int largeur,int hauteur);
        void initialiseTerrain();
        void afficheGrille() const;
        void afficheChoix() const;
        void affichePosition() const;
        void sauve() const;
        void editeur();
    private:
        int d_largeur, d_hauteur;
        vector<vector<int>> d_grille;

};

void cursor(int l, int c);

#endif // EDITEURTERRAIN_H
