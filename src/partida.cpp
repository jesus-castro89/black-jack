#include "partida.h"

using namespace std;

Partida::Partida(string jugador, int puntaje, string mano, bool gano) {

    this->jugador = move(jugador);
    this->puntaje = puntaje;
    this->mano = move(mano);
    this->gano = gano;
}

string Partida::toString() const {

    return "Jugador: " + jugador + ", Puntaje: "
           + to_string(puntaje)
           + "\nMano: " + mano + ", Gano: "
           + (gano ? "Si" : "No");
}