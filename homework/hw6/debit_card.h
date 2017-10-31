#include "plastic_card.h"

#ifndef HW6_DEBIT_CARD_H
#define HW6_DEBIT_CARD_H



class Debit_card: public Plastic_card {
public:
    Debit_card() {

    };
    Debit_card(int blnc): Plastic_card(blnc) {

    };

};

#endif //HW6_DEBIT_CARD_H
