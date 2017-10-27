#include <cstring>
#include "queue_class.h"
#include <limits.h>

class ostream;

Queue::Queue():
        size(0), capacity(0), queue_elems(nullptr){
};


Queue::Queue(int init_capacity):
        size(0) {
    queue_elems = new(std::nothrow) int[init_capacity];
    capacity = (!queue_elems) ? init_capacity: 0;
}


Queue::Queue(const Queue& queue):
        size(0), capacity(0) {
    queue_elems = new(std::nothrow) int[queue.capacity];
    if (queue_elems) {
        size = queue.size;
        capacity = queue.capacity;
        std::copy(queue.queue_elems, queue.queue_elems + queue.size, queue_elems);
    }
}


Queue::~Queue() {
    delete[] queue_elems;
}


int Queue::get_capacity() {
    return capacity;
}

int Queue::get_size() {
    return size;
}


int Queue::resize() {

    int* resize = new(std::nothrow) int[capacity + QUEUE_SIZE];

    if (!resize) {
        std::cerr << strerror(errno)
                  << __FILE__
                  << ": Allocation returned nullptr"
                  << std::endl;
        return RESIZE_ERROR;
    }
    std::copy(queue_elems, queue_elems + size, resize);

    delete[] queue_elems;
    queue_elems = resize;
    capacity += QUEUE_SIZE;
    return NO_ERROR;
}


void Queue::put(int elem) {

    if (size == capacity && resize() != NO_ERROR) {
            std::cerr <<__FILE__<< ": Can not put element in queue" << std::endl;
    }
    else {
        queue_elems[size++] = elem;
    }
}


int Queue::get() {
    if (size == 0) {
        std::cerr << __FILE__ << ": Size of queue = 0" << std::endl;
        return INT_MAX;
    }
    int res = *queue_elems;
    size--;
    for (int i = 0; i < size; ++i) {
        queue_elems[i] = queue_elems[i + 1];
    };
    return res;
}

int Queue::get(int index) {
//    int index = 2 * ord_num_of_odd - 1;
    if (index > 0 && index < size) {
//        return get();

        size--;

        int res = queue_elems[index];
        for (int i = index; i < size; ++i) {
            queue_elems[i] = queue_elems[i + 1];
        };
        return res;
    }
    else {
        return get();
    }

}


std::ostream& operator<<(std::ostream &os, const Queue &q) {
    os << "queue: ";
    for (int i = 0; i < q.size; ++i) {
        os << q.queue_elems[i] << " ";
    }
    os << std::endl;
    return os;
}

Queue& Queue::operator=(const Queue &other_queue) {
    if (this != &other_queue) {

        delete[] queue_elems;
        size = 0;
        capacity = 0;
        queue_elems = new(std::nothrow) int[other_queue.capacity];
        if (queue_elems) {
            size = other_queue.size;
            capacity = other_queue.capacity;
            std::copy(other_queue.queue_elems, other_queue.queue_elems + other_queue.size, queue_elems);
        }
    }
    return *this;
}
