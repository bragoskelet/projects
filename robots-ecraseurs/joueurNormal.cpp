#include "joueurNormal.h"
#include "windows.h"
#include "terrain.h"

using std::cout;


joueurNormal::joueurNormal(int x, int y): joueur{x,y}
{}

joueurNormal::~joueurNormal()
{}

void joueurNormal::deplace(terrain& terrain) //Se déplace dans les 3 directions : verticale, horizontale ou diagonale
{
    bool deplace=false;

    while(!deplace)
    {
        bool haut=GetAsyncKeyState(VK_NUMPAD8);
        bool bas=GetAsyncKeyState(VK_NUMPAD2);
        bool droite=GetAsyncKeyState(VK_NUMPAD6);
        bool gauche=GetAsyncKeyState(VK_NUMPAD4);
        bool haut_gauche=GetAsyncKeyState(VK_NUMPAD7);
        bool haut_droite=GetAsyncKeyState(VK_NUMPAD9);
        bool bas_gauche=GetAsyncKeyState(VK_NUMPAD1);
        bool bas_droite=GetAsyncKeyState(VK_NUMPAD3);

        if(haut)
        {
            if(pos().y()>0 && terrain[pos().x()][pos().y()-1]==VIDE)
            {
                terrain[pos().x()][pos().y()]=VIDE;
                decale(0,-1);
                terrain[pos().x()][pos().y()]=JOUEUR;
                deplace=true;
            }
        }

        else if(bas)
        {
            if(pos().y()<terrain.hauteur()-1 && terrain[pos().x()][pos().y()+1]==VIDE)
            {
                terrain[pos().x()][pos().y()]=VIDE;
                decale(0,1);
                terrain[pos().x()][pos().y()]=JOUEUR;
                deplace=true;
            }
        }

        else if(gauche)
        {
            if(pos().x()>0 && terrain[pos().x()-1][pos().y()]==VIDE)
            {
                terrain[pos().x()][pos().y()]=VIDE;
                decale(-1,0);
                terrain[pos().x()][pos().y()]=JOUEUR;
                deplace=true;
            }
        }

        else if(droite)
        {
            if(pos().x()<terrain.largeur()-1 && terrain[pos().x()+1][pos().y()]==VIDE)
            {
                terrain[pos().x()][pos().y()]=VIDE;
                decale(1,0);
                terrain[pos().x()][pos().y()]=JOUEUR;
                deplace=true;
            }
        }

        else if(haut_gauche)
        {
            if(pos().y()>0 && pos().x()>0 && terrain[pos().x()-1][pos().y()-1]==VIDE)
            {
                terrain[pos().x()][pos().y()]=VIDE;
                decale(-1,-1);
                terrain[pos().x()][pos().y()]=JOUEUR;
                deplace=true;
            }
        }

        else if(haut_droite)
        {
            if(pos().y()>0 && pos().x()<terrain.largeur()-1 && terrain[pos().x()+1][pos().y()-1]==VIDE)
            {
                terrain[pos().x()][pos().y()]=VIDE;
                decale(1,-1);
                terrain[pos().x()][pos().y()]=JOUEUR;
                deplace=true;
            }
        }

        else if(bas_gauche)
        {
            if(pos().y()<terrain.hauteur()-1 && pos().x()>0 && terrain[pos().x()-1][pos().y()+1]==VIDE)
            {
                terrain[pos().x()][pos().y()]=VIDE;
                decale(-1,1);
                terrain[pos().x()][pos().y()]=JOUEUR;
                deplace=true;
            }
        }

        else if(bas_droite)
        {
            if(pos().y()<terrain.hauteur()-1 && pos().x()<terrain.largeur()-1 && terrain[pos().x()+1][pos().y()+1]==VIDE)
            {
                terrain[pos().x()][pos().y()]=VIDE;
                decale(1,1);
                terrain[pos().x()][pos().y()]=JOUEUR;
                deplace=true;
            }
        }
    }

}

void joueurNormal::affiche() const
{ cout<<"J"; }

