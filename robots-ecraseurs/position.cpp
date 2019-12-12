#include "position.h"

position::position(int x, int y): d_x{x}, d_y{y}
{}

position::position(const position &pos): d_x{pos.x()}, d_y{pos.y()}
{}

position::~position()
{}


int position::x() const
{ return d_x; }

int position::y() const
{ return d_y; }


void position::modifie(int x, int y)
{
    d_x=x;
    d_y=y;
}

void position::modifie(const position &pos)
{
    d_x=pos.x();
    d_y=pos.y();
}

void position::decale(int dx, int dy)
{
    d_x+=dx;
    d_y+=dy;
}
