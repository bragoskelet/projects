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
using std::cin;

terrain::terrain(): d_largeur{0}, d_hauteur{0}, d_grille(), d_joueur{nullptr}, d_robots(), d_debris()
{}

terrain::terrain(int largeur, int hauteur):
    d_largeur{largeur}, d_hauteur{hauteur}, d_grille(), d_joueur{nullptr}, d_robots(), d_debris()
{
    initGrille();
}

terrain::~terrain()
{
    delete d_joueur;
    for(int i=0; i<d_robots.size(); ++i)
    {
        delete d_robots[i];
    }
    d_robots.clear();
}

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
        for(int j=0; j<d_largeur; ++j)
        {
            //cout<<d_grille[j][i]<<" ";
            if(d_grille[j][i]==dalle::VIDE) cout<<d_grille[j][i]<<" ";
            else if(d_grille[j][i]==dalle::ROBOT) cout<<"R ";
            else if(d_grille[j][i]==dalle::JOUEUR) cout<<"J ";
            else cout<<"X ";
        }
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
            f>>x>>y;
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


//accès avec pos
int& terrain::operator[](const position& p)
{
    return d_grille[p.x()][p.y()];
}
//accès avec pos
int terrain::operator[](const position& p) const
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

bool terrain::tousRobotsDetruits() const
{
    bool tousDetruits=true;
    int i=0;
    while(i<d_robots.size() && tousDetruits)
    {
        if(!d_robots[i]->detruit()) tousDetruits=false;
        ++i;
    }

    return tousDetruits;
}

void terrain::TEST_deplacements()
{
    while(!d_joueur->estMort())
    {
        d_joueur->deplace(*this);
        system("cls");
        affiche();
        int x,y;
        x=d_robots[0]->pos().x();
        y=d_robots[0]->pos().y();
        d_robots[0]->deplace(*this);
        system("cls");
        affiche();

        cout<<"Pos robot avant "<<x<<","<<y<<endl;
        cout<<"Pos robot apres "<<d_robots[0]->pos().x()<<","<<d_robots[0]->pos().y()<<endl;
    }
}

void terrain::deplacements()
{
    affiche();
    while(!d_joueur->estMort() && !tousRobotsDetruits())
    {
        d_joueur->deplace(*this);
        system("cls");
        affiche();
        for(int i=0; i<d_robots.size(); ++i)
        {
            if(!d_robots[i]->detruit()) d_robots[i]->deplace(*this);
            system("cls");
            affiche();
        }

    }
}
