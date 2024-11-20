#ifndef BLACK_JACK_DECK_H
#define BLACK_JACK_DECK_H

#include "card.h"
#include <vector>
#include <memory>

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
    std::vector<std::unique_ptr<Card>> cards;

    Deck();

    void shuffle();

    std::unique_ptr<Card> draw();
};
#endif //BLACK_JACK_DECK_H
