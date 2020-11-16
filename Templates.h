//
// Created by mazur on 27.10.2020.
//

#ifndef TEMPLATES_TEMPLATES_H
#define TEMPLATES_TEMPLATES_H

const int SZ = 10;
template <class T> T funct(T* a, T* b = nullptr) {
    if (b)
        return *a < *b ? *a : *b;
    else {
        T min = *a;
        for (int i = 1; i < SZ; i++)
            if (*(a + i) < min)
                min = *(a + i);
        return min;
    }
}

template <class T>
class Dynar {
    T* ptr;
    int size;
public:
    Dynar(): size(1) { ptr = new T; }
    Dynar(int sz): size(sz) { ptr = new T[size]; }

    ~Dynar() {
        if (size == 1)
            delete ptr;
        if (size > 1)
            delete[] ptr;
    }

    void add_back(T el) {
        T* temp = new T[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = ptr[i];
        }
        temp[size++] = el;
        delete[] ptr;
        ptr = temp;
    }
    void show() {
        for (int i = 0; i < size; i++)
            std::cout << ptr[i] << ' ';
        std::cout << std::endl;
    }

    void sort();

    T& operator[](int);
};


template <class T>
T& Dynar<T>::operator[](int n) {
    return ptr[n];
}

template <class T>
void Dynar<T>::sort() {
    T temp;
    for (int j = 0; j < size - 1; j++)
        for (int k = j + 1; k < size; k++)
            if (ptr[k] < ptr[j]) {
                temp = ptr[k];
                ptr[k] = ptr[j];
                ptr[j] = temp;
            }
}


#endif //TEMPLATES_TEMPLATES_H
