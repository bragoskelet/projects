#ifndef JOUEURNORMAL_H
#define JOUEURNORMAL_H

#include "joueur.h"

class joueurNormal: public joueur //se déplace dans les 8 directions
{
    public:
        joueurNormal(int x=0, int y=0);
        virtual ~joueurNormal();
        virtual void deplace(terrain& terrain) override;
        virtual void affiche() const override;

    protected:

    private:
};

#endif // JOUEURNORMAL_H
