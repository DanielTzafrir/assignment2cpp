#ifndef Player_HPP
#define Player_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "card.hpp"

namespace ariel {

class Player {

public:
	Player(const string& name);				
	string getName();
	void setNum_playable_cards(int new_num);
	void setNum_won_cards(int new_num);
	bool getWas_in_game();
	void setWas_in_game(bool new_bool);		
	int stacksize();	
	int cardesTaken();

private:	
	string name_;			
	int num_playable_cards_;	
	int num_won_cards_;	
	bool was_in_game_;
	
};

}

#endif // Player_HPP
