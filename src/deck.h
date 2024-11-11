#ifndef BLACK_JACK_DECK_H
#define BLACK_JACK_DECK_H

#include "card.h"
#include <vector>
#include <random>
#include <algorithm>

/**
 * @brief Clase Deck
 * @code
 * Deck deck;
 * deck.shuffle();
 * Card card = deck.draw();
 * @endcode
 */
struct Deck {

    /**
     * @brief Vector de cartas
     */
    std::vector<Card> cards;

    Deck();

    void shuffle();

    Card draw();
};
#endif //BLACK_JACK_DECK_H
