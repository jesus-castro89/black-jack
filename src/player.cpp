#include "player.h"
#include <iostream>

using namespace std;

/**
 * @brief Constructor del jugador
 * @code
 * Player player("Jugador");
 * @endcode
 * @param name nombre del jugador
 * @param isDealer si el jugador es el dealer
 * @return Player el jugador
 */
Player::Player(string name, bool isDealer) : name(std::move(name)), isDealer(isDealer) {

    hand.reserve(2);
}

/**
 * @brief Añade una carta a la mano
 * @code
 * player.addCard(card);
 * @endcode
 * @param card carta a añadir
 */
void Player::addCard(unique_ptr<Card> card) {

    if (card == nullptr) {

        cerr << "Error: Attempted to add a null card to the hand." << endl;
        return;
    }
    if (!isDealer) {

        if (card->figure == Figure::ACE) {

            int option;
            cout << "Elige el valor del As: 1 u 11:" << endl;
            cin >> option;
            while (option != 1 && option != 11) {

                cout << "Elige el valor del As: 1 u 11:" << endl;
                cin >> option;
            }
            score += option;
        } else {
            score += card->value;
        }
    } else {
        score += card->value;
    }
    hand.push_back(std::move(card));
}

/**
 * @brief Muestra la mano del jugador
 * @code
 * player.showHand();
 * @endcode
 */
void Player::showHand() const {

    string handStr = "La mano de " + name + " es: ";
    for (const auto &card: hand) {

        if (card != nullptr) {

            handStr += card->getCard() + " ";
        } else {
            cerr << "Error: Null card in hand." << endl;
        }
    }
    cout << handStr << endl;
}

/**
 * @brief Obtiene la mano del jugador
 * @code
 * string hand = player.getHand();
 * @endcode
 * @return string la mano del jugador
 */
string Player::getHand() const {

    string handStr = "La mano de " + name + " es: ";
    for (const auto &card: hand) {

        if (card != nullptr) {

            handStr += card->getCard() + " ";
        } else {
            cerr << "Error: Null card in hand." << endl;
        }
    }
    return handStr;
}