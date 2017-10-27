#ifndef HW4_CLASSES_FUNCTIONS_H
#define HW4_CLASSES_FUNCTIONS_H

#include "person_class.h"

#define MAX_LINE 255

struct List {
    int size;
    Person* persons;
};

struct List *fill_list_from_file(const char* file);

void filter_by_age(struct List* list, int age);

void filter_by_education(struct List *list);

void filter_by_gender(struct List* list);


#endif //HW4_CLASSES_FUNCTIONS_H
