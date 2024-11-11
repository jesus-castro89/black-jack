#ifndef BLACK_JACK_PLAYER_H
#define BLACK_JACK_PLAYER_H

#include "card.h"
#include <string>
#include <vector>
#include <iostream>

struct Player {

    std::string name;
    std::vector<Card> hand;
    int score = 0;
    bool isDealer;

    explicit Player(std::string name, bool isDealer = true);

    void addCard(Card card);

    void showHand() const;
};

#endif
