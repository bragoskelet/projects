#include "joueur.h"
#include "terrain.h"

joueur::joueur(int x, int y): d_pos{x,y}
{
    //ctor
}

joueur::~joueur()
{
    //dtor
}

position joueur::pos() const
{
    return d_pos;
}

void joueur::modifie(int x, int y)
{
    d_pos.modifie(x,y);
}

void joueur::decale(int dx, int dy)
{
    d_pos.decale(dx,dy);
}
