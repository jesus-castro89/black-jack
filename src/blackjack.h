#ifndef BLACK_JACK_BLACKJACK_H
#define BLACK_JACK_BLACKJACK_H

#include "deck.h"
#include "player.h"
#include <string>
#include <iostream>

struct BlackJack {

    Player player = Player("Jugador");
    Player dealer = Player("Dealer");
    Deck deck;

    BlackJack();

    void showTable() const;

    void playerTurn();

    void dealerTurn();

    [[nodiscard]] Winner getWinner() const;

    void showWinner() const;
};

#endif
