#ifndef BLACK_JACK_FIGURE_H
#define BLACK_JACK_FIGURE_H

/**
 * @brief Enumerado de las figuras de la baraja
 * @code
 * Figure figure = Figure::JACK;
 * @endcode
 */
enum class Figure {
    /**
     * @brief Dos
     * @code
     * Figure figure = Figure::TWO;
     * @endcode
     */
    TWO = 2,
    /**
     * @brief Tres
     * @code
     * Figure figure = Figure::THREE;
     * @endcode
     */
    THREE,
    /**
     * @brief Cuatro
     * @code
     * Figure figure = Figure::FOUR;
     * @endcode
     */
    FOUR,
    /**
     * @brief Cinco
     * @code
     * Figure figure = Figure::FIVE;
     * @endcode
     */
    FIVE,
    /**
     * @brief Seis
     * @code
     * Figure figure = Figure::SIX;
     * @endcode
     */
    SIX,
    /**
     * @brief Siete
     * @code
     * Figure figure = Figure::SEVEN;
     * @endcode
     */
    SEVEN,
    /**
     * @brief Ocho
     * @code
     * Figure figure = Figure::EIGHT;
     * @endcode
     */
    EIGHT,
    /**
     * @brief Nueve
     * @code
     * Figure figure = Figure::NINE;
     * @endcode
     */
    NINE,
    /**
     * @brief Diez
     * @code
     * Figure figure = Figure::TEN;
     * @endcode
     */
    TEN,
    /**
     * @brief Jota
     * @code
     * Figure figure = Figure::JACK;
     * @endcode
     */
    JACK,
    /**
     * @brief Reina
     * @code
     * Figure figure = Figure::QUEEN;
     * @endcode
     */
    QUEEN,
    /**
     * @brief Rey
     * @code
     * Figure figure = Figure::KING;
     * @endcode
     */
    KING,
    /**
     * @brief As
     * @code
     * Figure figure = Figure::ACE;
     * @endcode
     */
    ACE
};

#endif