public class Card {
    Suite suit;
    Figure figure;
    boolean isTaken;

    public static void main(String[] args) {
        Card card = new Card(Suite.SPADES, Figure.ACE);
        System.out.println(card.showCard());
        System.out.println(card.getValue());
    }

    Card(Suite s, Figure f) {
        suit = s;
        figure = f;
    }

    String showCard() {

        return String.format("%s%c", figure.figureName, suit.suitSymbol);
    }

    int getValue() {
        return figure.figureValue;
    }

    void take() {
        isTaken = true;
    }

    boolean isTaken() {
        return isTaken;
    }
}