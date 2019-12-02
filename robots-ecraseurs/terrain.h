#ifndef TERRAIN_H
#define TERRAIN_H

#include <fstream>
#include <vector>
#include "position.h"
#include "joueur.h"
#include "robot.h"

using std::vector;
using std::string;

enum c{VIDE,DEBRIS,JOUEUR,ROBOT};

class terrain
{

    public:
        terrain(int largeur, int hauteur);
        virtual ~terrain();
        int hauteur();
        int largeur();
        void affiche() const;
        void sauve() const;
        void charge();

        vector<int>& operator[](int i);
        vector<int> operator[](int i)const;
        int& operator()(int i, int j);
        int operator()(int i, int j) const;


    protected:

    private:
        int d_largeur;
        int d_hauteur;
        vector<vector<int>> d_grille;
        //joueur* d_joueur;
        //vector<robot*> d_robots;


};

#endif // TERRAIN_H
