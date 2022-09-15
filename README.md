# card-game-bot
Early stage prototype of a bot that plays a shedding and matching type card game and evaluates the strength of a poker hand.

## Overview

I've created 5 classes: Game, Player, Pile, Deck, Card. Since each inherits another, the structure is not too complicated.

## Topics

Card: It's basically just two data points: the card's suit and the card's denomination.

Deck: An array of 52 distinct cards with a feature to shuffle them.

Pile: It's similar to a deck but it uses a stack instead of an array and it need not contain 52 cards. The game class has 4 private members, 2 of which are piles: the draw pile and the discard pile.

Player: Represents a hand in the game. Currently, Game has 2 private member players, "hero" and "villain". The user controls "hero", while the computer controls "villain".

Game: This is the overarching class with all key functions associated with the game such as playing a turn, snapping and calling kazoo. 

Check in-line comments for detailed workings of each function. I recommended going through the header files in the order listed above. 
