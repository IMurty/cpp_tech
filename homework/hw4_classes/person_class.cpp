#include "person_class.h"
#include <iostream>


Person::Person():
        gender(0),
        birth_year(0) {

    const char none[] = "None";

    size_t len  = strlen(none) + 1;
    last_name   = new char[len];
    first_name  = new char[len];
    middle_name = new char[len];
    addres      = new char[len];
    education   = new char[len];

    memcpy(last_name, none, len);
    memcpy(first_name, none, len);
    memcpy(middle_name, none, len);
    memcpy(education, none, len);
    memcpy(addres, none, len);

};

/*===========================================================================*/

Person::Person(char *last_name_, char *first_name_, char *middle_name_,
               int gen, int b_year_,  char *edu_, char *addr_):
        gender(gen), birth_year(b_year_) {

    size_t len = strlen(last_name_) + 1;
    last_name = new char[len];
    memcpy(last_name,(const char*)last_name_, len);

    len = strlen(first_name_) + 1;
    first_name = new char[len];
    memcpy(first_name, first_name_, len);

    len = strlen(middle_name_) + 1;
    middle_name = new char[len];
    memcpy(middle_name, middle_name_, len);

    len = strlen(edu_) + 1;
    education = new char[len];
    memcpy(education, edu_, len);

    len = strlen(addr_) + 1;
    addres = new char[len];
    memcpy(addres, addr_, len);
}

/*===========================================================================*/

Person::Person(const Person &other_person):
        birth_year(other_person.birth_year),
        gender(other_person.gender) {

    if (other_person.first_name) {
        size_t len = strlen(other_person.first_name) + 1;
        first_name = new char[len];
        strncpy(first_name, other_person.first_name, len);
    }

    if (other_person.last_name) {
        size_t len = strlen(other_person.last_name) + 1;
        last_name = new char[len];
        strncpy(last_name, other_person.last_name, len);
    }

    if (other_person.middle_name) {
        size_t len = strlen(other_person.middle_name) + 1;
        middle_name = new char[len];
        strncpy(middle_name, other_person.middle_name, len);
    }

    if (other_person.addres) {
        size_t len = strlen(other_person.addres) + 1;
        addres = new char[len];
        strncpy(addres, other_person.addres, len);
    }

    if (other_person.education) {
        size_t len = strlen(other_person.education) + 1;
        education = new char[len];
        strncpy(education, other_person.education, len);
    }
}
/*===========================================================================*/


Person::~Person() {

    delete[] last_name;
    delete[] first_name;
    delete[] middle_name;
    delete[] addres;
    delete[] education;
}

/*===========================================================================*/
void  Person::set_person_info(char* last_name_, char* first_name_, char* middle_name_, int gen, int b_year, char* addr, char* edu) {

    size_t len = strlen(last_name_) + 1;
    last_name = new char[len];
    memcpy(last_name,(const char*)last_name_, len);

    len = strlen(first_name_) + 1;
    first_name = new char[len];
    memcpy(first_name, first_name_, len);

    len = strlen(middle_name_) + 1;
    middle_name = new char[len];
    memcpy(middle_name, middle_name_, len);

    len = strlen(edu) + 1;
    education = new char[len];
    memcpy(education, edu, len);

    len = strlen(addr) + 1;
    addres = new char[len];
    memcpy(addres, addr, len);
}

/*===========================================================================*/

void Person::show_person_info()
{
    std::cout << "Person information:" << std::endl;
    std::cout << "\tLast name: " << get_last_name()
              << "\n\tFirst name: "<< get_first_name()
              << "\n\tMiddle name: " << get_middle_name()
              << "\n\tGender: ";
    switch (get_gender()) {
        male: std::cout << "male";
            break;
        female: std::cout << "female";
            break;
        default: std::cout << "unknown";
            break;
    }
    std::cout << "\n\tBirth year: " << get_b_year()
              << "\n\tAddres: " << get_addres()
              << "\n\tEducation: " << education << std::endl;
}

/*===========================================================================*/
// !!!!!!!!!return const char*

void Person::show_full_name() {
    std::cout << get_last_name()   << " "
              << get_first_name()  << " "
              << get_middle_name() << std::endl;
}

/*===========================================================================*/

char* Person::get_last_name() {
    return last_name;
}

char* Person::get_first_name() {
    return first_name;
}

char* Person::get_middle_name() {
    return middle_name;
}

char* Person::get_addres() {
    return addres;
}

char* Person::get_education(){
    return education;
}

int Person::get_gender(){
    return gender;
}

int Person::get_b_year() {
    return birth_year;
}
