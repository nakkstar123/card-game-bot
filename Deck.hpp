//
//  Deck.hpp
//  kazoo
//
//  Created by Nakul Khambhati on 7/8/22.
//

#ifndef Deck_hpp
#define Deck_hpp

#include "Card.hpp"

class Card;

class Deck{
private:
    
    Card* m_deck[52]; // holds pointers to 52 (distinct) cards. pointers are used because they're more efficient and can be dynmaically removed but this makes the code look ugly at times
    
public:
    
    Deck(); // creates an array of 52 distinct cards in order (A - K of each suit)
    ~Deck(); // dynamically deallocates the memory
    void display(); // shows the entire deck (used for testing shuffle)
    void shuffle(); // makes 100 random swap between two cards in the deck
    Card get(int i) const; // returns the card at a certain position in the array (this should ideally return a pointer instead but this function is never really used and I'm too lazy)
    
};

#include <stdio.h>

#endif /* Deck_hpp */
