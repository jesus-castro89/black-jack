#ifndef BLACK_JACK_SUITE_H
#define BLACK_JACK_SUITE_H

/**
 * @brief Enumerado para los palos de la baraja
 * @code
 * Suite suite = Suite::HEARTS;
 * @endcode
 */
enum class Suite {
    /**
     * @brief Corazones
     * @code
     * Suite suite = Suite::HEARTS;
     * @endcode
     */
    HEARTS,
    /**
     * @brief Diamantes
     * @code
     * Suite suite = Suite::DIAMONDS;
     * @endcode
     */
    DIAMONDS,
    /**
     * @brief Tréboles
     * @code
     * Suite suite = Suite::CLUBS;
     * @endcode
     */
    CLUBS,
    /**
     * @brief Picas
     * @code
     * Suite suite = Suite::SPADES;
     * @endcode
     */
    SPADES
};

#endif