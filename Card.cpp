//
//  Card.cpp
//  kazoo
//
//  Created by Nakul Khambhati on 7/8/22.
//

#include "Card.hpp"
#include <string>
#include <iostream>

Card::Card(int val, Suit suit){
    m_suit = suit;
    m_value = val;
}

void Card::display() const{
    if( m_value >= 2 && m_value <= 9 )
          std::cout << m_value;
       else
          switch(m_value)
             
             {
             case 10:
                  std::cout << "T";
                  break;
             case jack:
                  std::cout << "J";
                  break;
             case queen:
                  std::cout << "Q";
                  break;
             case king:
                  std::cout << "K";
                  break;
             case ace:
                  std::cout << "A";
                  break;
             }
    switch(m_suit)
          {
             case clubs:
                  std::cout << "♣";
                  break;
             case diamonds:
                  std::cout << "♦";
                  break;
             case hearts:
                  std::cout << "♥";
                  break;
             case spades:
                  std::cout << "♠";
                  break;
          }
}

bool Card::isEqual(Card& other) const{
    if (this->m_value == other.m_value && this->m_suit == other.m_suit) return true;
    return false;
}

int Card::get_value() const{
    return m_value;
}
