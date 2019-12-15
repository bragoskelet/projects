#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include "position.h"

class terrain;

class joueur
{
    public:
        joueur(int x, int y);
        virtual ~joueur();
        position pos() const;
        bool estMort() const;
        void estEcrase();
        void modifie(int x, int y);
        void decale(int dx, int dy);
        virtual void deplace(terrain& terrain)=0;
        virtual void affiche() const=0;

    protected:

    private:
        position d_pos;
        bool d_mort; //on aurait pu si le mettre dans une autre classe dérivée abstraite pour les joueurs dans un terrain, pour que
                    //si crée un autre mode où par exemple le joueur ne peut pas mourir, on puisse hériter de joueur sans avoir une
                    //donnée inutile(mort)
};

#endif // JOUEUR_H
