#include <iostream>
#include <fstream>
#include "person_class.h"
#include "functions.h"

int main(int argc, const char* argv[]) {

    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " [file_name]" << std::endl;
        return 0;
    }

    List* pers_list = fill_list_from_file(argv[1]);
    if (pers_list) {
        filter_by_age(pers_list, 18);
        filter_by_education(pers_list);
        filter_by_gender(pers_list);
        delete[] pers_list->persons; // освободить list
    }
    return 0;
}