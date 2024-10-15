#include <string>
#include <utility>
#include <vector>
#include <iostream>

export module player;

import card;

using namespace std;

export struct Player {
    int score;
    string name;
    vector<Card> cards;

    Player() {
        score = 0;
        name = "Player";
    }

    explicit Player(string name) {
        score = 0;
        this->name = std::move(name);
    }

    void addCard(Card card) {
        cards.push_back(card);
    }

    void showHand() {
        cout << name << " has: ";
        for (const auto &card: cards) {
            cout << card.getCard() << " ";
        }
        cout << endl;
    }
};