#include "robot2G.h"
#include "terrain.h"
#include "windows.h"

robot2G::robot2G()
{}

robot2G::robot2G(int x,int y)
    :robot{x,y}
{}

robot2G::~robot2G()
{}

void robot2G::deplace(terrain& terrain) // Se déplace horizontalement, verticalement ou en diagonale
{
    //IA
}

void robot2G::affiche() const
{
    std::cout<<"2";
}
