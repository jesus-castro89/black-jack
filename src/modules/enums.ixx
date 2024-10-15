export module enums;
/**
 * @brief Enumeración de los ganadores
 */
export enum class Winner {
    PLAYER,
    DEALER,
    DRAW
};
/**
 * @brief Enumeración de las figuras
 */
export enum class Suite {
    HEARTS = 1,
    DIAMONDS,
    SPADES,
    CLUBS
};
/**
 * @brief Enumeración de las figuras
 */
export enum class Figure {
    J=10,
    Q,
    K,
    A,
    N
};