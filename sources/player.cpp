# include "game.hpp"
# include "player.hpp"
using namespace std;

namespace ariel {

Player::Player(string name) : name_(name) {}

int Player::stacksize() { return 26; }

int Player::cardesTaken() { return 0; }
}
