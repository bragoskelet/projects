#ifndef TERRAIN_H
#define TERRAIN_H

#include <fstream>
#include <vector>
#include <string>
#include "position.h"
#include "robot.h"
#include "joueur.h"
#include "debris.h"


using std::vector;
using std::string;

enum dalle{VIDE,DEBRIS,JOUEUR,ROBOT};
enum type_joueur{NORMAL,EXPERT};
enum type_robot{UN_G,DEUX_G};

class terrain
{
    public:
        terrain(int largeur, int hauteur);
        virtual ~terrain();
        int hauteur();
        int largeur();
        void affiche() const;
        void creeJoueur(int type, int x, int y);
        void creeRobot(int type, int x, int y);
        void creeDebris(int x, int y);

        void sauve(string & fname) const;
        void charge(const string & fname);

        const joueur* djoueur() const; // nom de méthode différent de nom de class (joueur) sinon bug
        vector<int>& operator[](int i);
        vector<int> operator[](int i)const;
        int& operator()(int i, int j);
        int operator()(int i, int j) const;

        int& operator[](const position& p);
        int operator[](const position& p) const

        void joueurEcrase();
        void detruitRobots(const position& pos);
        void deplace();

		void remplitGrille();
    private:
        int d_largeur; //nb colonnes, le x ou i
        int d_hauteur; //nb lignes, le y ou j
        vector<vector<int>> d_grille;
        joueur* d_joueur;
        vector<robot*> d_robots;
        vector<debris> d_debris;

        void initGrille();


};

#endif // TERRAIN_H
