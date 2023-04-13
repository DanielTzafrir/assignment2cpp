# include "game.hpp"
# include "player.hpp"
using namespace std;

namespace ariel {

Player::Player(const string& name) : name_(name), num_playable_cards_(26), num_won_cards_(0), was_in_game_(false) {}//, playable_cards(new Card[26]) {}

string Player::getName() { return name_;}

void Player::setNum_playable_cards(int new_num) { num_playable_cards_ = new_num; }
void Player::setNum_won_cards(int new_num) { num_won_cards_ = new_num; }
bool Player::getWas_in_game() { return was_in_game_; }
void Player::setWas_in_game(bool new_bool) { was_in_game_ = new_bool; }

int Player::stacksize() { return num_playable_cards_; }

int Player::cardesTaken() { return num_won_cards_; }
}


