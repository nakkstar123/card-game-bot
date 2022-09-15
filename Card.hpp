//
//  Card.hpp
//  kazoo
//
//  Created by Nakul Khambhati on 7/8/22.
//

#ifndef Card_hpp
#define Card_hpp

#include "globals.h"

#include <stdio.h>

class Card{
    
private:
    Suit m_suit; // Suit is something called an "enum" which is basically just an array of the 4 different suits
    int m_value;
public:
    Card(int, Suit); // constructing a card requires specifying its value
//    void set();
    
    void display() const; // displays the card's value. Ex: A♦
    bool isEqual(Card& other) const; // checks if two cards are identical (not used after a deck is created)
    int get_value() const; // returns the denomination of a card
    
    int rank() const {return m_value;}
    Suit suit() const {return m_suit;}
    
    bool operator<=(const Card &c){
        return (m_value <= c.m_value);
    }
    
};

#endif /* Card_hpp */
