#include "card.hpp"

namespace ariel {

    Card::Card(Value value, Shape shape) : value_(value), shape_(shape) {}

    int Card::getValue() const {
        return value_;
    }

    string Card::toString() const {
        string valueStr;
        switch (value_) {
            case TWO: valueStr = "2"; break;
            case THREE: valueStr = "3"; break;
            case FOUR: valueStr = "4"; break;
            case FIVE: valueStr = "5"; break;
            case SIX: valueStr = "6"; break;
            case SEVEN: valueStr = "7"; break;
            case EIGHT: valueStr = "8"; break;
            case NINE: valueStr = "9"; break;
            case TEN: valueStr = "10"; break;
            case JACK: valueStr = "Jack"; break;
            case QUEEN: valueStr = "Queen"; break;
            case KING: valueStr = "King"; break;
            case ACE: valueStr = "Ace"; break;
            default: valueStr = "Unknown"; break;
        }

        string shapeStr;
        switch (shape_) {
            case HEARTS: shapeStr = "Hearts"; break;
            case DIAMONDS: shapeStr = "Diamonds"; break;
            case CLUBS: shapeStr = "Clubs"; break;
            case SPADES: shapeStr = "Spades"; break;
            default: shapeStr = "Unknown"; break;
        }

        return valueStr + " of " + shapeStr;
    }

} 

