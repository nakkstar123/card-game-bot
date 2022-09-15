//
//  HeadsUp.cpp
//  kazoo
//
//  Created by Nakul Khambhati on 8/22/22.
//

#include "HeadsUp.hpp"

// maybe use a set here instead ... 

HeadsUp::HeadsUp(){
    for (int i = 0; i < 52; i++){
        Card temp(i%13 + 2, Suit(i/13)); // 2 to 14 for it to work (?)
        m_deck.push_back(temp);
    }
    
    shuffleDeck(100);
    
    for (int i = 0; i < 5; i++){
        Card temp = m_deck.back();
        
        std::vector<Card>::iterator it = m_deck.end();
        it--;
        
        m_deck.erase(it);
        
        m_community.push_back(temp);
    }
    
    for (int i = 0; i < 2; i++){
        Card temp = m_deck.back();
        
        std::vector<Card>::iterator it = m_deck.end();
        it--;
        
        m_deck.erase(it);
        
        m_hero.push_back(temp);
    }
    
    for (int i = 0; i < 2; i++){
        Card temp = m_deck.back();
        
        std::vector<Card>::iterator it = m_deck.end();
        it--;
        
        m_deck.erase(it);
        
        m_villain.push_back(temp);
    }
    
    sort(m_hero.begin(), m_hero.end(), compareCardPtr);
    sort(m_villain.begin(), m_villain.end(), compareCardPtr);
    sort(m_community.begin(), m_community.end(), compareCardPtr);
    
}

HeadsUp::~HeadsUp(){
        
    std::vector<Card>::iterator it;
    
    it = m_deck.begin();
    while (it != m_deck.end()){
        it = m_deck.erase(it);
    }
    
    it = m_hero.begin();
    while (it != m_hero.end()){
        it = m_hero.erase(it);
    }
    
    it = m_villain.begin();
    while (it != m_villain.end()){
        it = m_villain.erase(it);
    }
    
    it = m_community.begin();
    while (it != m_community.end()){
        it = m_community.erase(it);
    }
    
}

void HeadsUp::shuffleDeck(int NUM_SWAPS){
    srand(static_cast<unsigned int>(time(nullptr))); // sets random seed
    
    for (int i = 0; i < NUM_SWAPS; i++){
        
        int m = rand()%52;
        int n = rand()%52; // gets two numbers between 0 and 51
        
        Card temp = m_deck[m];
        m_deck[m] = m_deck[n];
        m_deck[n] = temp;
        
        // swaps the cards in those respective positions
    }
}

void HeadsUp::displayDeck(){
    for (int i = 0; i < m_deck.size(); i++){
        

        m_deck[i].display();
        
        if (i%13 == 12) std::cout << std::endl; // prints 4 lines of 13 so it's not too ugly
        else std::cout << ' ';
            
        
    }
}

void HeadsUp::displayHand(const std::vector<Card> &hand){
 
    for (int i = 0; i < hand.size(); i++){

        
            hand[i].display();
            
            std::cout << ' ';
            

    }
    
    std::cout << std::endl;
    
}

void HeadsUp::displayHero(){
    
    displayHand(m_hero);
    
}

void HeadsUp::displayVillain(){
    
    displayHand(m_villain);
    
}

void HeadsUp::displayCommunity(){
    
    displayHand(m_community);
    
}

bool HeadsUp::compareHands(const std::vector<Card> &hand1, const std::vector<Card> &hand2){
    
    int h = evaluateHand(hand1);
    int v = evaluateHand(hand2);
    
    if (h > v) return true;
    else if (h < v ) return false;
    
    else{ // this won't work for QQQKK vs JJJAA :/
        
        for (int i = 4; i >= 0; i--){
            
            if (hand1[i].rank() > hand2[i].rank()) return true;
            if (hand1[i].rank() < hand2[i].rank()) return false;
            
            // else continue to the next iteration of the loop
        }
        
    }
    
    // if reached here then exactly equal, just return true ig
    return true;
}


