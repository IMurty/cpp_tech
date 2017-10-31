#ifndef HW6_PLASTIC_CARD_H
#define HW6_PLASTIC_CARD_H


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

#endif //HW6_PLASTIC_CARD_H
