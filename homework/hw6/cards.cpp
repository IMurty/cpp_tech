#include "cards.h"
#include <iostream>

Plastic_card::Plastic_card(): balance(0) {}

Plastic_card::Plastic_card(double blnc): balance(blnc) {}

Plastic_card::~Plastic_card() {};


double Plastic_card::get_balance() {
    return balance;
}

double Plastic_card::withdraw_funds(double funds) {
    if (funds > balance) {
        std::cerr << "Plastic_Card_ERROR:\n\tinsufficient funds on the card" << std::endl;
        return 0;
    }
    return balance -= funds;
}

void Plastic_card::full_info() {
    std::cout<<"Plastic_card:\n\tBalance: "<< balance << std::endl;
}

/*
 *
 */
Credit_card::Credit_card():
        limit(0) {
    balance = 0;
};

Credit_card::Credit_card(double blnc,double lmt):
        limit(lmt) {
    balance = blnc;
};

void Credit_card::full_info() {
    std::cout << "\tBalance: " << balance
              << "\n\tLimit: " << limit
              << std::endl;
}

double Credit_card::withdraw_funds(double funds) {
    if ((balance - funds) < limit) {
        std::cerr << "Credit_Card_ERROR:\n\tinsufficient funds on the card" << std::endl;
        return 0;
    }
    balance -= funds;
    return balance;
}
