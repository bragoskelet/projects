#include "terrain.h"

using std::cout;
using std::endl;

terrain::terrain(int largeur, int hauteur): d_largeur{largeur}, d_hauteur{hauteur}, d_grille(d_hauteur)
{
    for(int i=0; i<d_grille.size(); ++i)
    {
        d_grille[i].resize(d_largeur);
        for(int j=0; j<d_largeur; ++j) d_grille[i][j]=VIDE;
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
    for(int i=0; i<d_grille.size(); ++i)
    {
        for(int j=0; j<d_grille[i].size(); ++j) cout<<d_grille[i][j]<<" ";
        cout<<endl;
    }
}

void terrain::sauve() const
{

}

void terrain::charge()
{

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


