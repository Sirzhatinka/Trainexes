#include <iostream>
#include <cstdlib>                                // to fill the array
#include <ctime>                                  // to initialize


class vector {
    int* ptr;
    int size;
public:
    vector(): size(1) { ptr = new int; }
    vector(int s): size(s) { ptr = new int[size]; }
    ~vector() { delete[] ptr; }

    int variant_3() {
        int start = 0, sum = 0, min = *ptr;
        for (int i = 1; i < size; i++)
            if (*(ptr + i) < min) {
                min = *(ptr + i);
                std::cout << "\nNow, min = " << min;
                start = i;
                std::cout << "\nstart = " << start;
            }
        start++;
        for (; start < size; start++)
            sum += *(ptr + start);
        return sum;
    }

    int& operator[](int index) {
        while (index >= size)
            index -= size;
        while (index < 0)
            index += size;
        return *(ptr + index);
    }

    void add_back(int value) {
        int *temp = new int[++size];
        for (int i = 0; i < size - 1; i++)
            *(temp + i) = *(ptr + i);
        *(temp + size - 1) = value;
        delete[] ptr;
        ptr = temp;
    }
    void add_front(int value) {
        size++;
        int *temp = new int[size];
        *temp = value;
        for (int i = 1; i < size; i++)
            *(temp + i) = *(ptr + i);
        delete[] ptr;
        ptr = temp;
    }

    void del_back() {
        int* temp = new int[--size];
        for (int i = 0; i < size; i++)
            *(temp + i) = *(ptr + i);
        delete[] ptr;
        ptr = temp;
    }
    void del_front() {
        int* temp = new int[--size];
        for (int i = 1; i < size + 1; i++)
            *(temp + i - 1) = *(ptr + i);
        delete[] ptr;
        ptr = temp;
    }

    int get_size() { return size; }
    void ShowThem() {
        for (int i = 0; i < size - 1; i++)
            std::cout << *(ptr + i) << ' ';
        std::cout << *(ptr + size - 1);
    }

    void SrtUp() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (*(ptr + j) < *(ptr + i)) {
                    int temp = *(ptr + j);
                    *(ptr + j) = *(ptr + i);
                    *(ptr + i) = temp;
                }
            }
        }
    }
};

int main() {
    srand(time(NULL));
    vector arr1(10), arr2;
    int i;
    arr2[0] = rand() % 100;
    for (i = 1; i < 10; i++)
        arr2.add_back(rand() % 100);
    for (i = 0; i < 10; i++)
        arr1[i] = rand() % 100;
    std::cout << "Before sort: ";
    arr2.ShowThem();
    arr2.SrtUp();
    std::cout << "\nAfter: ";
    arr2.ShowThem();
    return 0;
}
