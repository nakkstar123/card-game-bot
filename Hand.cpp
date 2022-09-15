//
//  Hand.cpp
//  kazoo
//
//  Created by Nakul Khambhati on 7/15/22.
//

#include "Hand.hpp"
#include "Card.hpp"
#include <iostream>

Hand::Hand(){
    m_stack = 1500;
    m_pocket[0] = nullptr;
    m_pocket[1] = nullptr;
}
Hand::~Hand(){
    delete m_pocket[0];
    delete m_pocket[1];
}
bool Hand::pay(double amt){
    if (amt > m_stack) return false;
    m_stack -= amt;
    return true;
}

void Hand::set(int pos, Card card){
    m_pocket[pos] = new Card(card);
}

void Hand::display(){
    std::cout << "Your cards are " << std::endl;
    m_pocket[0]->display();
    std::cout << " ";
    m_pocket[1]->display();
    std::cout << std::endl;
    
    std::cout << "Your stack is " << m_stack << std::endl;
    
    
}
