// Librerías de nuestro proyecto
#include <iostream>
#include <random>
#include <string>
#include <algorithm>
// Espacio de nombres a utilizar
using namespace std;
// Variables globales
// Puntajes del Jugador y el Dealer
int player = 0;
int dealer = 0;
// Mensajes del Jugador y el Dealer
string playerMessage = "Las cartas del jugador son: ";
string dealerMessage = "Las cartas del dealer son: ";
// Arreglo de cartas
int cards[52];
// Enumeración de las figuras
enum Figure {
    HEARTS = 1,
    DIAMONDS,
    SPADES,
    CLUBS
};
// Funciones
/**
 * @brief Función que crea un mazo de cartas
 *
 * @code
 * createDeck();
 * @endcode
 */
void createDeck() {
    // Inicializamos el valor de las cartas en 2
    int cardValue = 2;
    // Inicializamos el contador de cartas en 0
    int cardCount = 0;
    // Iteramos sobre las figuras (Corazones, Diamantes, Picas y Tréboles)
    for (int figure = HEARTS; figure <= CLUBS; figure++) {
        // Iteramos sobre las cartas del 2 al As
        // Siendo un total de 13 cartas
        for (int card = 1; card <= 13; card++) {
            switch (card) {
                case 10:// J
                case 11:// Q
                case 12:// K
                    cardValue = 10;
                    break;
                case 13:// A
                    cardValue = 11;
                    break;
                default:// 2 al 9
                    break;
            }
            // Guardamos el valor de la carta en el arreglo
            cards[cardCount] = cardValue;
            // Incrementamos el contador de cartas
            cardCount++;
            cardValue++;
        }
        // Reiniciamos el valor de la carta por cada figura
        cardValue = 2;
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
int drawCard() {

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

    int card = drawCard();
    if (isPlayer) {
        player += card;
        playerMessage += " " + to_string(card);
    } else {
        dealer += card;
        dealerMessage += " " + to_string(card);
    }
}

void showCards(bool isPlayer) {

    cout << ((isPlayer) ? playerMessage : dealerMessage) << endl;
}

void winner() {

    if (player > 21) {
        cout << "Haz Perdido" << endl;
    } else if (player == 21) {
        cout << "Haz Ganado" << endl;
    } else {
        if (player > dealer) {
            cout << "Haz Ganado" << endl;
        } else if (player < dealer) {
            cout << "Haz Perdido" << endl;
        } else {
            cout << "Empate" << endl;
        }
    }
}

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
    winner();
    return 0;
}