#include "robot1G.h"
#include "terrain.h"
#include "windows.h"


robot1G::robot1G(int x, int y)
    :robot{x,y}
{}

robot1G::~robot1G()
{}

void robot1G::deplace(terrain& terrain) // Ne se déplace qu'horizontalement ou verticalement
{
<<<<<<< HEAD
    int dx = pos().x() - terrain.djoueur()->pos().x();
    int dy = pos().y() - terrain.djoueur()->pos().y();


    if(fabs(dx)>fabs(dy))
    {
        decale(dx/fabs(dx),0);
    }
    else if(fabs(dx)<fabs(dy))
            decale(0,dy/fabs(dy));
    else if(rand()%2 == 0)
            decale(dx/fabs(dx),0);
    else
            decale(0,dy/fabs(dy));

    //Traitement de la case
    arriveSur(terrain);
=======
    /* A COMPLETER
    int dx = 0;
    int dy = 0;

    if(terrain.djoueur()->pos().x() < pos.x())        //Initialisation de dx selon la posititon du joueur
    {
        d_pos.decale(-1,0);
    }
    else if(terrain.djoueur->pos.x() > pos.x())
    {
        d_pos.decale(1,0);
    }
    if(dx == 0)
    {
        if(terrain.djoueur->pos.y() < pos.y())    //Initialisation de dy selon la posititon du joueur
        {
            d_pos.decale(0,-1);
        }
        else if(terrain.djoueur->pos.y() > pos.y())
        {
            d_pos.decale(0,1);
        }
    }

    if(terrain[pos.x()][pos.y()] != dalle::VIDE)        //Vérification si collision
    {
        if(terrain[pos.x()][pos.y()] == dalle::JOUEUR)
        {
            terrain.joueurEcrase();
        }
        else if(terrain[pos().x()][pos().y()]==dalle::DEBRIS) collision();
        else if(terrain[pos().x()][pos().y()]==dalle::ROBOT)
        {
            collision();
            terrain.detruitRobots(pos());
            terrain(pos.x())
        }
    }
    else terrain[pos.x()][pos.y()] = dalle::ROBOT;      //Si case libre
    */
>>>>>>> dc1938565bb4eddca51e98fb9304471eb9167d1e
}

void robot1G::affiche() const
{
    std::cout<<"1";
}
