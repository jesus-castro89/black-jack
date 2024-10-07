// Librería de entrada/salida
#include <iostream>
// Librería de elementos aleatorios
#include <random>
// Librería de manejo de cadenas de texto
#include <string>
// Agregamos std a los namespaces
using namespace std;
// Definimos las variables globales
int player, dealer, card;
string playerMessage, dealerMessage;

/**
 * Función que generará número aleatorios entre el 2
 * y el 11.
 *
 * @return Entero generado aleatoriamente en el rango dado.
 */
int drawCard() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(2, 11);
    return dist(gen);
}

void plusCardPlayer() {

    card = drawCard();
    player += card;
    playerMessage += " " + to_string(card);
}

void plusCardDealer() {

    card = drawCard();
    dealer += card;
    dealerMessage += " " + to_string(card);
}

/**
 * Función que permite agregar al jugador o la maquina el valor
 * de una carta tomada de forma aleatoria
 *
 * @param isPlayer valor Booleano que permite saber a quien se
 * sumara el valor y nombre/figura de la carta.
 */
void plusCard(bool isPlayer) {

    (isPlayer) ? plusCardPlayer() : plusCardDealer();
}

/**
 *
 *
 * @param isPlayer
 */
void printData(bool isPlayer) {

    string message = (isPlayer) ? playerMessage : dealerMessage;
    cout << message << endl;
}

void isPlayerWinner() {

    if (player > 21)
        cout << "¡Perdiste!" << endl;
    else if (player == 21)
        cout << "¡Ganaste la partida!" << endl;
}

bool playerWantCard() {

    char option;
    cout << "Deseas otra carta (y/n)" << endl;
    cin >> option;
    return option == 'y';
}

void playerTurn() {

    printData(true);
    do {
        if (!playerWantCard()) break;
        else {
            plusCard(true);
            printData(true);
            isPlayerWinner();
        }
    } while (player < 21);
}

void dealerTurn() {
    // De esta manera imprimimos la mano del dealer
    printData(false);
    string message = (dealer > player) ? "¡Perdiste!"
                                       : ((player > dealer) ? "¡Ganaste la partida!"
                                                            : "¡¡EMPATE!!");
    // Imprimimos el mensaje
    cout << message << endl;
}

void initGame() {
    // Inicializamos las variables globales
    player = 0;
    dealer = 0;
    playerMessage = "Las cartas del jugador son: ";
    dealerMessage = "Las cartas del dealer son: ";
    // Repartimos dos cartas aleatorias tanto al jugador como
    // al dealer
    plusCard(true);
    plusCard(true);
    plusCard(false);
    plusCard(false);
}

int main() {
    initGame();
    playerTurn();
    if (player < 21)
        dealerTurn();
    int d;
    cin >> d;
    (d % 3 == 0) ? cout << "Múltiplo de 3" << endl
                 : ((d % 2 == 0) ? cout << "Múltiplo de 2" << endl
                                 : cout << "No es múltiplo de 2 ni de 3" << endl);
    // if (d % 3 == 0)
    //     cout << "Múltiplo de 3" << endl;
    // else if (d % 2 == 0)
    //     cout << "Múltiplo de 2" << endl;
    // else
    //     cout << "No es múltiplo de 2 ni de 3" << endl;
    return 0;
}