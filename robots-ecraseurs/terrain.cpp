#include <iostream>
#include <fstream>
#include <string>
#include "terrain.h"

using std::cout;
using std::endl;

terrain::terrain(int largeur, int hauteur): d_largeur{largeur}, d_hauteur{hauteur}, d_grille(d_largeur), d_joueur{nullptr}, d_robots()
{
    for(int i=0; i<largeur; ++i)
    {
        d_grille[i].resize(hauteur);
        for(int j=0; j<hauteur; ++j) d_grille[i][j]=VIDE;
    }
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

void terrain::sauve(string &fname) const
{

}

void terrain::charge(const string &fname)
{
    istream f(fname);
    if(!f.is_open())
    {
        cout<<"erreur le fichier n'existe pas ";
        return;
    }
    else
    {
        int larg,haut;
        f>>larg>>haut;
        for(int i=0; i<larg; i++)
        {
            d_grille[i].resize(haut);
            for(int j=0; j<hauteur; j++) 
            {
                f>>d_grille[i][j];
            }
        }
    }
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

joueur* terrain::djoueur() const
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
