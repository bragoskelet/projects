#include <iostream>
#include <fstream>
#include <string>
#include "terrain.h"
#include "joueurNormal.h"
#include "joueurExpert.h"
#include "robot1G.h"
#include "robot2G.h"


using std::cout;
using std::endl;

terrain::terrain(int largeur, int hauteur):
    d_largeur{largeur}, d_hauteur{hauteur}, d_grille(), d_joueur{nullptr}, d_robots(), d_debris()
{
    initGrille();
}

terrain::~terrain()
{}

int terrain::hauteur()
{
    return d_hauteur;
}

int terrain::largeur()
{
    return d_largeur;
}

void terrain::affiche() const
{
    for(int i=0; i<d_hauteur; ++i)
    {
        for(int j=0; j<d_largeur; ++j) cout<<d_grille[j][i]<<" ";
        cout<<endl;
    }
}

void terrain::creeJoueur(int type, int x, int y)
{
    switch(type)
    {
        case type_joueur::NORMAL :
            d_joueur=new joueurNormal{x,y};
            break;
        case type_joueur::EXPERT :
            d_joueur=new joueurExpert{x,y};
        break;
    }
}

void terrain::creeRobot(int type, int x, int y)
{
    switch(type)
    {
        case type_robot::UN_G :
            d_robots.push_back(new robot1G{x,y});
            break;
        case type_robot::DEUX_G :
            d_robots.push_back(new robot2G{x,y});
        break;
    }
}

void terrain::creeDebris(int x, int y)
{
    d_debris.push_back({x,y});
}

void terrain::initGrille()
{
    d_grille.resize(d_largeur);
    for(int i=0; i<d_largeur; ++i)
    {
        d_grille[i].resize(d_hauteur);
        for(int j=0; j<d_hauteur; ++j) d_grille[i][j]=dalle::VIDE;
    }
}

void terrain::remplitGrille()
{
    //dimensions prêtes, il faut remplir la grille avec le joueur, robots, debris stockés

    //joueur
    d_grille[d_joueur->pos().x()][d_joueur->pos().y()]=dalle::JOUEUR;

    //robots
    for(int i=0; i<d_robots.size(); ++i) d_grille[d_robots[i]->pos().x()][d_robots[i]->pos().y()]=dalle::ROBOT;

    //debris
    for(int i=0; i<d_debris.size(); ++i) d_grille[d_debris[i].pos().x()][d_debris[i].pos().y()]=dalle::DEBRIS;
}

void terrain::sauve(string &fname) const
{
    std::ofstream f (fname);
    //créer nv fichier

    f.close();
}

void terrain::charge(const string &fname) //charge dans les données et non la grille
{
    /* lecture:
    LARGEUR HAUTEUR
    TYPE_JOUEUR POS_JOUEUR
    NB_ROBOTS TYPE+POS_ROBOTS
    NB_DEBRIS POS_DEBRIS
    */
    std::ifstream f(fname);
    if(!f.is_open())
    {
        cout<<"Erreur le fichier n'existe pas! Impossible de le lire "<<endl;
        return;
    }
    else
    {
        //on suppose pour l'instant que la lecture se passe bien
        int type, x, y, nb_objets;
        //dimensions
        f>>d_largeur>>d_hauteur;

        //joueur
        f>>type>>x>>y;
        creeJoueur(type,x,y);

        //robots
        f>>nb_objets; //ici nb de robots
        for(int i=0; i<nb_objets; ++i)
        {
            f>>type>>x>>y;
            creeRobot(type,x,y);
        }

        //debris
        f>>nb_objets; //ici nb de debris
        for(int i=0; i<nb_objets; ++i)
        {
            f>>x,y;
            creeDebris(x,y);
        }

        initGrille();//dim
        remplitGrille();//grille entière
    }
    f.close();
}

vector<int>& terrain::operator[](int i)
{
    return d_grille[i];
}

vector<int> terrain::operator[](int i)const
{
    return d_grille[i];
}

int& terrain::operator()(int i, int j)
{
    return d_grille[i][j];
}

int terrain::operator()(int i, int j) const
{
    return d_grille[i][j];
}

int& terrain::operator()(position& p)
{
    return d_grille[p.x()][p.y()];
}

int terrain::operator()(position p) const
{
    return d_grille[p.x()][p.y()];
}

const joueur* terrain::djoueur() const
{
    return d_joueur;
}

void terrain::joueurEcrase()
{
    d_joueur->estEcrase();
}

void terrain::detruitRobots(const position& pos)
{
    for(int i=0; i<d_robots.size(); ++i)
    {
        if(d_robots[i]->pos()==pos) d_robots[i]->collision();
    }
}
