#include "blackjack.h"
#include "deck.h"
#include <string>
#include <iostream>

using namespace std;

int money = 100;

int* moneyPtr = &money;

BlackJack::BlackJack() {

    deck.shuffle();
    player.addCard(deck.draw());
    player.addCard(deck.draw());
    dealer.addCard(deck.draw());
    dealer.addCard(deck.draw());
    showTable();
    playerTurn();
    dealerTurn();
    showWinner();
    play();
}

void BlackJack::play() {

    string option;
    do {

        cout << "Dinero: " << money << endl;
        cout << "¿Quieres jugar otra vez? (s/n): ";
        cin >> option;
        if (option == "s") {

            deck = Deck();
            deck.shuffle();
            player.hand.clear();
            dealer.hand.clear();
            player.score = 0;
            dealer.score = 0;
            player.addCard(deck.draw());
            player.addCard(deck.draw());
            dealer.addCard(deck.draw());
            dealer.addCard(deck.draw());
            showTable();
            playerTurn();
            dealerTurn();
            showWinner();
        }
    } while (option == "s" && *moneyPtr > 0);
    cout << "Gracias por jugar" << endl;
}

void BlackJack::showTable() const {

    player.showHand();
    dealer.showHand();
}

void BlackJack::playerTurn() {

    string option;
    if (player.score < 21) {
        do {
            cout << "¿Quieres otra carta? (s/n): ";
            cin >> option;
            if (option == "s") {
                player.addCard(deck.draw());
                player.showHand();
            }
            if (player.score > 21) {
                break;
            }
        } while (option == "s");
    }
}

void BlackJack::dealerTurn() {

    while (dealer.score < 17) {
        dealer.addCard(deck.draw());
    }
    dealer.showHand();
}

[[nodiscard]] Winner BlackJack::getWinner() const{

    if (player.score > 21) {

        if (dealer.score > 21) {
            return Winner::DRAW;
        } else {
            *moneyPtr -= 10;
            return Winner::DEALER;
        }
    } else {
        if (player.score == 21 || dealer.score > 21) {
            *moneyPtr += 10;
            return Winner::PLAYER;
        } else {
            if (player.score > dealer.score) {
                *moneyPtr += 10;
                return Winner::PLAYER;
            } else if (player.score < dealer.score) {
                *moneyPtr -= 10;
                return Winner::DEALER;
            } else {
                return Winner::DRAW;
            }
        }
    }
}

void BlackJack::showWinner() {

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