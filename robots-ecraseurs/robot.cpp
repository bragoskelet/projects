#include "robot.h"

robot::robot()
{}

robot::robot(int x, int y)
    :d_pos{x,y}
{}

robot::~robot()
{}


position robot::pos() const
{
    return d_pos;
}

void robot::modifie(int x, int y)
{
    d_pos.modifie(x,y);
}

void robot::decale(int dx, int dy)
{
    d_pos.decale(dx,dy);
}

