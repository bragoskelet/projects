#include "robot1G.h"
#include "terrain.h"
#include "windows.h"
#include <cmath>

robot1G::robot1G(int x, int y)
    :robot{x,y}
{}

robot1G::~robot1G()
{}

void robot1G::deplace(terrain& terrain) // Ne se déplace qu'horizontalement ou verticalement
{
    int dx = pos().x() - terrain.djoueur()->pos().x();
    int dy = pos().y() - terrain.djoueur()->pos().y();

    terrain[pos().x()][pos().y()]=dalle::VIDE;

    if(fabs(dx)>fabs(dy))
    {
        decale(-dx/fabs(dx),0);
    }

    else if(fabs(dx)<fabs(dy)) decale(0,-dy/fabs(dy));

    else if(rand()%2 == 0) decale(-dx/fabs(dx),0);

    else decale(0,-dy/fabs(dy));

    //Traitement de la case
    arriveSur(terrain);
}

void robot1G::affiche() const
{
    std::cout<<"1";
}
