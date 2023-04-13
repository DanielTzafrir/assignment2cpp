#include <random>
#include "game.hpp"

using namespace std;

namespace ariel {

Game::Game(Player& p1_, Player& p2_) : p1(p1_), p2(p2_) {
	buildDeck();
	p1.setWas_in_game(true);
	p2.setWas_in_game(true);
	Is_game_on = true;
	num_win_p1 = 0;
	num_win_p2 = 0;
	num_draw = 0;
	
}

void Game::playTurn() {
	if (&p1 == &p2) { throw invalid_argument("Got the same player"); }
	if (p1.stacksize() > 0) { 
		
		// Call a func that draw a card from each player
		drawACard();
	
		// first case: draw 
		if (c_p1.back().getValue() == c_p2.back().getValue()) {
	
			// Call a reqursive function that return string to update the logs.
			stats_turn.push_back(statsDrawToString(p1.getName(), p2.getName(), c_p1.back().toString(), c_p2.back().toString()) + draw());
		}
		else {
		
			// Check who won
			checkValues();
		}	
	}
		
	if (p1.stacksize() == 0) { 
		endOfGame();
		return;	
	}
 }
// Reqursive function that return string to update the logs. This func is also updating all of the neccesary things for the draw
string Game::draw() {
	
	// Update the number of draws
	num_draw += 1;
	
	// If no cards left then each player get his own cards back and the game is over
	if (p1.stacksize() == 0) { 
		
		return stacksizeCheck();					
	}
	
	// Call a func that draw a card from each player. This card is upside down which means we dont care about the value
	drawACard();
	
	// We check if the stacksize is 0 for the possibilty that the cards we draw were the last cards
	if (p1.stacksize() == 0) { 
		
		return stacksizeCheck();	
	}
	
	// Call a func that draw a card from each player.
	drawACard();
	
	// Check the values of the cards to see if someone won
	if (c_p1.back().getValue() != c_p2.back().getValue()) {
	
		// Check who won
		string temp = checkValuesNoLogUpdate();
		
		// Remove the cards of each temp vectors
		c_p1.clear();
		c_p2.clear();
				
		return temp;
	}
	
	return statsDrawToString(p1.getName(), p2.getName(), c_p1.back().toString(), c_p2.back().toString()) + draw();
}

string Game::stacksizeCheck() {

	// Temp string to hold the stats. here bcz we clear the vectors before using the statsDrawToString func
	string temp = statsDrawToString(p1.getName(), p2.getName(), c_p1.back().toString(), c_p2.back().toString());
	
	
	// Update the number of cards that the players won
	p1.setNum_won_cards(p1.cardesTaken() + int(c_p1.size()));
	p2.setNum_won_cards(p2.cardesTaken() + int(c_p2.size()));
	
	// Remove the cards of each temp vectors
	c_p1.clear();
	c_p2.clear();
		
	return temp;
	
}

void Game::drawACard() {

	// Push the top cards of each player to vectors that hold the cards from each player temporarly
	c_p1.push_back(playable_cards_p1.back());
	c_p2.push_back(playable_cards_p2.back());
	
	// Remove the top cards from each player deck
	playable_cards_p1.pop_back();
	playable_cards_p2.pop_back();
	
	// Update the num of playable cards for both players
	p1.setNum_playable_cards(p1.stacksize() - 1);
	p2.setNum_playable_cards(p2.stacksize() - 1);
}

void Game::checkValues() {
	// First case: the card of player 1 have a higher value and the card of player 1 isnt ACE and the card of player 2 isnt TWO. The first part of the condition is bcz 2 > ACE
	if ((c_p1.back().getValue() == 2 && c_p2.back().getValue() == 14) || (c_p1.back().getValue() > c_p2.back().getValue() && (c_p1.back().getValue() != 14 || c_p2.back().getValue() != 2))) {
		
		// Update the number of cards that the player 1 won
		p1.setNum_won_cards(p1.cardesTaken() + int((c_p1.size() * 2)));
		
		// Push the log of the turn to stats_turn variable
		stats_turn.push_back(statsWinToString(p1.getName(), p2.getName(), c_p1.back().toString(), c_p2.back().toString(), p1.getName()));
		
		// Update the number of wins for player 1
		num_win_p1 += 1;
		
		// Remove the top cards of each temp vectors
		c_p1.clear();
		c_p2.clear();
				
	}
	
	// Second case: the card of player 2 have a higher value and the card of player 2 isnt ACE and the card of player 1 isnt TWO. The first part of the condition is bcz 2 > ACE
	else if ((c_p2.back().getValue() == 2 && c_p1.back().getValue() == 14) ||(c_p2.back().getValue() > c_p1.back().getValue() && (c_p2.back().getValue() != 14 || c_p1.back().getValue() != 2))) {
		
		// Update the number of cards that the player 2 won
		p2.setNum_won_cards(p2.cardesTaken() + int((c_p1.size() * 2)));
		
		// Push the log of the turn to stats_turn variable
		stats_turn.push_back(statsWinToString(p1.getName(), p2.getName(), c_p1.back().toString(), c_p2.back().toString(), p2.getName()));
		
		// Update the number of wins for player 1
		num_win_p2 += 1;
		
		// Remove the top cards of each temp vectors
		c_p1.clear();
		c_p2.clear();
				
	}
}

string Game::checkValuesNoLogUpdate() {
	// First case: the card of player 1 have a higher value and the card of player 1 isnt ACE and the card of player 2 isnt TWO. The first part of the condition is bcz 2 > ACE
	if ((c_p1.back().getValue() == 2 && c_p2.back().getValue() == 14) || (c_p1.back().getValue() > c_p2.back().getValue() && (c_p1.back().getValue() != 14 || c_p2.back().getValue() != 2))) {
		
		// Update the number of cards that the player 1 won
		p1.setNum_won_cards(p1.cardesTaken() + int((c_p1.size() * 2)));
		
		// Update the number of wins for player 1
		num_win_p1 += 1;
		
		// Return the log 
		return statsWinToString(p1.getName(), p2.getName(), c_p1.back().toString(), c_p2.back().toString(), p1.getName());

	}
	
	// Second case: the card of player 2 have a higher value and the card of player 2 isnt ACE and the card of player 1 isnt TWO. The first part of the condition is bcz 2 > ACE
	else {
		
		// Update the number of cards that the player 2 won
		p2.setNum_won_cards(p1.cardesTaken() + int((c_p1.size() * 2)));
		
		// Update the number of wins for player 1
		num_win_p2 += 1;
		
		// Return the log 
		return statsWinToString(p1.getName(), p2.getName(), c_p1.back().toString(), c_p2.back().toString(), p2.getName());
					
	}
}
void Game::printLastTurn() { cout << stats_turn.back() << endl; }

void Game::playAll() { 

	// Loop to play all turns
	while (p1.stacksize() > 0){
	
		playTurn();
	}
}

void Game::printWiner() { cout << Winner_name << endl; }

void Game::printLog() {
	
	cout << "Logs: " << endl;
	
	// Loop that go over all the elements in stats_turn and print them. The I is of type size_t bcz it should be non-negative to be able to be an index
	for( size_t i = 0; i < stats_turn.size(); i++) {
	
		cout << stats_turn[i] << endl;
	}
}

void Game::printStats() { 

	// Print stats of player 1
	cout << "stats player 1: " << endl;
	
	// Win rate
	if ( stats_turn.size() != 0) {
		int win_rate_p1 = int((100*double(num_win_p1))/double(stats_turn.size()));
		cout << "The win rate is: " + to_string(win_rate_p1) + "%" << endl;
	}
	
	else { cout << "The win rate is: 0%" << endl; }
	
	// Cards won
	cout << "The number of cards won: " + to_string(p1.cardesTaken()) << endl;
	
	// Print stats of player 2
	cout << "stats player 2: " << endl;
	
	// Win rate 
	if ( stats_turn.size() != 0) {
		int win_rate_p2 = int((100*double(num_win_p2))/double(stats_turn.size()));
		cout << "The win rate is: " + to_string(win_rate_p2) + "%" << endl;
	}
	
	else { cout << "The win rate is: 0%" << endl; }
	
	// Cards won
	cout << "The number of cards won: " + to_string(p2.cardesTaken()) << endl;
	
	// General information
	cout << "General information: " << endl;
	
	// Draw rate
	if ( stats_turn.size() != 0) {
		int draw_rate = (100*num_draw)/int(stats_turn.size());
		cout << "The Draw rate is: " + to_string(draw_rate) + "%" << endl;
	}
	
	else { cout << "The Draw rate is: 0%" << endl; }
	
	// Amount of turns
	cout << "The amount of turns: " + to_string(stats_turn.size()) << endl;
	// Amount of draws
	cout << "The amount of draws: " + to_string(num_draw) << endl;
}

void Game::buildDeck() {
	
	vector<Card> allCards;
	
	// Create a vector of all possible card combinations
        for (int value = Card::TWO; value <= Card::ACE; ++value) {
            for (int shape = Card::HEARTS; shape <= Card::SPADES; ++shape) {
                allCards.push_back(Card(static_cast<Card::Value>(value), static_cast<Card::Shape>(shape)));               
            }            
        }
	
        // Shuffle the vector randomly
        random_device rd;
        mt19937 gen(rd());
        shuffle(allCards.begin(), allCards.end(), gen);
        
        // Take the first 52 cards from the shuffled vector
        vector<Card> cards(allCards.begin(), allCards.begin() + 52);
	
	// Give each player a half of the deck
	vector<Card>::difference_type halfDeck = cards.size() / 2;
    	playable_cards_p1 = vector<Card>(cards.begin(), cards.begin() + halfDeck);
    	playable_cards_p2 = vector<Card>(cards.begin() + halfDeck, cards.end());
}



string Game::statsWinToString(string player1, string player2, string card1, string card2, string winner) {
    return player1 + " played " + card1 + " " + player2 + " played " + card2 + ". " + winner + " wins.";
}

string Game::statsDrawToString(string player1, string player2, string card1, string card2) {
    return player1 + " played " + card1 + " " + player2 + " played " + card2 + ". draw.";
}

void Game::endOfGame() {

	// Update Winner
	if (p1.cardesTaken() > p2.cardesTaken()) { Winner_name = p1.getName(); }
	else if (p2.cardesTaken() > p1.cardesTaken()) { Winner_name = p2.getName(); }
	else { Winner_name = "draw. no winner"; }
	
	//Update Is_game_on
	Is_game_on = false;
}

}




