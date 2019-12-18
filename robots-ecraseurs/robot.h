#ifndef ROBOT_H
#define ROBOT_H

#include "position.h"

class terrain;

class robot
{
    public:
        robot(int x, int y);
        virtual ~robot();

        bool detruit() const;
        void collision();
        position pos() const;
        void modifie(int x, int y);
        void decale(int dx, int dy);
		void arriveSur(terrain& terrain);
		
        virtual void deplace(terrain& terrain) = 0;
        virtual void affiche() const = 0 ;

    protected:

    private:
        position d_pos;
        bool d_detruit;
};

#endif // ROBOT_H
