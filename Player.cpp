//
//  Player.cpp
//  kazoo
//
//  Created by Nakul Khambhati on 7/8/22.
//

#include "Player.hpp"
#include <iostream>

Player::Player(bool isHero){
    
    if(isHero){
        for (int i = 0; i < 4; i++){
            m_hand[i] = nullptr;
            m_seen[i] = i/2; // sets to false, false, true, true
        }
    }
    
    else {
        for (int i = 0; i < 4; i++){
            m_hand[i] = nullptr;
            m_seen[i] = false; // sets to false, false, false, false
        }
    }
}

void Player::set(int pos, Card card){
    m_hand[pos] = new Card(card);
}

void Player::showHand() const{
    for (int i = 0; i < 4; i++){
        
        if (m_hand[i] == nullptr) std::cout << "--"; // for snapped cards
        else if (m_seen[i]) m_hand[i]->display();
        else std::cout << "??"; // for unknown cards
        
        if (i%2 == 1) std::cout << std::endl; // creates a square formation
        else std::cout << ' ';
    }
}

Card* Player::get(int pos) const{
    return m_hand[pos];
}

int Player::get_min_pos() const{ // of all cards
    
    int min_pos = 0;
    for (int i = 0; i < 4; i++){
        if (m_hand[i] != nullptr){
            if (m_hand[i]->get_value() < m_hand[min_pos]->get_value()) min_pos = i;
        }
    }
    
    return min_pos;
}

int Player::get_max_pos() const{ // of all cards
    
    int max_pos = 0;
    for (int i = 0; i < 4; i++){
        if (m_hand[i] != nullptr){
            if (m_hand[i]->get_value() > m_hand[max_pos]->get_value()) max_pos = i;
        }
    }
    
    return max_pos;
}

void Player::see(int pos){
    m_seen[pos] = true;
}

void Player::unsee(int pos){
    m_seen[pos] = false;
}

bool Player::isVisible(int pos) const{
    return m_seen[pos];
}

int Player::findVal(int val) const{ // currently only returns the positions of 1 known equivalent card
    
    for (int i = 0; i < 4; i++){
        if (m_hand[i] != nullptr){
            if (m_hand[i]->get_value() == val) return i;
        }
    }
    
    return -1; // if player doesn't have it, return -1 so that in snap's implementation, we can start by checking if it's -1
}

void Player::chuck(int pos){
    
    m_hand[pos] = nullptr;
    
}
