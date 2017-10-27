#include <cstdio>
#include <iostream>
#include <cstring>
#include <fstream>
#include "functions.h"


List * fill_list_from_file(const char* file) {

    std::ifstream f(file);
    if (!f.is_open()) {
        std::cout << "Unable to open file" << std::endl;
        return nullptr;
    }
    int size = 0;
    f >> size;
    List* persons_arr = new List;
    persons_arr->size = size;

    persons_arr->persons = new(std::nothrow) Person[size];
    if (!persons_arr->persons) {
        return nullptr;
    }

    char *last_name = new char[MAX_LINE];
    char *first_name = new char[MAX_LINE];
    char *middle_name = new char[MAX_LINE];
    int gender = 0;
    int birth_year = 0;
    char *adress = new char[MAX_LINE];
    char *education = new char[MAX_LINE];

    int counter = 0;
    while(!f.eof()) {

        f >> last_name
          >> first_name
          >> middle_name
          >> gender
          >> birth_year
          >> education
          >> adress;

        if (counter == size) {
            break;
        }
        Person *person = new Person(
                first_name,
                last_name,
                middle_name,
                gender,
                birth_year,
                education,
                adress
        );
        persons_arr->persons[counter] = *person;
        counter++;

    }

    f.close();
    return persons_arr;
}


void filter_by_age(List *list, int age) {
    std::cout << "Persons over the age of " << age << ":" <<std::endl;
    for (int i = 0; i < list->size; ++i ) {
        if ((2017 - list->persons[i].get_b_year()) > age) {
            std::cout << "\t";
            list->persons[i].show_full_name();
        }
    }
}

void filter_by_education(struct List *list) {
    std::cout << "Filter by education:"<<std::endl;
    for (int i = 0; i < list->size; ++i ) {
        if (strcmp(list->persons[i].get_education(), "hight") == 0) {
            std::cout << "\t";
            list->persons[i].show_full_name();
        }
    }
}

void filter_by_gender(struct List* list) {
    std::cout << "Filter male:"<<std::endl;
    for (int i = 0; i < list->size; ++i ) {
        if (list->persons[i].get_gender() == 1) {
            std::cout << "\t";
            list->persons[i].show_full_name();
        }
    }
}
