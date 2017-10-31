#ifndef HW6_PLASTIC_CARD_H
#define HW6_PLASTIC_CARD_H

#include <cmath>

class Plastic_card {
public:
    Plastic_card();
    Plastic_card(double balance);

    virtual ~Plastic_card();
    double get_balance();
    virtual double withdraw_funds(double funds);
    virtual void full_info();

protected:

    double balance;

};


class Debit_card: public Plastic_card {
public:
    Debit_card() {

    };
    Debit_card(int blnc): Plastic_card(blnc) {

    };

};


class Credit_card: public Plastic_card {
public:
    Credit_card();
    Credit_card(double blnc, double lmt);
    double withdraw_funds(double funds);
    void full_info();
private:
    double limit;
};
#endif //HW6_PLASTIC_CARD_H
