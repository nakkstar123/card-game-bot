//
//  main.cpp
//  kazoo
//
//  Created by Nakul Khambhati on 7/8/22.
//

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "globals.h"

#include "Game.hpp"
#include "Poker.hpp"

#include "HeadsUp.hpp"

using namespace std;

int main() {
    
//    Game game;
//    game.play();
    
//    Poker game;
//    game.play();
    
    // random doesnt work !

    HeadsUp game;

//    game.displayDeck();
//    cout << endl;
    
    cout << "Hero: ";
    game.displayHero();

    cout << "Villain: ";
    game.displayVillain();

    cout << endl;

    cout << "Community: ";
    game.displayCommunity();

    cout << endl;

    cout << game.playHeadsUp() << endl;
    
//    cout << game.heroCallPreFlop() << endl;
    
    
    

    
//    int arr[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
//
//    for (int i = 0; i < 100; i++){
//
//
//        HeadsUp game;
//
//        int j = game.evaluateHero() - 1;
//
//        arr[j]++;
//    }
//
//    for (int i = 0; i < 9; i++){
//        cout << arr[i] << " " << endl;
//    }
//
//    cout << endl;
    
    
    return 0;
    
}
