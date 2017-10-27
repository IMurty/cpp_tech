#ifndef HW4_CLASSES_PERSON_CLASS_H
#define HW4_CLASSES_PERSON_CLASS_H

#include <cstring>
enum gender {male = 1, female = 2};

class Person
{
public:
    Person();
    Person(char* last_name, char* fist_name, char* middle_name, int gender, int b_year, char* addr, char* edu);
    Person(const Person &other_person);
    ~Person();

    void  set_person_info(char* last_name, char* frist_name, char* middle_name, int gender, int b_year, char* addr, char* edu);
    //set для каждого
    void  show_person_info();
    void  show_full_name();
    char* get_first_name();
    char* get_last_name();
    char* get_middle_name();
    int   get_gender();
    int   get_b_year();
    char* get_addres();
    char* get_education();

private:
    char* last_name;
    char* first_name;
    char* middle_name;
    int   gender;
    int   birth_year;
    char* addres;
    char* education;

};

#endif //HW4_CLASSES_PERSON_CLASS_H
