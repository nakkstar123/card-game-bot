//
//  Poker.cpp
//  kazoo
//
//  Created by Nakul Khambhati on 7/15/22.
//

#include "Poker.hpp"
#include "Card.hpp"
#include "Hand.hpp"

#include <iostream>

Poker::Poker() : m_pile(true){
    
    for (int i = 0; i < 2; i++){ // deal random cards from the draw pile to both of them
        m_btn.set(i, m_pile.draw());
        m_sb.set(i, m_pile.draw());
        m_bb.set(i, m_pile.draw());
    }
    
    for (int i = 0; i < 5; i++){
        m_board[i] = new Card(m_pile.draw());
        m_open[i] = false;
    }
    m_pot = 0;
    
}
void Poker::displayBoard(){
    
    for (int i = 0; i < 5; i++){
    
        if (m_open[i]) m_board[i]->display();
        else std::cout << "??"; // for unknown cards
        std::cout << ' ';
    
    } std::cout << std::endl;
}
void Poker::flop(){
    for (int i = 0; i < 3; i++){
        m_open[i] = true;
    }
}
void Poker::turn(){
    m_open[3] = true;
}
void Poker::river(){
    m_open[4] = true;
}

void Poker::open(){
    
}

void Poker::play(){
    
    displayBoard();
    Hand players[3] = {m_btn, m_sb, m_bb};
    bool inGame[3] = {true , true , true};
    
    
    // something to repeat the round until the game ends (after river betting)
//    double thisRound[3] = {0.01, 0, 0};
    double to_call = 20;
    
    for (int i = 0; i < 3; i++){
        if (!inGame[i]) break;
//        if (thisRound[0] == thisRound[1] && thisRound[1] == thisRound[2]) break;
        
        std::cout << "Player " << i+1 <<":" << std::endl;
        
        players[i].display();
        std::cout << "What would you like to do (C, F)? ";
        char n;
        std::cin >> n;
            switch(n){
                case 'C': {
                    players[i].pay(to_call);
                    m_pot += to_call;
                }
                    break;
//                case 'B': {
//                    std::cout << "What do you want to raise it to? ";
//                    double r;
//                    std::cin >> r;
//                    to_call = r;
//                    players[i].pay(to_call);
//                    m_pot += to_call;
//                }
                case 'F': {
                    inGame[i] = false;
                }
            }
    
    }
    
    flop();
    displayBoard();
    
    for (int i = 0; i < 3; i++){
        if (!inGame[i]) break;
//        if (thisRound[0] == thisRound[1] && thisRound[1] == thisRound[2]) break;
        
        std::cout << "Player " << i+1 <<":" << std::endl;
        
        players[i].display();
        std::cout << "What would you like to do (C, F)? ";
        char n;
        std::cin >> n;
            switch(n){
                case 'C': {
                    players[i].pay(to_call);
                    m_pot += to_call;
                }
                    break;
//                case 'B': {
//                    std::cout << "What do you want to raise it to? ";
//                    double r;
//                    std::cin >> r;
//                    to_call = r;
//                    players[i].pay(to_call);
//                    m_pot += to_call;
//                }
                case 'F': {
                    inGame[i] = false;
                }
            }
    
    }
    
    turn();
    displayBoard();
    
    for (int i = 0; i < 3; i++){
        if (!inGame[i]) break;
//        if (thisRound[0] == thisRound[1] && thisRound[1] == thisRound[2]) break;
        
        std::cout << "Player " << i+1 <<":" << std::endl;
        
        players[i].display();
        
        std::cout << "What would you like to do (C, F)? ";
        char n;
        std::cin >> n;
            switch(n){
                case 'C': {
                    players[i].pay(to_call);
                    m_pot += to_call;
                }
                    break;
//                case 'B': {
//                    std::cout << "What do you want to raise it to? ";
//                    double r;
//                    std::cin >> r;
//                    to_call = r;
//                    players[i].pay(to_call);
//                    m_pot += to_call;
//                }
                case 'F': {
                    inGame[i] = false;
                }
            }
    
    }
    
    river();
    displayBoard();

    
    
}

