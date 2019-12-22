#include "editeurTerrain.h"
#include <iostream>
#include "windows.h"
#include "fstream"

using std::cout;
using std::cin;
using std::endl;

void cursor(int l, int c)
{
	COORD cs={c, l};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cs);
}

editeurTerrain::editeurTerrain(): d_grille{}
{}

editeurTerrain::editeurTerrain(int largeur,int hauteur): d_largeur{largeur}, d_hauteur{hauteur}, d_grille{}
{
    initialiseTerrain();
}

void editeurTerrain::initialiseTerrain()
{
    d_grille.resize(d_largeur);
    for(int i=0;i<d_largeur;i++)
    {
        d_grille[i].resize(d_hauteur);
        for(int j=0;j<d_hauteur;j++)
        {
            d_grille[i][j]=types::VIDE;
        }
    }
}

void editeurTerrain::afficheGrille() const
{
    cout<<"  ";
    for(int i=0; i<d_largeur; ++i) //coord sur la grille
    {
         cout<<i<<" ";
    }
    cout<<"\n\n";

    for(int i=0;i<d_hauteur;i++)
    {
        cout<<i<<" ";
        for(int j=0;j<d_largeur;j++)
        {
            cout<<d_grille[j][i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void editeurTerrain::afficheChoix() const
{
    cout<<"\nTapez: "<<VIDE<<" pour une case vide\n";
    cout<<"Tapez: "<<DEBRIS<<" pour un debris\n";
    cout<<"Tapez: "<<JOUEUR_NORMAL<<" pour un joueur normal\n";
    cout<<"Tapez: "<<JOUEUR_EXPERT<<" pour un joueur expert\n";
    cout<<"Tapez: "<<ROBOT_1G<<" pour un robot de premiere generation\n";
    cout<<"Tapez: "<<ROBOT_2G<<" pour un robot de deuxieme generation\n";
    cout<<"Tapez -1 pour sauver et quitter.\n\n";
    cout<<"Choisir un objet valide de la liste : \n";

}

void editeurTerrain::affichePosition() const
{
    cout<<"Entrer une position valide en x et y a modifier : ";
}

void editeurTerrain::sauve() const
{
    /* lecture terrain:
    LARGEUR HAUTEUR
    TYPE_JOUEUR POS_JOUEUR
    NB_ROBOTS TYPE+POS_ROBOTS
    NB_DEBRIS POS_DEBRIS
    */



}

void editeurTerrain::editeur()
{
    int largeur, hauteur;
    do
    {
        system("cls");
        cout<<"Entrer une largeur et une hauteur valides de terrain : ";
        cin>>largeur>>hauteur;
    } while(largeur<=0 || hauteur<=0);

    d_largeur=largeur;
    d_hauteur=hauteur;
    initialiseTerrain();

    bool quitter=false, joueurSaisi=false;;
    while(!quitter)
    {
        int choix;
        do
        {
            system("cls");
            afficheGrille();
            afficheChoix();
            cin>>choix;
        } while(choix<-1 || choix>NB_TYPES-1);

        if(choix==-1) quitter=true;

        else //edit
        {
            int x,y;
            do
            {
                system("cls");
                afficheGrille();
                affichePosition();
                cin>>x>>y;
            } while(x<0 || x>=d_largeur || y<0 || y>=d_hauteur);

            if(choix==types::JOUEUR_NORMAL || choix==types::JOUEUR_EXPERT)
            {
                if(joueurSaisi)
                {
                    int i=0, j=0; //à optimiser
                    while(i<d_largeur && d_grille[i][j]!=types::JOUEUR_NORMAL && d_grille[i][j]!=types::JOUEUR_EXPERT)
                    {
                        j=0;
                        while(j<d_hauteur && d_grille[i][j]!=types::JOUEUR_NORMAL && d_grille[i][j]!=types::JOUEUR_EXPERT)
                        {
                            ++j;
                        }

                        if(d_grille[i][j]!=types::JOUEUR_NORMAL && d_grille[i][j]!=types::JOUEUR_EXPERT)++i;
                    }
                    d_grille[i][j]=types::VIDE;
                }

                else joueurSaisi=true;
            }

            d_grille[x][y]=choix;
        }

    } //on quittera

    sauve();
}
