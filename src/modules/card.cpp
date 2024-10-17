#include <string>
#include <utility>
#include "enums.h"

using namespace std;

struct Card {
    int value;
    Suite suite;
    Figure figure;
    bool isTaken = false;

    Card() {
        suite = Suite::HEARTS;
        figure = Figure::J;
        value = 10;
    }

    Card(Suite suite, int value) {
        this->suite = suite;
        this->value = value;
        switch (value) {
            case 11:
                this->figure = Figure::J;
                break;
            case 12:
                this->figure = Figure::Q;
                break;
            case 13:
                this->figure = Figure::K;
                break;
            case 14:
                this->figure = Figure::A;
                break;
            default:
                this->figure = Figure::N;
                break;
        }
    }

    Card(Suite suite, Figure figure) {

        this->suite = suite;
        switch (figure) {
            case Figure::J:
                this->figure = Figure::J;
                break;
            case Figure::Q:
                this->figure = Figure::Q;
                break;
            case Figure::K:
                this->figure = Figure::K;
                break;
            case Figure::A:
                this->figure = Figure::A;
                break;
            default:
                this->figure = Figure::N;
                break;
        }
        this->value = 10;
    }

    /**
     * @brief Devuelve la carta
     * @code
     * Card card = Card(Suite::HEARTS, 10);
     * getCard();
     * @endcode
     * @return string carta
     */
    [[nodiscard]] string getCard() const {

        return to_string(value) + getSuite();
    }

    /**
     * @brief Devuelve la figura de la carta
     * @code
     * Figure figure = Figure::J;
     * getFigure();
     * @endcode
     * @return string figura de la carta
     */
    [[nodiscard]] string getSuite() const {

        switch (suite) {
            case Suite::HEARTS:
                return "(C)";
            case Suite::DIAMONDS:
                return "(D)";
            case Suite::SPADES:
                return "(E)";
            case Suite::CLUBS:
                return "(T)";
        }
    }
};
