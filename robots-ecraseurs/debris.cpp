#include "debris.h"

debris::debris(int x, int y): d_pos{x,y}
{
    //ctor
}

debris::~debris()
{
    //dtor
}


position debris::pos() const
{
    return d_pos;
}

void debris::modifie(int x, int y)
{
    d_pos.modifie(x,y);
}
