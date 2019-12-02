#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include "position.h"

class terrain;

class joueur
{
    public:
        joueur(int x=0, int y=0);
        virtual ~joueur();
        position pos() const;
        void modifie(int x, int y);
        void decale(int dx, int dy);
        virtual void deplace(terrain& terrain)=0;
        virtual void affiche() const=0;

    protected:

    private:
        position d_pos;
};

#endif // JOUEUR_H
