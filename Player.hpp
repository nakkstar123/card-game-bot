//
//  Player.hpp
//  kazoo
//
//  Created by Nakul Khambhati on 7/8/22.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Card.hpp"
#include "Pile.hpp"

class Card;

class Pile;

class Player{
private:
    
    // no functionality for more than 4 cards rn (i.e. penalties)
    
    Card* m_hand[4]; // a player has an array of 4 pointers to cards (where a nullptr would indicate that the card has been snapped)
    bool m_seen[4]; // an array that knows which cards are visible to the user (hero)
    
    
public:
    
    Player(bool); // initialize either the hero or the villain (to determinewhich cards are visible)
    void set(int pos, Card card);
    void see(int pos); // makes a card visible (Ex: after discarding a 7)
    void unsee(int pos); // makes a card invisible (Ex: after villain discards a card u previously knew)
    void chuck(int pos); // sets a card in m_hand to the nullptr (after snapping)
    
    
    void showHand() const; // displays the hand, done after every move
    Card* get(int pos) const;
    int get_min_pos() const; // not used rn
    int get_max_pos() const; // used for the computer turn, returns the position of the biggest card
    bool isVisible(int pos) const;
    int findVal(int val) const; // checks if hero or villain have a card of that denomination (used in implementation of snap)

    
};

#endif /* Player_hpp */
