//
// Created by Jesús Castro on 04/11/2024.
//

#ifndef BLACK_JACK_CARD_H
#define BLACK_JACK_CARD_H

#include "enums.h"
#include <string>

struct Card {
    int value;
    Suite suite;
    Figure figure;
    bool isTaken = false;

    explicit Card(Suite suite, Figure figure);

    [[nodiscard]] std::string getCard() const;

    [[nodiscard]] std::string getSuiteDisplay() const;
};

#endif //BLACK_JACK_CARD_H