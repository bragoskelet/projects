#include "robot.h"

robot::robot(int x, int y): d_pos{x,y}
{}

robot::~robot()
{}

position robot::pos() const
{
    return d_pos;
}
bool robot::detruit() const
{
    return d_detruit;
}

void robot::collision()
{
    d_detruit=true;
}

void robot::modifie(int x, int y)
{
    d_pos.modifie(x,y);
}

void robot::decale(int dx, int dy)
{
    d_pos.decale(dx,dy);
}

void robot::arriveSur(terrain& terrain)
{
    if(terrain[pos().x()][pos().y()]==dalle::VIDE) terrain[pos().x()][pos().y()]=dalle::ROBOT;

    else if(terrain[pos().x()][pos().y()]==dalle::JOUEUR)
    {
        terrain.joueurEcrase();
        terrain[pos().x()][pos().y()]=dalle::ROBOT;
    }

    else if(terrain[pos().x()][pos().y()]==dalle::DEBRIS) collision();

    else //2 robots sur la même case
    {
        terrain[pos().x()][pos().y()]=dalle::DEBRIS;
        terrain.detruitRobots(pos());
    }
}

