//
//  Game.hpp
//  kazoo
//
//  Created by Nakul Khambhati on 7/8/22.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>

#include "Player.hpp"

class Player;

// CHECK GAME.CPP, implementations are not obvious so some arbitrary choices have been made

class Game{
private:
    Player hero;
    Player villain;
    
    Pile m_drawPile;
    Pile m_discardPile;
    
public:
    
    Game(); // construct a game with the private members and set visibilities of hero and villain
    void sneakPeak(); // the display function, uses player's showHand
    void computerTurn(); // villain makes automatic move
    void play(); // start interacting with the user, give options for moves
    void kazoo(); // end the game next turn, reveal cards and determine winner.
    void special(Card card); // based on the discarded card, hero might have special abilities
    void snap(); // if hero or villain has a denomination that has just been discarded, they can snap (preference explained in implementation)
    
};

#endif /* Game_hpp */


// draw discard pile
// special abilities
// snapping
