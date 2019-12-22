#include "editeurTerrain.h"
#include <iostream>
#include "windows.h"

using std::cout;
using std::cin;
using std::endl;

editeurTerrain::editeurTerrain(int largeur,int hauteur):d_largeur{largeur},d_hauteur{hauteur},d_terrain{}
{}

void editeurTerrain::initialiserTerrain()
{
    d_terrain.resize(d_largeur);
    for(int i=0;i<d_largeur;i++)
    {
        d_terrain[i].resize(d_hauteur);
        for(int j=0;j<d_hauteur;j++)
        {
            d_terrain[i][j]=VIDE;
        }
    }
}

void editeurTerrain::affichageEditeur()
{
    for(int i=0;i<d_largeur;i++)
    {
        for(int j=0;j<d_hauteur;j++)
        {
            if(d_terrain[i][j]<10)
            {
                cout<<d_terrain[i][j]<<"  ";
            }
            else
            {
                cout<<d_terrain[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

void editeurTerrain::editeur(int largeur, int hauteur)
{
    int continuer=1, x, y,choix;
    editeurTerrain t(largeur,hauteur);
    t.initialiserTerrain();
    while(continuer==1)
    {
        t.affichageEditeur();
        cout<<"Choisissez la position en x et y a modifier :";
        cin>>x>>y;
        while(x<0||x>largeur)
        {
            cout<<"x n'est pas dans le terrain veuillez retaper x :";
            cin>>x;
        }
        while(y<0||y>hauteur)
        {
            cout<<"y n'est pas dans le terrain veuillez retaper y :";
            cin>>y;
        }
        cout<<"\n\nTapez: "<<VIDE<<" pour une case vide\n";
        cout<<"Tapez: "<<DEBRIS<<" pour un debris\n";
        cout<<"Tapez: "<<JOUEURNORMAL<<" pour un joueur normal\n";
        cout<<"Tapez: "<<JOUEUREXPERT<<" pour un joueur expert\n";
        cout<<"Tapez: "<<ROBOT1G<<" pour un robot de premiere generation\n";
        cout<<"Tapez: "<<ROBOT2G<<" pour un robot de deuxieme generation\n";
        cin>>choix;
        while(choix!=VIDE&&choix!=DEBRIS&&choix!=JOUEURNORMAL&&choix!=JOUEUREXPERT&&choix!=ROBOT1G&&choix!=ROBOT2G)
        {
            cout<<"Votre choix ne correspond pas a la liste donnee, veuillez retaper choix :";
            cin>>choix;
        }
        if(choix==JOUEURNORMAL||choix==JOUEUREXPERT)
        {
            for(int i=0;i<largeur;i++)
            {
                for(int j=0;j<hauteur;j++)
                {
                    if(t.d_terrain[i][j]==JOUEURNORMAL||t.d_terrain[i][j]==JOUEUREXPERT)
                    {
                        t.d_terrain[i][j]=VIDE;
                    }
                }
            }
        }
        t.d_terrain[y][x]=choix;
        system("cls");
        t.affichageEditeur();
        cout<<" Si vous voulez continuer a editer le terrain, tapez 1 sinon tapez autre chose : ";
        cin>>continuer;
        system("cls");
    }
}
