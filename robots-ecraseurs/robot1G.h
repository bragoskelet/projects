#ifndef ROBOT1G_H
#define ROBOT1G_H

#include "robot.h"

class robot1G : public robot
{
    public:
        robot1G();
        robot1G(int x, int y);
        virtual ~robot1G();

        virtual void deplace(terrain& terrain) override;
        virtual void affiche() const override;

    protected:

    private:
        position d_pos;
};

#endif // ROBOT1G_H
