#include <iostream>
#include "credit_card.h"


Credit_card::Credit_card():
        limit(0) {
    balance = 0;
};

Credit_card::Credit_card(double blnc,double lmt):
        limit(lmt) {
    balance = blnc;
};

Credit_card::~Credit_card() {
    
}

void Credit_card::full_info() {
    std::cout << "Credit card info:"
              << "\tBalance: " << balance
              << "\tLimit: " << limit
              << std::endl;
}

double Credit_card::withdraw_funds(double funds) {
    if ((balance - funds) < limit) {
        std::cerr << "Credit_Card_ERROR: insufficient funds on the card" << std::endl;
        return 0;
    }
    balance -= funds;
    return balance;
}