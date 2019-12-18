#include "robot2G.h"
#include "terrain.h"
#include "windows.h"
#include <cmath>

robot2G::robot2G(int x,int y): robot{x,y}
{}

robot2G::~robot2G()
{}

void robot2G::deplace(terrain& terrain) // Se déplace horizontalement, verticalement ou en diagonale.
{
    int dx=pos().x() - terrain.djoueur()->pos().x();
    int dy=pos().y() - terrain.djoueur()->pos().y();

    terrain[pos().x()][pos().y()]=dalle::VIDE;
    //déplacement
    if(dx!=0 && dy!=0) //alors il faut se deplacer en X et en Y (en diagonale)
    {
        decale(dx/fabs(dx),dy/fabs(dy));
    }

    else //deplacement soit horizontal soit vertical
    {
        if(dx==0) decale(0,dy/fabs(dy)); //on ne deplace que d'une case, et /fabs(y) conserve le signe de dy: pour haut ou bas.
        else decale(dx/fabs(dx),0);     // idem pour dx, la division vaut 1 ou -1.
    }

    //traitement de la case
    arriveSur(terrain);
}

void robot2G::affiche() const
{
    std::cout<<"2";
}
