#include "menu.h"

#include <cstdlib>
#include "windows.h"

using std::cout;
using std::cin;
using std::endl;

menu::menu(): d_quit{false}
{}

menu::~menu()
{}


bool menu::quit() const
{ return d_quit; }

void menu::afficheTitre() const
{
    cout<<"\n\n";
    //ligne 1
    for(int i=0; i<33; ++i) cout<<" ";
    for(int i=0; i<32; ++i)
    {
        if(i==1 || i==2 || i==3 || i==4 || i==5 || i==10 || i==17 || i==23 || i==27 || i==28 || i==29 || i==30 || i==31) cout<<"#";
        else cout<<" ";
    }
    cout<<endl;
    //ligne 2
    for(int i=0; i<33; ++i) cout<<" ";
    for(int i=0; i<32; ++i)
    {
        if(i==0 || i==9 || i==11 || i==17 ||i==23 || i==27) cout<<"#";
        else cout<<" ";
    }
    cout<<endl;
    //ligne 3
    for(int i=0; i<33; ++i) cout<<" ";
    for(int i=0; i<32; ++i)
    {
        if(i==0 || i==8 || i==12 || i==17 || i==18 || i==22 || i==23 || i==27) cout<<"#";
        else cout<<" ";
    }
    cout<<endl;
    //ligne 4
    for(int i=0; i<33; ++i) cout<<" ";
    for(int i=0; i<32; ++i)
    {
        if(i==0 || i==3 || i==4 || i==5 || i==7 || i==8 || i==9 || i==10 || i==11 || i==12 || i==13 || i==16 || i==19 || i==21 || i==24 || i==27 || i==28 || i==29 || i==30 || i==31) cout<<"#";
        else cout<<" ";
    }
    cout<<endl;
    //ligne 5
    for(int i=0; i<33; ++i) cout<<" ";
    for(int i=0; i<32; ++i)
    {
        if(i==0 || i==5 || i==7 || i==13 || i==16 || i==19 || i==21 || i==24 || i==27) cout<<"#";
        else cout<<" ";
    }
    cout<<endl;
    //ligne 6
    for(int i=0; i<33; ++i) cout<<" ";
    for(int i=0; i<32; ++i)
    {
        if(i==0 || i==5 || i==7 || i==13 || i==15 || i==20 || i==25 || i==27) cout<<"#";
        else cout<<" ";
    }
    cout<<endl;
    //ligne 7
    for(int i=0; i<33; ++i) cout<<" ";
    for(int i=0; i<32; ++i)
    {
        if(i==1 || i==2 || i==3 || i==4 || i==7 || i==13 || i==15 || i==20 || i==25 || i==27 || i==28 || i==29 || i==30 || i==31) cout<<"#";
        else cout<<" ";
    }
    cout<<"\n\n\n\n";
}

void menu::affiche()
{
    system("mode con lines=40 cols=100");
    afficheTitre();

    for(int i=0; i<46; ++i) cout<<" ";
    cout<<"(1) Jouer\n\n\n";

    for(int i=0; i<45; ++i) cout<<" ";
    cout<<"(2) Quitter\n\n\n";

    int choix=-1;

    while(choix!=2)
    {
        do
        {
            cin>>choix;
        } while(choix<1 || choix>2);

        if(choix==1)
        {
            system("cls");

        }


    }


}

void menu::run() const
{

}
