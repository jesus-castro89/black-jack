/**
 * Enumeración de los palos de la baraja inglesa.
 */
public enum Suite {
    /**
     * Espadas.
     */
    SPADES('♠'),
    /**
     * Corazones.
     */
    HEARTS('♥'),
    /**
     * Diamantes.
     */
    DIAMONDS('♦'),
    /**
     * Tréboles.
     */
    CLUBS('♣');

    /**
     * Nombre del palo.
     */
    String suitName;
    /**
     * Símbolo del palo.
     */
    char suitSymbol;

    /**
     * Constructor de la enumeración.
     * @param symbol Símbolo del palo.
     */
    Suite(char symbol) {
        suitSymbol = symbol;
        suitName = switch (symbol) {
            case '♠' -> "Espadas";
            case '♥' -> "Corazones";
            case '♦' -> "Diamantes";
            default -> "Tréboles";
        };
    }
}
