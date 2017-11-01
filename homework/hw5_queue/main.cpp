#include <iostream>
#include "queue_class.h"


void delete_elem(Queue& queue) {
    for (int i = 1; i < queue.get_size(); i++) {
        queue.get(i);
    }
}


int main() {

    Queue q;

    for (int i = 0; i < 1000; ++i) {
        q.put(i);
    }
    Queue queues[10];

    for (int i = 0; i < 10; ++i) {
        queues[i] = q;
    }

    for (int i = 0; i < 10; ++i) {
        delete_elem(queues[i]);
    }

//    for (int i = 0; i < 10; ++i) {
//        std::cout << queues[i];
//    }

    return 0;
}

