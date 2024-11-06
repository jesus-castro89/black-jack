#include "deck.cpp"

struct BlackJack {

    Player player = Player("Jugador");
    Player dealer = Player("Dealer");
    Deck deck;

    BlackJack() {

        deck.shuffle();
        player.addCard(deck.draw());
        player.addCard(deck.draw());
        dealer.addCard(deck.draw());
        dealer.addCard(deck.draw());
    };

    void showTable() {

        player.showHand();
        dealer.showHand();
    }

    void playerTurn() {

    }

    void dealerTurn() {

    }

    [[nodiscard]] Winner getWinner() const {

        if (player.score > 21) {
            return Winner::DEALER;
        } else {
            if (player.score == 21) {
                return Winner::PLAYER;
            } else {
                if (player.score > dealer.score) {
                    return Winner::PLAYER;
                } else if (player.score < dealer.score) {
                    return Winner::DEALER;
                } else {
                    return Winner::DRAW;
                }
            }
        }
    }

    void showWinner() const {

        string winner = "El ganador es: ";
        switch (getWinner()) {
            case Winner::PLAYER:
                winner += player.name;
                break;
            case Winner::DEALER:
                winner += dealer.name;
                break;
            case Winner::DRAW:
                winner += "Empate";
                break;
        }
        cout << winner << endl;
    }
};