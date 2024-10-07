// Librerías de nuestro proyecto
#include <iostream>
#include <random>
#include <string>
// Espacio de nombres a utilizar
using namespace std;
// Variables globales
int player = 0;
int dealer = 0;
// Mensajes del Jugador y el Dealer
string playerMessage = "Las cartas del jugador son: ";
string dealerMessage = "Las cartas del dealer son: ";
// Arreglo de cartas
int cards[52];
// Funciones
/**
 * Función que crea un deck de cartas siguiendo las reglas del blackjack,
 * es decir, las cartas del 2 al 10 valen su número, las figuras valen 10 y
 * el As vale 11. Esto se repite 4 veces para completar el deck.
 */
void createDeck() {
    // Inicializamos el valor de las cartas en 2
    int cardValue = 2;
    // Inicializamos el contador de cartas en 0
    int cardCount = 0;
    // Iteramos sobre las figuras (Corazones, Diamantes, Picas y Tréboles)
    for (int figure = 1; figure <= 4; figure++) {
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
 * Función que simula el robo de una carta
 * @return int
 */
int drawCard() {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 52);
    int card = dist(gen);
    return cards[card - 1];
}

int main() {

    createDeck();
    cout << "Carta robada: " << drawCard() << endl;
    cout << "Carta robada: " << drawCard() << endl;
    cout << "Carta robada: " << drawCard() << endl;
    cout << "Carta robada: " << drawCard() << endl;
}