#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "joueurNormal.h"
#include "joueurExpert.h"
#include "robot1G.h"
#include "robot2G.h"
#include "terrain.h"

TEST_CASE("Un joueur fonctionne bien")
{
    SUBCASE("le constructeur est correct")
    {
        int x=1, y=2;
        joueurNormal jn{x,y};
        REQUIRE_EQ(jn.pos().x(),x);
        REQUIRE_EQ(jn.pos().y(),y);
    }
}

TEST_CASE("un terrain fonction bien")
{
    SUBCASE("Le constructeur par defaut est correct")
    {
        int x=0,l=4,h=4;
        terrain t(l,h);
        for(int i=0;i<l;i++)
        {
            for (int j=0;j<h;j++)
            {
                REQUIRE_EQ(t(i,j),x);
            }
        }
    }
}

TEST_CASE("Un robot fonctionne bien")
{
    SUBCASE("Un robot de premiere generation fonctionne bien")
    {
        SUBCASE("Le constructeur est correct")
        {
            int x=1, y=2;
            robot1G r{x,y};
            REQUIRE_EQ(r.pos().x(),x);
            REQUIRE_EQ(r.pos().y(),y);
        }
    }

    SUBCASE("Un robot de seconde generation fonctionne bien")
    {
        SUBCASE("Le constructeur est correct")
        {
            int x=1, y=2;
            robot2G r{x,y};
            REQUIRE_EQ(r.pos().x(),x);
            REQUIRE_EQ(r.pos().y(),y);
        }
    }
}
