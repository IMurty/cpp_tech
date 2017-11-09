#include <iostream>
#include "linked_list.h"


int main() {
//    LinkedList<char *> list_check;

    int limit = 9;
    LinkedList<int> list_i = LinkedList<int>(limit);
    for (int i = 0; i < 10; ++i) {
        try {
            list_i.insert(rand() % 100);
        }
        catch (...) {
            std::cout << "Can't add elem" << std::endl;
        }
    }

    std::cout << list_i << std::endl;
    LinkedList<float> list_f;
    for (int i = 0; i < 10; ++i) {
        try {
            list_f.insert(rand() % 100 / 3.0);
        }
        catch (...) {
            std::cout << "Can't add elem" << std::endl;
        }


    }
    std::cout << list_f << std::endl;


    LinkedList<int> arr_i[2];
    for (int i = 0; i < 2; ++i) {
        arr_i[i] = list_i;
        arr_i[i].print_sort();
    }


    LinkedList<float> arr_f[2];
    for (int i = 0; i < 2; ++i) {
        arr_f[i] = list_f;
        arr_f[i].print_sort();
    }


    return 0;
}