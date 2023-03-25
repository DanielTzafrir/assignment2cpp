#ifndef Player_HPP
#define Player_HPP

#include <iostream>
#include <string>
using namespace std;

#include "card.hpp"

namespace ariel {

class Player {

public:
	Player(string name);	
	//Player(const string& name, int num_playable_cards=26, int num_won_cards=0, bool was_in_game=false);	
	//~Player();	
	string getName() const;
	/*int getNum_playable_cards();
	Card& operator[](int index);
    	const Card& operator[](int index) const;
	void setNum_playable_cards(int new_num);
	int getNum_won_cards();
	void setNum_won_cards(int new_num);
	bool getWas_in_game();
	void setWas_in_game(bool new_bool);
	*/	
	int stacksize();	
	int cardesTaken();

private:	
	string name_;	
	/*card* playable_cards;	
	card* won_cards;	
	int num_playable_cards;	
	int num_won_cards;	
	bool was_in_game;
	*/
};

}

#endif // Player_HPP
