#ifndef HW7_TEMP_LINKED_LIST_H
#define HW7_TEMP_LINKED_LIST_H

#include <iostream>
#include <cstring>
#include "linked_list.h"

const int LIMIT = 100;

template<class T>
class LinkedList;


template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};


template< typename T>
std::ostream& operator<<(std::ostream & os, const LinkedList<T> & list);

//=============================================================//


template <class T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(int lim);
    LinkedList(const LinkedList<T> & another_list);
    ~LinkedList();

    void insert(const T& value);
    bool remove();
    bool isEmpty();
    void makeEmpty();
    bool find(const T& value);
    void print_sort();

    LinkedList<T> operator + (const LinkedList<T> & list);
    LinkedList<T> & operator = (const LinkedList<T> & list);


private:
    Node<T> *head;
    Node<T> *tail;
    int len;
    int limit;
    void deepCopy (const LinkedList<T> & original);
    friend std::ostream& operator << <T>(std::ostream & os, const LinkedList<T> & list);

};

//------------------------------------------------------//

template <class T>
LinkedList<T>::LinkedList()
        : head(nullptr), tail(nullptr), len(0), limit(LIMIT) {}

template <class T>
LinkedList<T>::LinkedList(int lim)
        : head(nullptr), tail(nullptr), len(0), limit(lim) {}


template <class T>
LinkedList<T>::LinkedList (const LinkedList<T> & another_list) {
    deepCopy( another_list );
}


template <class T>
LinkedList<T>::~LinkedList() {
    makeEmpty();
}

//------------------------------------------------------//

template <class T>
void LinkedList<T>::deepCopy( const LinkedList<T> & original ) {
    head = tail = nullptr;
    if ( original.head == nullptr )
        return;

    Node<T> *copy_ptr = head = new Node<T>;
    Node<T> *original_ptr = original.head;
    copy_ptr->data = original_ptr->data;

    if ( original_ptr == original.tail )
        tail = copy_ptr;
    while ( original_ptr->next != nullptr ) {
        original_ptr = original_ptr->next;
        copy_ptr->next = new Node<T>;
        copy_ptr = copy_ptr->next;
        copy_ptr->data = original_ptr->data;
        if ( original_ptr == original.tail )
            tail = copy_ptr;
    }
    copy_ptr->next = nullptr;
    len = original.len;
    limit = original.limit;
}

//------------------------------------------------------//

template <class T>
void LinkedList<T>::makeEmpty() {
    while (head)
    {
        tail = head->next;
        delete head;
        head = tail;
    }
    len = 0;
}

//------------------------------------------------------//

//inserts at the beginning of the linked list
template <class T>
void LinkedList<T>::insert(const T& value) {
    if (len != limit) {
        Node<T> *node = new Node<T>;
        node->data = value;
        node->next = head;
        head = node;
        len += 1;
    }
    else {
        throw(1);
    }

}



template <class T>
bool LinkedList<T>::find(const T& parameter) {
    Node<T> *node = head;
    while (node->next != nullptr)
    {
        if (node->data == parameter)
            return true;
        node = node->next;
    }
    return false;
}

template <class T>
bool LinkedList<T>::remove() {
    if (head == nullptr && tail == nullptr) {
        return false;
    }
    else {
        Node<T>* temp;

        temp = head;
        head = head->next;
        delete(temp);
        len -= 1;

        return true;
    }
}
//======================================================//

template <class T>
LinkedList<T> & LinkedList<T>::operator = (const LinkedList<T> & list) {
    if (this == &list)
        return *this;
    makeEmpty();
    deepCopy (list);
    return *this;
}

//------------------------------------------------------//
template <class T>
LinkedList<T> LinkedList<T>::operator+(const LinkedList<T> &list_2) {
    LinkedList<T> new_list;
    Node<T> *temp = this->head;
    while(temp) {
        new_list.insert(temp->data);
        temp = temp->next;
    }
    temp = list_2.head;
    while(temp) {
        new_list.insert(temp->data);
        temp = temp->next;
    }
    return new_list;
}


template<class T>
void LinkedList<T>::print_sort(){
    Node<T>* ptr = head;
    Node<T>* tmp = nullptr;
    Node<T>* prev = nullptr;
    bool flag = false;
    if(head) {
        do {
            flag = false;
            ptr = head;
            while(ptr->next) {
                if(ptr->data > ptr->next->data) {
                    if(ptr == head)
                    {
                        tmp = ptr;
                        ptr = tmp->next;
                        tmp->next = ptr->next;
                        ptr->next = tmp;
                        head = ptr;
                        flag = true;
                    }
                    else {
                        tmp = ptr;
                        ptr = tmp->next;
                        tmp->next = ptr->next;
                        ptr->next = tmp;
                        prev->next = ptr;
                        flag = true;
                    }
                }
                prev = ptr;
                ptr = ptr->next;
            }
        }
        while(flag);
        std::cout << "Sorted:" << *this << '\n' << std::endl;
    }
    else

        std::cout << "Nothing to sort" << std::endl;
};

//=====================================================//

template< typename T>
std::ostream& operator<<(std::ostream & os, const LinkedList<T> & list) {
    Node<T> *node = list.head;

    while (node != nullptr) {
        os << node->data << ", ";
        node = node->next;
    }
    return os;
}

//=========================================================//

template <>
class LinkedList<char*>;

//=========================================================//
#endif //HW7_TEMP_LINKED_LIST_H
