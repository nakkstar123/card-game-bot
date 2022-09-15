//
//  HeadsUp.hpp
//  kazoo
//
//  Created by Nakul Khambhati on 8/22/22.
//

#ifndef HeadsUp_hpp
#define HeadsUp_hpp

#include <stdio.h>
#include "Card.hpp"
#include <vector>
#include <iostream>

class HeadsUp{
private:
    std::vector<Card> m_deck;
    
    std::vector<Card> m_hero;
    
    std::vector<Card> m_villain;
    
    std::vector<Card> m_community;

public:
    HeadsUp();
    
    ~HeadsUp();
    
    void shuffleDeck(int NUM_SWAPS);
    
    void displayDeck();
    
    void displayHand(const std::vector<Card> &hand);
    
    void displayHero();
    
    void displayVillain();
    
    void displayCommunity();
    
    bool compareHands(const std::vector<Card> &hand1, const std::vector<Card> &hand2);
    
    int evaluateHand(const std::vector<Card> &hand);
    
    int evaluate7Hand(const std::vector<Card> &hand, std::vector<Card> &result);
    
    bool callPreFlop(const std::vector<Card> &hand);
    
    bool heroCallPreFlop(){
        return callPreFlop(m_hero);
    }
    
    int evaluateHero(){
        std::vector<Card> useless;
        std::vector<Card> hero;
        
        for (int i = 0; i < m_community.size(); i++) hero.push_back(m_community[i]);
        for (int i = 0; i < m_hero.size(); i++) hero.push_back(m_hero[i]);
        
        return evaluate7Hand(hero, useless);
    }
    
    int playHeadsUp();
    
    std::string rankToName(int r);
    
};

inline // not sure how this works exactly
bool compareCardPtr(const Card lhs, const Card rhs)
{
    return (lhs.rank() <= rhs.rank());
}


#endif /* HeadsUp_hpp */
