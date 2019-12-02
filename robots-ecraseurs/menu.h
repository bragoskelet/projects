#ifndef MENU_H
#define MENU_H

#include <iostream>

class menu
{
    public:
        menu();
        virtual ~menu();
        bool quit() const;
        void afficheTitre() const;
        void affiche();
        void run() const;


    protected:

    private:
        bool d_quit;
};

#endif // MENU_H
