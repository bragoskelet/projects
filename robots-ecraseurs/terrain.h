#ifndef TERRAIN_H
#define TERRAIN_H

#include <fstream>
#include <vector>
#include "position.h"
#include "robot.h"
#include "joueur.h"


using std::vector;
using std::string;

enum dalle{VIDE,DEBRIS,JOUEUR,ROBOT};

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

        joueur* djoueur() const; // nom de méthode différent de nom de class (joueur)
        vector<int>& operator[](int i);
        vector<int> operator[](int i)const;
        int& operator()(int i, int j);
        int operator()(int i, int j) const;

        void joueurEcrase();
        void detruitRobots(const position& pos);


    private:
        int d_largeur; //nb colonnes, le x ou i
        int d_hauteur; //nb lignes, le y ou j
        vector<vector<int>> d_grille;
        joueur* d_joueur;
        vector<robot*> d_robots;

};

#endif // TERRAIN_H
