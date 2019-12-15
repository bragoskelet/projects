#ifndef JOUEUREXPERT_H
#define JOUEUREXPERT_H

#include "joueur.h"

class joueurExpert: public joueur
{
    public:
        joueurExpert(int x, int y);
        virtual ~joueurExpert();
        virtual void deplace(terrain& terrain) override;
        virtual void affiche() const override;

    protected:

    private:

};

#endif // JOUEUREXPERT_H
