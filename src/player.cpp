#include "player.h"

/**
 * @brief Constructor de la clase Player
 * @param name Nombre del jugador
 * @return Player
 * @code
 * Player player("Juan");
 * @endcode
 */
Player::Player(std::string name, bool isDealer) : name(std::move(name)) {

    hand.reserve(2);
    this->isDealer = isDealer;
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
    if (!isDealer) {// Para el jugador

        if (card.figure == Figure::ACE) {

            int option;
            std::cout << "Elige el valor del As: 1 u 11" << std::endl;
            std::cin >> option;
            while (option != 1 && option != 11) {
                std::cout << "Elige el valor del As: 1 u 11" << std::endl;
                std::cin >> option;
            }
            score += option;
        } else{
            score += card.value;
        }
    }else{// Para el dealer
        score += card.value;
    }
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
