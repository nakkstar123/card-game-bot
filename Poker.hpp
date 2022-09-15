//
//  Poker.hpp
//  kazoo
//
//  Created by Nakul Khambhati on 7/15/22.
//

#ifndef Poker_hpp
#define Poker_hpp

#include <stdio.h>
#include "Hand.hpp"
#include "Pile.hpp"

class Card;

class Hand;

class Pile;

class Poker{
private:
    
    Hand m_btn;
    Hand m_sb;
    Hand m_bb;
    
    Pile m_pile;
    Card* m_board[5];
    bool m_open[5];
    double m_pot;
    
public:
    
    Poker();
    void displayBoard();
    void flop();
    void turn();
    void river();
    
    void open();
    
    void play();
    
};


#endif /* Poker_hpp */
