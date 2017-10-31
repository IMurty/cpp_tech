#include <iostream>
#include "cards.h"

const int cards_count = 1;


int main() {
    Plastic_card *cards[cards_count];

    //Credit cards
    std::cout << "___Credit_card___" << std::endl;
    for (int i = 0; i < cards_count; ++i) {
        Credit_card *card = new Credit_card(5000 * (i + 1), -1000 * i);
        cards[i] = card;
    }

    for (int i = 0; i < cards_count; ++i) {
        cards[i]->full_info();
        cards[i]->withdraw_funds((i + 1) * 6000);
        cards[i]->full_info();
        std::cout << "_________________" << std::endl;
    }

    //Debit cards
    std::cout << "___Debit_card___" << std::endl;
    for (int i = 0; i < cards_count; ++i) {
        Debit_card *card = new Debit_card(5000 * (i + 1));
        cards[i] = card;
    }

    for (int i = 0; i < cards_count; ++i) {
        cards[i]->full_info();
        cards[i]->withdraw_funds((i + 1) * 100000);
        cards[i]->full_info();
        std::cout << "_________________" << std::endl;
    }
//    card.full_info();
//    card.withdraw_funds(10);
//    card.full_info();
//    card.withdraw_funds(100);
//    Credit_card cr(100, -100);
//    cr.withdraw_funds(1000);
//    cr.full_info();
    return 0;
}