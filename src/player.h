#ifndef BLACK_JACK_PLAYER_H
#define BLACK_JACK_PLAYER_H

#include "card.h"
#include <vector>
#include <iostream>
#include <memory>

struct Player {

    std::string name;
    std::vector<std::unique_ptr<Card>> hand;
    int score = 0;
    bool isDealer{};

    explicit Player(std::string name, bool isDealer = true);

    void addCard(std::unique_ptr<Card> card);

    void showHand() const;
};

#endif
