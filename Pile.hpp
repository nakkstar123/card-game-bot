//
//  Pile.hpp
//  kazoo
//
//  Created by Nakul Khambhati on 7/8/22.
//

#ifndef Pile_hpp
#define Pile_hpp

#include <stdio.h>
//#include <iostream>
#include "Deck.hpp"
#include<stack>

class Deck;

class Pile{
private:
    
    std::stack<Card> m_pile;
    
public:
    
    Pile(bool); // the constructor takes in a bool to determine whether it should create a draw pile or a discard pile (check Game's private members)
    ~Pile();
    Card draw(); // removes the top card and returns it
    void place(Card card); // adds a card to the top
    Card top(); // returns the card at the top without removing it (used in the discard pile to determine whether or not to snap)

    
};

#endif /* Pile_hpp */
