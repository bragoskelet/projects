#ifndef ROBOT_H
#define ROBOT_H

#include "position.h"

class terrain;

class robot
{
    public:
        robot();
        robot(int x, int y);
        virtual ~robot();

        position pos() const;
        void modifie(int x, int y);
        void decale(int dx, int dy);

        virtual void deplace(terrain& terrain) = 0;
        virtual void affiche() const = 0 ;

    protected:

    private:
        position d_pos;
};

#endif // ROBOT_H
