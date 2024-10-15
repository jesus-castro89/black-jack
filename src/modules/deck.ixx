export module deck;

import card;
import enums;

using namespace std;

/**
 * @brief Clase Deck
 */
export class Deck {
    Card cards[52]{};
    int index = 0;

    /**
     * @brief Constructor de la clase Deck
     */
    Deck() {
        Suite suite;
        for (int i = 1; i <= 4; i++) {

            switch (i) {

                case 1:
                    suite = Suite::HEARTS;
                    break;
                case 2:
                    suite = Suite::DIAMONDS;
                    break;
                case 3:
                    suite = Suite::SPADES;
                    break;
                default:
                    suite = Suite::CLUBS;
                    break;
            }
            for (int j = 1; j <= 13; j++) {

                if (j < 10) {

                    cards[index] = Card(suite, j + 1);
                } else {
                    cards[index] = Card(suite, static_cast<Figure>(j + 1));
                }
                index++;
            }
        }
    }
};