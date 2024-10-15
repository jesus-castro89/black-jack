#include <iostream>
#include <random>
#include <string>
#include <algorithm>

import enums;
import card;
using namespace std;

/**
 * @brief Ganador del juego
 */
Winner winner;
/**
 * @brief Puntaje del jugador
 */
int player = 0;
/**
 * @brief Puntaje del dealer
 */
int dealer = 0;
/**
 * @brief Mensaje de las cartas del jugador
 */
string playerMessage = "Las cartas del jugador son: ";
/**
 * @brief Mensaje de las cartas del dealer
 */
string dealerMessage = "Las cartas del dealer son: ";
/**
 * @brief Arreglo de cartas
 */
Card cards[52]{};

/**
 * @brief Función que imprime el ganador del juego
 *
 * @code
 * printWinner();
 * @endcode
 */
void printWinner() {

    string message = winner == PLAYER ? "Haz Ganado" :
                     (winner == DEALER ? "Haz Perdido" : "Empate");
    cout << message << endl;
}

/**
 * @brief Función que crea un mazo de cartas
 *
 * @code
 * createDeck();
 * @endcode
 */
void createDeck() {

    int index = 0;
    Suite suite = HEARTS;
    for (int i = 1; i <= 4; i++) {

        switch (i) {
            case 1:
                suite = HEARTS;
                break;
            case 2:
                suite = DIAMONDS;
                break;
            case 3:
                suite = SPADES;
                break;
            case 4:
                suite = CLUBS;
                break;
        }
        for (int j = 1; j <= 13; j++) {

            switch (j) {
                case 10:
                    cards[index] = Card(suite, J);
                    break;
                case 11:
                    cards[index] = Card(suite, Q);
                    break;
                case 12:
                    cards[index] = Card(suite, K);
                    break;
                case 13:
                    cards[index] = Card(suite, A);
                    break;
                default:
                    cards[index] = Card(suite, j + 1);
                    break;
            }
            index++;
        }
    }
}

/**
 * @brief Función que mezcla el mazo de cartas
 *
 * @code
 * shuffleDeck();
 * @endcode
 */
void shuffleDeck() {

    random_device rd;
    mt19937 gen(rd());
    shuffle(begin(cards), end(cards), gen);
}

/**
 * @brief Función que saca una carta del mazo
 *
 * @code
 * int card=drawCard();
 * @endcode
 *
 * @return int La carta que se sacó del mazo
 */
Card drawCard() {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 52);
    int card = dist(gen);
    return cards[card - 1];
}

/**
 * @brief Función que suma una carta al jugador o al dealer
 *
 * @param isPlayer Booleano que indica si la carta es para el jugador o el dealer
 *
 * @code
 * plusCard(true);
 * @endcode
 *
 * @code
 * plusCard(false);
 * @endcode
 */
void plusCard(bool isPlayer) {

    Card card = drawCard();
    if (isPlayer) {

        player += card.value;
        playerMessage += " " + card.figure + card.getSuite();
    } else {
        dealer += card.value;
        dealerMessage += " " + card.figure + card.getSuite();
    }
}

/**
 * @brief Función que muestra las cartas del jugador o del dealer
 *
 * @param isPlayer Booleano que indica si se muestran las cartas del jugador o del dealer
 *
 * @code
 * showCards(true);
 * @endcode
 *
 * @code
 * showCards(false);
 * @endcode
 */
void showCards(bool isPlayer) {

    cout << ((isPlayer) ? playerMessage : dealerMessage) << endl;
}

/**
 * @brief Función que determina el ganador del juego
 */
void howIsWinner() {

    if (player > 21) {
        winner = DEALER;
    } else {
        if (player == 21) {
            winner = PLAYER;
        } else {
            winner = player > dealer ? PLAYER :
                     (player < dealer ? DEALER : DRAW);
        }
    }
}

/**
 * @brief Función que inicializa el juego
 */
void initGame() {

    createDeck();
    shuffleDeck();
    plusCard(true);
    plusCard(true);
    plusCard(false);
    plusCard(false);
    showCards(true);
    showCards(false);
}

int main() {

    initGame();
    howIsWinner();
    printWinner();
    return 0;
}