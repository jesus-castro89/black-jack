#include "player.h"

/**
 * @brief Constructor de la clase Player
 * @param name Nombre del jugador
 * @return Player
 * @code
 * Player player("Juan");
 * @endcode
 */
Player::Player(std::string name) : name(std::move(name)) {

    hand.reserve(2);
}

/**
 * @brief Añade una carta a la mano del jugador
 * @param card Carta a añadir
 * @return void
 * @code
 * player.addCard(card);
 * @endcode
 */
void Player::addCard(Card card) {

    hand.push_back(card);
    score += card.value;
}

/**
 * @brief Muestra la mano del jugador
 * @return void
 * @code
 * player.showHand();
 * @endcode
 */
void Player::showHand() const {

    std::string handStr = "La mano de " + name + " es: ";
    for (auto &card: hand) {
        handStr += card.getCard() + " ";
    }
    std::cout << handStr << std::endl;
}