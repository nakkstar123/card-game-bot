//
//  Pile.cpp
//  kazoo
//
//  Created by Nakul Khambhati on 7/8/22.
//

#include "Pile.hpp"

Pile::Pile(bool isDraw){
    
    if (isDraw){ // for a draw pile, we want 52 shuffled cards
    
        Deck deck;
        deck.shuffle();
        for (int i = 0; i < 52; i++){
            m_pile.push(deck.get(i));
        }
    }
    
    // else leave it empty (initializing a discard pile)
}

Pile::~Pile(){
    while (!m_pile.empty()) m_pile.pop();
}

Card Pile::draw(){
    
    Card top = m_pile.top();
    m_pile.pop();
    return top;
}

void Pile::place(Card card){
    m_pile.push(card);
}

Card Pile::top(){
    return m_pile.top();
}

//int Pile::get_size(){
//    return m_pile.size();
//}
