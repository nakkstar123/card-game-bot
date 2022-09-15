//
//  Deck.cpp
//  kazoo
//
//  Created by Nakul Khambhati on 7/8/22.
//

#include <iostream>
#include "Deck.hpp"

#include <cstdlib>
#include <ctime>

Deck::Deck(){
    
    for (int i = 0; i < 52; i++){
        m_deck[i] = new Card(i%13 + 1, Suit(i/13)); // I came up with a pretty convenient way of initializing the deck
    }
}

Deck::~Deck(){
    for (int i = 0; i < 52; i++){
        delete m_deck[i];
    }
}

void Deck::display(){
    for (int i = 0; i < 52; i++){
        m_deck[i]->display();
        
        if (i%13 == 12) std::cout << std::endl; // prints 4 lines of 13 so it's not too ugly
        else std::cout << ' ';
    }
}

void Deck::shuffle(){
    const int NUM_SWAPS = 100;
    srand(static_cast<unsigned int>(time(nullptr))); // sets random seed
    
    for (int i = 0; i < NUM_SWAPS; i++){
        
        int m = rand()%52;
        int n = rand()%52; // gets two numbers between 0 and 51
        
        Card* temp = m_deck[m];
        m_deck[m] = m_deck[n];
        m_deck[n] = temp;
        
        // swaps the cards in those respective positions
    }
    
}

Card Deck::get(int i) const{
    return *m_deck[i];
}
