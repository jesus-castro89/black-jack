#ifndef BLACK_JACK_BLACKJACK_H
#define BLACK_JACK_BLACKJACK_H

#include "deck.h"
#include "player.h"
#include "partida.h"
#include <string>
#include <iostream>

/**
 * Estructura que representa al juego de BlackJack.
 * Contiene un jugador, un dealer y un mazo de cartas.
 * Permite jugar, mostrar la mesa, el turno del jugador,
 * el turno del dealer, obtener el ganador y mostrarlo.
 *
 * @see Player
 * @see Deck
 * @see Winner
 *
 * @code
 * BlackJack blackJack;
 * blackJack.play();
 * @endcode
 */
struct BlackJack {

    /**
     * Jugador del juego.
     */
    Player player = Player("Jugador", false);
    /**
     * Dealer del juego.
     */
    Player dealer = Player("Dealer");
    /**
     * Mazo de cartas del juego.
     */
    Deck deck;

    /**
     * Constructor de BlackJack.
     */
    BlackJack();

    /**
     * Inicia el juego.
     */
    void play();

    /**
     * Muestra la mesa.
     */
    void showTable() const;

    /**
     * Función que representa el turno del jugador.
     */
    void playerTurn();

    /**
     * Función que representa el turno del dealer.
     */
    void dealerTurn();

    /**
     * Obtiene el ganador del juego.
     *
     * @return El ganador del juego.
     */
    [[nodiscard]] Winner getWinner() const;

    void showWinner() const;

    void loadFile();

    void saveFile() const;
};

#endif
