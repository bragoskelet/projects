#ifndef ROBOT_H
#define ROBOT_H

#include "position.h"

class robot
{
    public:
        robot();
        virtual ~robot();

    protected:

    private:
        position d_pos;
};

#endif // ROBOT_H
