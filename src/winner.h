#ifndef BLACK_JACK_WINNER_H
#define BLACK_JACK_WINNER_H

/**
 * @brief Enumerado de los posibles ganadores
 * @code
 * Winner winner = Winner::PLAYER;
 * @endcode
 */
enum Winner {
    /**
     * @brief Jugador
     * @code
     * Winner winner = Winner::PLAYER;
     * @endcode
     */
    PLAYER,
    /**
     * @brief Dealer
     * @code
     * Winner winner = Winner::DEALER;
     * @endcode
     */
    DEALER,
    /**
     * @brief Empate
     * @code
     * Winner winner = Winner::DRAW;
     * @endcode
     */
    DRAW
};

#endif