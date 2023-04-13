#ifndef Card_HPP
#define Card_HPP

#include <iostream>
#include <string>
using namespace std;

namespace ariel {

class Card {
public:
    enum Value { TWO=2, THREE=3, FOUR=4, FIVE=5, SIX=6, SEVEN=7, EIGHT=8, NINE=9, TEN=10, JACK=11, QUEEN=12, KING=13, ACE=14};
    enum Shape { HEARTS, DIAMONDS, CLUBS, SPADES };
    
    Card(Value value = ACE, Shape shape = HEARTS);
    
    int getValue() const;
    
    string toString() const;
    
private:
    Value value_;
    Shape shape_;
};
}

#endif // Card_HPP
