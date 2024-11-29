#ifndef BLACK_JACK_PARTIDA_H
#define BLACK_JACK_PARTIDA_H

#include <string>
#include <utility>

struct Partida {
    std::string jugador;
    int puntaje;
    std::string mano;
    bool gano;

    Partida(std::string jugador, int puntaje, std::string mano, bool gano);

    [[nodiscard]] std::string toString() const;
};

#endif //BLACK_JACK_PARTIDA_H
