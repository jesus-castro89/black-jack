#include "deck.h"
#include <algorithm>
#include <random>
#include <iostream>

using namespace std;

/**
 * @brief Constructor de la baraja
 * @code
 * Deck deck;
 * @endcode
 * @return Deck la baraja de cartas
 */
Deck::Deck() {

    cards.reserve(52);
    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 13; j++) {

            auto suite = static_cast<Suite>(i);
            auto figure = static_cast<Figure>(j + 2);
            cards.emplace_back(make_unique<Card>(suite, figure));
        }
    }
}

/**
 * @brief Baraja las cartas
 * @code
 * deck.shuffle();
 * @endcode
 */
void Deck::shuffle() {

    random_device rd;
    mt19937 g(rd());
    if (!cards.empty()) {

        std::shuffle(cards.begin(), cards.end(), g);
    }
}

/**
 * @brief Roba una carta
 * @code
 * Card card = deck.draw();
 * @endcode
 * @return Card carta robada
 */
unique_ptr<Card> Deck::draw() {
    random_device rd;
    mt19937 g(rd());
    uniform_int_distribution<int> distribution(0, static_cast<int>(cards.size()) - 1);
    unique_ptr<Card> card;

    while (true) {
        int index = distribution(g);
        if (index >= 0 && index < cards.size() && cards[index] != nullptr && !cards[index]->isTaken) {
            card = std::move(cards[index]);
            card->isTaken = true;
            return card;
        } else {
            cards.erase(cards.begin() + index);
        }
    }
}
