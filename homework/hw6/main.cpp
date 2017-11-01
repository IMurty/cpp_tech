#include <iostream>
#include "plastic_card.h"
#include "credit_card.h"
#include "debit_card.h"

const int cards_count = 4;


int main() {
    Plastic_card **cards = new Plastic_card* [cards_count];

    //Credit cards
    std::cout << ">> Credit_cards:" << std::endl;
    for (int i = 0; i < cards_count; ++i) {
        cards[i] = new Credit_card(5000 * (i + 1), -1000 * i);
    }

    for (int i = 0; i < cards_count; ++i) {
        cards[i]->full_info();
        cards[i]->withdraw_funds((i + 1) * 4000);
        cards[i]->full_info();
        std::cout << "_________________" << std::endl;
    }

    //Debit cards
    std::cout << ">> Debit_cards:" << std::endl;
    for (int i = 0; i < cards_count; ++i) {
        delete cards[i];
        cards[i] = new Debit_card(5000 * (i + 1));
    }

    for (int i = 0; i < cards_count; ++i) {
        cards[i]->full_info();
        cards[i]->withdraw_funds((i + 1) * 100000);
        cards[i]->full_info();
        std::cout << "_________________" << std::endl;
    }

    for (int i = 0; i < cards_count; ++i) {
        delete cards[i];
    }
    delete[] cards; // delete для каждого
    return 0;
}