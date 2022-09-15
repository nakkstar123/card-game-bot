//
//  Game.cpp
//  kazoo
//
//  Created by Nakul Khambhati on 7/8/22.
//

#include "Game.hpp"
#include <iostream>


// for more players, use an array instead
Game::Game() : hero(true), villain(false), m_drawPile(true), m_discardPile(false){
    
    for (int i = 0; i < 4; i++){ // deal random cards from the draw pile to both of them
        hero.set(i, m_drawPile.draw());
        villain.set(i, m_drawPile.draw());
        
    }
}

void Game::sneakPeak(){
    
    std::cout << "Hero's hand: " << std::endl;
    hero.showHand();
    std::cout << std::endl;
    
    std::cout << "Villain's hand: " << std::endl;
    villain.showHand();
    std::cout << std::endl;
    
//    std::cout << "There are " << m_drawPile.get_size() << " remaining cards in the draw pile." << std::endl;
//    std::cout << "*****" << std::endl;
    
}

void Game::computerTurn(){ // villain's automated turn

    Card pick = m_drawPile.draw();
    int max = villain.get_max_pos();
    if (pick.get_value() < villain.get(max)->get_value()){ // replace with pick if it's smaller than max.
        Card* discard = villain.get(max);
        villain.set(max, pick);
        villain.unsee(max); // if i previously knew this position, I no longer do
        
        m_discardPile.place(*discard); // might want to make this pointer thing consistent
        std::cout << "Villain has replaced and discarded "; // add to a discard pile
        discard->display();
        std::cout << std::endl;
        std::cout << std::endl;
    }
    else{ // otherwise just discard it
        m_discardPile.place(pick);
        std::cout << "Villain has discarded "; // add to a discard pile
        pick.display();
        std::cout << std::endl;
        std::cout << std::endl;
    }
    
    this->snap(); // check for snap
    
}

void Game::special(Card card){ // jack doesn't skip rn, it's the same as queen
    int val = card.get_value();
    switch (val){
        case 7:
        case 8:{
            
            std::cout << "Which card do you want to see (1, 2, 3, 4)? ";
            int n;
            std::cin >> n;
            hero.see(n-1);
            
            break;
        }
        case 9:
        case 10:{
            
            std::cout << "Which card do you want to see (1, 2, 3, 4)? ";
            int n;
            std::cin >> n;
            villain.see(n-1);
            
            break;
        }
        case 11:
        case 12:{
            
            std::cout << "Choose a card to give (1, 2, 3, 4): ";
            int n;
            std::cin >> n;
            
            std::cout << "Choose a card to receive (1, 2, 3, 4): ";
            int m;
            std::cin >> m;
            
            // swaps cards and their visibilities
            
            Card* temp = hero.get(n-1);
            hero.set(n-1, *(villain.get(m-1)));
            villain.set(m-1, *temp);
            
            bool vis = hero.isVisible(n-1);
            if (villain.isVisible(m-1)) hero.see(n-1);
            else hero.unsee(n-1);
            
            if (vis) villain.see(m-1);
            else villain.unsee(m-1);
            
            break;
        }
        case 13:{
            
            // swaps cards and their visibilities BUT received card is made visible
            
            std::cout << "Choose a card to give (1, 2, 3, 4): ";
            int n;
            std::cin >> n;
            
            std::cout << "Choose a card to receive (1, 2, 3, 4): ";
            int m;
            std::cin >> m;
            
            Card* temp = hero.get(n-1);
            hero.set(n-1, *(villain.get(m-1)));
            villain.set(m-1, *temp);
            
            if (hero.isVisible(n-1)) villain.see(m-1);
            else villain.unsee(m-1);
            
            hero.see(n-1);
            
            break;
        }
    }
    
}

