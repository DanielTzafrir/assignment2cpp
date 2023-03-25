#ifndef Card_HPP
#define Card_HPP

#include <iostream>
#include <string>
using namespace std;

namespace ariel {

class Card {

public:	
	Card(string name, int value);	
	//~Card();	
	

private:	
	string name_;
	int value_;
};

}

#endif // Card_HPP
