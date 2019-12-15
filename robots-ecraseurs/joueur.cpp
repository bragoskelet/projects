#include "joueur.h"
#include "terrain.h"

joueur::joueur(int x, int y): d_pos{x,y}
{}

joueur::~joueur()
{}

position joueur::pos() const
{
    return d_pos;
}

bool joueur::estMort() const
{
    return d_mort;
}

void joueur::estEcrase()
{
    d_mort=true;
}

void joueur::modifie(int x, int y)
{
    d_pos.modifie(x,y);
}

void joueur::decale(int dx, int dy)
{
    d_pos.decale(dx,dy);
}
