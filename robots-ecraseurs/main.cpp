#include <iostream>
#include <cstdlib>
#include "menu.h"
#include "terrain.h"
#include "joueurNormal.h"
#include "windows.h"

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
    terrain t{4,5};
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

int main()
{
    menu m{};
    //m.affiche();
    //testOperator();
    testCoord();
}
