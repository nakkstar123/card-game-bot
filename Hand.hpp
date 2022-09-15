//
//  Hand.hpp
//  kazoo
//
//  Created by Nakul Khambhati on 7/15/22.
//

#ifndef Hand_hpp
#define Hand_hpp

#include <stdio.h>
#include "Card.hpp"

class Card;

class Hand{
private:
    Card* m_pocket[2];
    double m_stack;
    
public:
    Hand();
    ~Hand();
    bool pay(double amt);
    void set(int pos, Card card);
    void display();
};


#endif /* Hand_hpp */
