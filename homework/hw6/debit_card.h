#include "plastic_card.h"

#ifndef HW6_DEBIT_CARD_H
#define HW6_DEBIT_CARD_H



class Debit_card: public Plastic_card {
public:
    Debit_card();
    Debit_card(int blnc);
    ~Debit_card();
    void full_info();
};

#endif //HW6_DEBIT_CARD_H
