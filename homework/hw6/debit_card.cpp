#include <iostream>
#include "debit_card.h"

Debit_card::Debit_card() {

};

Debit_card::Debit_card(int blnc): Plastic_card(blnc) {

};

Debit_card::~Debit_card() {

};

void Debit_card::full_info() {
    std::cout << "Debit card info:"
    << "\tBalance: " << balance
    << std::endl;
};