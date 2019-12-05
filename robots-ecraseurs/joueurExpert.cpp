#include "joueurExpert.h"
#include "windows.h"
#include "terrain.h"

using std::cout;

joueurExpert::joueurExpert(int x, int y): joueur{x,y}
{
    //ctor
}

joueurExpert::~joueurExpert()
{
    //dtor
}


void joueurExpert::deplace(terrain& terrain)  // se déplace uniquement dans 4 directions: haut bas gauche droite
{
    bool deplace=false;

    while(!deplace)
    {
        bool haut=GetAsyncKeyState(VK_NUMPAD8);
        bool bas=GetAsyncKeyState(VK_NUMPAD2);
        bool droite=GetAsyncKeyState(VK_NUMPAD6);
        bool gauche=GetAsyncKeyState(VK_NUMPAD4);

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
    }

}

void joueurExpert::affiche() const
{
    cout<<"J";
}
