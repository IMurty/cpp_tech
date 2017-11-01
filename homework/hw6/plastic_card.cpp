
#include <iostream>
#include "plastic_card.h"

Plastic_card::Plastic_card(): balance(0) {}

Plastic_card::Plastic_card(double blnc): balance(blnc) {}

Plastic_card::~Plastic_card() {
   
};


double Plastic_card::get_balance() {
    return balance;
}

double Plastic_card::withdraw_funds(double funds) {
    if (funds > balance) {
        std::cerr << "Plastic_Card_ERROR: insufficient funds on the card" << std::endl;
        return 0;
    }
    return balance -= funds;
}

// void Plastic_card::full_info() {
//     std::cout<<"Plastic_card:\tBalance: "<< balance << std::endl;
// }


