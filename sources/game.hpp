#ifndef Game_HPP
#define Game_HPP

#include <iostream>
#include <string>
using namespace std;

#include "player.hpp"
#include "card.hpp"

namespace ariel {

class Game {

public:	
	Game(Player p1, Player p2);	
	//~Game();
	void playTurn();
	void printLastTurn();
	void playAll();
	void printWiner();
	void printLog();
	void printStats();	


private:	
	Player p1_, p2_;	

};

}

#endif // Game_HPP
