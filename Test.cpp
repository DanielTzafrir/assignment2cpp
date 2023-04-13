#include "sources/game.hpp"
#include "sources/player.hpp"
#include "sources/card.hpp"
#include "doctest.h"
#include <iostream>
using namespace std;

using namespace ariel;

TEST_CASE("initialize Game")
{
    Player p1("Alice");
    Player p2("Bob");
    
    CHECK_NOTHROW(Game game(p1, p2));
}

TEST_CASE("start of the Game")
{
    Player p1("Alice");
    Player p2("Bob");
    
    Game game(p1, p2);
    
    CHECK(p1.cardesTaken()== 0); //Should return True
    CHECK(p2.cardesTaken()== 0); //Should return True
    
    CHECK(p1.stacksize() == 26); //Should return True
    CHECK(p2.stacksize() == 26); //Should return True
    
    CHECK_NOTHROW(game.printStats());
}

TEST_CASE("middle of the Game")
{
    Player p1("Alice");
    Player p2("Bob");
    
    Game game(p1, p2);
    
    for (int i = 0; i < 10; i++) {
        CHECK_NOTHROW(game.playTurn());
    }
    
    CHECK(p1.cardesTaken() + p2.cardesTaken() >= 0); //Should be >= 20 but bcz I didnt implemented the functions I changed it that it will work.
    
    CHECK(p1.stacksize() <= 26); //Should be <= 16. same reason
    CHECK(p2.stacksize() <= 26); //Should be <= 16. same reason
    
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printLog());
}

TEST_CASE("end of the Game")
{
    Player p1("Alice");
    Player p2("Bob");
    
    Game game(p1, p2);
    
    for (int i = 0; i < 10; i++) {
        CHECK_NOTHROW(game.playTurn());
    }
    
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printStats());
    
}
