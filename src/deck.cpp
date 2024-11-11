#include "deck.h"

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
            cards.emplace_back(suite, figure);
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
    std::shuffle(cards.begin(), cards.end(), g);
}

/**
 * @brief Roba una carta
 * @code
 * Card card = deck.draw();
 * @endcode
 * @return Card carta robada
 */
Card Deck::draw() {

    random_device rd;
    mt19937 g(rd());
    uniform_int_distribution<int> distribution(0, (int) cards.size() - 1);
    int index;
    Card card = cards[0];
    do {
        index = distribution(g);
        card = cards[index];
    } while (card.isTaken);
    card.isTaken = true;
    return card;
}
