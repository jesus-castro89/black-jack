#include "card.h"
#include <string>
#include <vector>
#include <iostream>

// using namespace std; // Evitar el uso de using namespace en archivos de implementación

struct Player {

    std::string name;
    std::vector<Card> hand;
    int score = 0;

    explicit Player(std::string name) : name(std::move(name)) {

        hand.reserve(2);
    }

    void addCard(Card card) {

        hand.push_back(card);
        score += card.value;
    }

    void showHand() const {

        std::string handStr = "La mano de " + name + " es: ";
        for (auto &card: hand) {
            handStr += card.getCard() + " ";
        }
        std::cout << handStr << std::endl;
    }
};