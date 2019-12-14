#ifndef JOUEURNORMAL_H
#define JOUEURNORMAL_H

#include "joueur.h"

class joueurNormal: public joueur
{
    public:
        joueurNormal(int x, int y);
        virtual ~joueurNormal();

        virtual void deplace(terrain& terrain) override;
        virtual void affiche() const override;

    protected:

    private:

};

#endif // JOUEURNORMAL_H
