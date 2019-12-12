#include "robot1G.h"
#include "terrain.h"
#include "windows.h"


robot1G::robot1G()
{}

robot1G::robot1G(int x, int y)
    :robot{x,y}
{}

robot1G::~robot1G()
{}

void robot1G::deplace(terrain& terrain) // Ne se déplace qu'horizontalement ou verticalement
{
    //IA
}

void robot1G::affiche() const
{
    std::cout<<"1";
}
