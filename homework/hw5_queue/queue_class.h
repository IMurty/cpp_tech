//
// Created by murt on 22.10.17.
//

#ifndef HW_5_QUEUE_CLASS_H
#define HW_5_QUEUE_CLASS_H

#include <iostream>

#define QUEUE_SIZE 100
#define NO_ERROR 1
#define RESIZE_ERROR 0

enum errortype {};

class Queue {

public:
    Queue();
    Queue(int init_capacity);
    Queue(const Queue& other_queue);
    ~Queue();
    void put(int elem);
    int get();
    int get(int index);
    int get_capacity();
    int get_size();
    friend std::ostream& operator<<(std::ostream& os, const Queue& q);
    Queue& operator=(const Queue& other_queue);


private:
    int size;
    int capacity;
    int* queue_elems;
    int resize();
};

#endif //HW_5_QUEUE_CLASS_H
