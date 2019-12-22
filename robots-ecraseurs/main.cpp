#include <iostream>
#include <cstdlib>
#include "menu.h"
#include "terrain.h"
#include "joueurNormal.h"
#include "robot2G.h"
#include "windows.h"
#include "editeurTerrain.h"

#include "graphics.h"

using std::cout;
using std::cin;
using std::endl;

void testOperator()
{
    terrain t{5,5};
    int x=3, y=1;
    cout<<t[x][y]<<" ";
    t[x][y]=JOUEUR;
    cout<<t[x][y]<<" ok"<<endl;
    t.affiche();
}

void testCoord()
{
    terrain t{4,6};
    joueurNormal j{1,2};
    t[1][2]=JOUEUR;
    t.affiche();
    while(j.pos().x()!=0 || j.pos().y()!=0)
    {
        j.deplace(t);
        system("cls");
        t.affiche();
    }
}

void testRobot()
{
    terrain t{4,6};
    t.creeJoueur(type_joueur::NORMAL,1,2);
    t.creeRobot(type_robot::UN_G,3,3);
    t.remplitGrille();
    t.deplacements();
}

void testJeu()
{
    terrain t{};
    t.charge("terrains/terrain1.txt");
    t.deplacements();
    cout<<"Fin";
    getch();
}

void testEditeur()
{
    editeurTerrain edt{};
    edt.editeur();

}

int main()
{
    menu m{};
    //m.affiche();
    //testOperator();
    //testCoord();
    //testRobot();
    testJeu();
    //testEditeur();
}

