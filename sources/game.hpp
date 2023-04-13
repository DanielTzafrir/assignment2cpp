#ifndef Game_HPP
#define Game_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "player.hpp"
#include "card.hpp"

namespace ariel {

class Game {

public:	
	Game(Player& p1_, Player& p2_);	
	void playTurn();
	void printLastTurn();
	void playAll();
	void printWiner();
	void printLog();
	void printStats();	
	void buildDeck();
	void endOfGame();
	void drawACard();
	void checkValues();
	string draw();
	string checkValuesNoLogUpdate();
	string stacksizeCheck();
	string statsWinToString(string player1, string player2, string card1, string card2, string winner);
	string statsDrawToString(string player1, string player2, string card1, string card2);

private:	
	Player p1, p2;
	bool Is_game_on;
	string Winner_name; 
	int num_win_p1;
	int num_win_p2;
	int num_draw;
	vector<Card> playable_cards_p1; //Holding the deck of player 1
	vector<Card> playable_cards_p2; //Holding the deck of player 2
	vector<Card> c_p1; // Holding the cards that player 1 played this turn
	vector<Card> c_p2; // Holding the cards that player 2 played this turn
	vector<string> stats_turn; // Each element in this variable holding the stats of a turn of ALL
	vector<string> stats_p1; // Each element in this variable holding the stats of a turn of player 1
	vector<string> stats_p2; // Each element in this variable holding the stats of a turn of player 2	

};

}

#endif // Game_HPP
