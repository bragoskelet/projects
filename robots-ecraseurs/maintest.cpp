#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "joueurNormal.h"
#include "joueurExpert.h"

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