int HeadsUp::evaluateHand(const std::vector<Card> &hand){
    
    int straight,flush,three,four,full,pairs;
    int k;
    
    straight = flush = three = four = full = pairs = 0;
    
    
    k = 0;
    while (k<4 && hand[k].suit()==hand[k+1].suit())
                    k++;
                if (k==4)
                    flush = 1;
    
    
    k = 0;
    while (k<4 && hand[k].rank()==hand[k+1].rank() - 1) // doesn't coubt A2345 as a straight
                    k++;
                if (k==4)
                    straight = 1;
    
    for (int i=0;i<2;i++){
                    k = i;
                    while (k<i+3&&hand[k].rank()==hand[k+1].rank())
                        k++;
                    if (k==i+3)
                        four = 1;
                }
    
    if (!four){
                    for (int i=0;i<3;i++){
                        k = i;
                        while (k<i+2&&hand[k].rank()==hand[k+1].rank())
                            k++;
                        if (k==i+2){
                            three = 1;
                            if (i==0){
                                if (hand[3].rank()==hand[4].rank())
                                    full=1;
                            }
                            else if(i==1){
                                if (hand[0].rank()==hand[4].rank())
                                    full=1;
                            }
                            else{
                                if (hand[0].rank()==hand[1].rank())
                                    full=1;
                            }
                        }
                    }
                }
    
    
    if (straight&&flush)
                    return 9;
                else if(four)
                    return 8;
                else if(full)
                    return 7;
                else if(flush)
                    return 6;
                else if(straight)
                    return 5;
                else if(three)
                    return 4;
    
    for (k=0;k<4;k++) if (hand[k].rank()==hand[k+1].rank()) pairs++;
    

        if (pairs==2)
            return 3;
        else if(pairs)
            return 2;
        else
            return 1;
    
}

int HeadsUp::evaluate7Hand(const std::vector<Card> &hand, std::vector<Card> &result){
    
    sort(m_hero.begin(), m_hero.end(), compareCardPtr);
    sort(m_villain.begin(), m_villain.end(), compareCardPtr);
    
    // 5 community cards (1 call)
    
    
    int best_rank = 0;
    int best_rank_pos[2] = {0, 0};
    
    for (int i = 0; i < 7; i++){
        for (int j = i + 1; j < 7; j++){
            
            std::vector<Card> temp;
            for (int k = 0; k < 7; k++){
                if (k != i && k != j) temp.push_back(hand[k]);
            }
            
            sort(temp.begin(), temp.end(), compareCardPtr);
            int r = evaluateHand(temp);
            
            // if (r == best_rank) // need a function here to deal with same rank
            
            if (r > best_rank){
                
                best_rank = r;
                best_rank_pos[0] = i;
                best_rank_pos[1] = j;
                
            }
            
        }
    }
    
    
    for (int k = 0; k < 7; k++){
        if (k != best_rank_pos[0] && k != best_rank_pos[1]) result.push_back(hand[k]);
    }
    
    sort(result.begin(), result.end(), compareCardPtr);
    
    return best_rank;
    
}

int HeadsUp::playHeadsUp(){
    std::vector<Card> hand1;
    std::vector<Card> hand2;
    
    for (int i = 0; i < 5; i++) {
        hand1.push_back(m_community[i]);
        hand2.push_back(m_community[i]);
    }
    
    
    for (int i = 0; i < 2; i++) hand1.push_back(m_hero[i]);
    for (int i = 0; i < 2; i++) hand2.push_back(m_villain[i]);
    
    
    std::vector<Card> result1;
    std::vector<Card> result2;
    
    int h = evaluate7Hand(hand1, result1);
    int v = evaluate7Hand(hand2, result2);
    
    std::cout << "Hero's best: ";
    displayHand(result1);
    std::cout << rankToName(h) << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Villain's best: ";
    displayHand(result2);
    std::cout << rankToName(v) << std::endl;
    
    if (h < v) return -1;
    else if (h > v) return 1;
    else return 0;
}

std::string HeadsUp::rankToName(int r){
    switch (r) {
        case 1 :
            return "high card";
            break;
        case 2 :
            return "pair";
            break;
        case 3 :
            return "two pair";
            break;
        case 4 :
            return "trips";
            break;
        case 5 :
            return "straight";
            break;
        case 6 :
            return "flush";
            break;
        case 7 :
            return "full house";
            break;
        case 8 :
            return "quads";
            break;
        case 9 :
            return "straight flush";
            break;
            
        default:
            return "";
            break;
    }
}

bool HeadsUp::callPreFlop(const std::vector<Card> &hand){
    
    Card c1(hand[0].rank(), hand[0].suit());
    Card c2(hand[1].rank(), hand[1].suit());
    
    if (c1.rank() < 10 && c2.rank() < 10){
        int diff = c1.rank() - c2.rank();
        
        
        if (diff != -1 && diff != 1 && diff != 0) return false;
        if (c1.suit() != c2.suit()) return false;
    }
    
    // still want to reduce broadway + low off suit 
    
    return true;
    
}
