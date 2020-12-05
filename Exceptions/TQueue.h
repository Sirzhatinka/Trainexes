//
// Created by mazur on 02.12.2020.
//

#ifndef EXCEPTIONS_TEMPLQUEUE_H
#define EXCEPTIONS_TEMPLQUEUE_H

#include <iostream>
const int SZ = 5;
template<class T> class Queue {
    T q[SZ];
    int head, tail;
    bool cycling;
public:
    Queue(): head(0), tail(0), cycling(false) { }

    class Excep {
    public:
        explicit Excep(int i): index(i) { }
        int index;
    };

    void setData(T d) {
        if (tail == SZ && head == 0)
            throw Excep(tail);
        else if (tail == SZ) {
            tail = 0;
            cycling = true;
        }
        if (head == tail && cycling)
            throw Excep(tail);
        q[tail++] = d;
    }
    T getData() {
        if (head == SZ && !cycling)
            throw Excep(head);
        else if (head == SZ) {
            head = 0;
            cycling = false;
        }
        if (head == tail && !cycling)
            throw Excep(head);
        return q[head++];
    }
};

void anotherTask();

#endif //EXCEPTIONS_TEMPLQUEUE_H
