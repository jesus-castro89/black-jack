#include "blackjack.h"
#include "deck.h"
#include <string>
#include <iostream>
#include <codecvt>

#ifdef _WIN32

#include <windows.h>
#include <fstream>

#endif

using namespace std;

int money = 100;

int *moneyPtr = &money;

BlackJack::BlackJack() {

    // Configurar la localización para UTF-8 si se está en Windows o Linux
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    // Configurar la localización para UTF-8
    std::locale::global(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    std::wcout.imbue(std::locale());
    //
    cout << "Ingrese su nombre: ";
    cin >> player.name;
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

[[nodiscard]] Winner BlackJack::getWinner() const {

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

void BlackJack::showWinner() const {

    string winner = "El ganador es: ";
    string option;
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
    cout << "¿Quieres guardar la partida? (s/n): " << endl;
    cin >> option;
    if (option == "s") {
        saveFile();
    }
}

void BlackJack::loadFile() {

    ifstream file("money.txt");
    if (file.is_open()) {
        file >> money;
        file.close();
    }
}

void BlackJack::saveFile() const {

    ofstream file("money.txt", ios::app);
    Partida partida = Partida(player.name,
                              player.score,
                              player.getHand(),
                              getWinner() == Winner::PLAYER);
    if (file.is_open()) {
        file << partida.toString() << endl;
        file.close();
    }
}