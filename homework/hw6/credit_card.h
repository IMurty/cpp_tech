#include "plastic_card.h"

#ifndef HW6_CREDIT_CARD_H
#define HW6_CREDIT_CARD_H


class Credit_card: public Plastic_card {
public:
    Credit_card();
    Credit_card(double blnc, double lmt);
    ~Credit_card();
    double withdraw_funds(double funds);
    void full_info();
private:
    double limit;
};

#endif //HW6_CREDIT_CARD_H
