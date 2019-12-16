#ifndef DEBRIS_H
#define DEBRIS_H

#include "position.h"

class debris
{
    public:
        debris(int x, int y);
        virtual ~debris();
        position pos() const;
        void modifie(int x, int y);

    private:
        position d_pos;
};

#endif // DEBRIS_H
