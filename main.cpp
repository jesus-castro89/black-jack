/**
 * Programa que simula el lanzamiento de un dado
 * y muestra el resultado en consola
 */
// Incluyendo librerías
#include <iostream>
#include <random>
// Espacio de nombres
using namespace std;

/**
 * Función que simula el lanzamiento de un dado
 * @return un número aleatorio entre 1 y 6
 */
int dice() {
    // Generador de números aleatorios
    random_device rd;
    // Semilla para el generador
    mt19937 gen(rd());
    // Distribución uniforme
    uniform_int_distribution<int> dist(1, 6);
    // Número aleatorio
    return dist(gen);
}

/**
 * Función principal
 */
int main() {
    int x = dice();
    // Usando if-else
    if (x == 1) {
        cout << "You rolled a 1" << endl;
    } else if (x == 2) {
        cout << "You rolled a 2" << endl;
    } else if (x == 3) {
        cout << "You rolled a 3" << endl;
    } else if (x == 4) {
        cout << "You rolled a 4" << endl;
    } else if (x == 5) {
        cout << "You rolled a 5" << endl;
    } else {
        cout << "You rolled a 6" << endl;
    }
    // Usando switch o en caso de
    switch (x) {
        case 1:
            cout << "You rolled a 1" << endl;
            break;
        case 2:
            cout << "You rolled a 2" << endl;
            break;
        case 3:
            cout << "You rolled a 3" << endl;
            break;
        case 4:
            cout << "You rolled a 4" << endl;
            break;
        case 5:
            cout << "You rolled a 5" << endl;
            break;
        default:
            cout << "You rolled a 6" << endl;
    }
    return 0;
}