void Game::snap(){ // hero can only snap HER own seen cards, villain can snap any card. BUT villain can only snap if hero doesn't (give hero preference here)
    
    // currently, only one snap is allowed (make a loop to change this)
    
    
    int discard_val = m_discardPile.top().get_value();
    if (hero.findVal(discard_val) != -1){ // if hero has it, he snaps it
        int to_snap = hero.findVal(discard_val);
        if (hero.isVisible(to_snap)) { // if player has it but it's invisible then move on
            std::cout << "Hero snapped ";
            hero.get(to_snap)->display();
            m_discardPile.place(*(hero.get(to_snap)));
            hero.chuck(to_snap);
            std::cout << std::endl;
            std::cout << std::endl;
        }
    }
    
    else if (villain.findVal(discard_val) != -1){
        int to_snap = villain.findVal(discard_val);
        if (villain.isVisible(to_snap)) { // if its visible hero will snap villain's card (HAVENT TESTED THIS PROPERLY YET)
            
            std::cout << "Hero snapped villain's ";
            villain.get(to_snap)->display();
            m_discardPile.place(*(villain.get(to_snap)));
            villain.chuck(to_snap);
            std::cout << std::endl;
            std::cout << std::endl;
            
            // then we want to do a swap between villain's to_snap, and any of hero's cards
            
            std::cout << "Choose a card to give (1, 2, 3, 4): ";
            int n;
            std::cin >> n;
            
            Card* temp = hero.get(n-1);
            hero.set(n-1, *(villain.get(to_snap)));
            villain.set(to_snap, *temp);
            
            bool vis = hero.isVisible(n-1);
            
            if (vis) villain.see(to_snap);
            else villain.unsee(to_snap);
            
            return;
            
        }
        
        // OTHERWISE (if villain has it and hero can't see it) villain will snap.
        
        std::cout << "Villain snapped ";
        villain.get(to_snap)->display();
        m_discardPile.place(*(villain.get(to_snap)));
        villain.chuck(to_snap);
        std::cout << std::endl;
        std::cout << std::endl;
    }
        
    
}

void Game::kazoo(){
    this->computerTurn(); // let villain play once more
    
    bool win = false;
    
    int hero_sum = 0;
    int villain_sum = 0;
    
    for (int i = 0; i < 4; i++){
        if (hero.get(i) != nullptr) hero_sum += hero.get(i)->get_value();
        if (villain.get(i) != nullptr) villain_sum += villain.get(i)->get_value();
        hero.see(i);
        villain.see(i); // see everything
    } // check sum and update visibilities
    
    this->sneakPeak(); // reveal all
    
    std::cout << "Hero sums to " << hero_sum << ", villain sums to " << villain_sum << "." << std::endl;
    
    if (hero_sum < villain_sum) win = true; // determine winner
    
    if (win) std::cout << "Hero wins." << std::endl;
    else std::cout << "Hero loses." << std:: endl;
    
    
    
    exit(1);
    
}

void Game::play(){ // snap should be player specific and shouldn't be called so many times
    
    
    this->sneakPeak();
    while (true){ // only break when kazoo is called (then exit(1) called)
        
//        std::cout << std::endl;

        
        std::cout << "Would you like to continue or end the game (C/E)? ";
        char ch;
        std::cin >> ch;
        
        switch (ch) {
            case 'C': {
                
                this->computerTurn();
                
                this->sneakPeak();
                
                Card pick = m_drawPile.draw();
                
                std::cout << "You have drawn ";
                pick.display();
                std::cout << std::endl;
                std::cout << "Would you like to keep it or discard it (K/D)? ";
                char c;
                std::cin >> c;
                
                switch(c)
                      {
                          case 'K':{
                              std::cout << "Which card do you want to replace (1, 2, 3, 4)? ";
                              int n;
                              std::cin >> n;
                              
                              Card* discard = hero.get(n-1);
                              m_discardPile.place(*discard);
                              
                              std::cout << "Hero has replaced and discarded "; // add to a discard pile
                              discard->display();
                              std::cout << std::endl;
                              
                              hero.set(n-1, pick);
                              hero.see(n-1);
                              
                              this->snap();
                              
                              break;
                          }
                              
                          case 'D': {
                              m_discardPile.place(pick);
                              std::cout << "Hero has discarded "; // add to a discard pile
                              pick.display();
                              std::cout << std::endl;
                              
                              this->special(pick);
                              this->snap();
        
                              break;
                          }
                      }
            }
                this->sneakPeak();
                break;
            case 'E': {
                this->kazoo();
            }
                break;
        }
        

    }
    
}
