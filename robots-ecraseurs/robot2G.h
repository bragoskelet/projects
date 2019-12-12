#ifndef ROBOT2G_H
#define ROBOT2G_H

#include "robot.h"

class robot2G : public robot
{
    public:
        robot2G();
        robot2G(int x, int y);
        virtual ~robot2G();

        virtual void deplace(terrain& terrain) override;
        virtual void affiche() const override;



    protected:

    private:
        position d_pos;
};

#endif // ROBOT2G_H
