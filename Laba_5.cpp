#include <iostream>
#include <iomanip>
#include <cstdlib>                                // to fill matrix with random numbers
#include <ctime>                                  // (in Generate() function)

int pow(int , int);                               // to generate negative values (line 32)
class Mtx {
    int** OutPtr;
    int line, column;
public:
    Mtx(): OutPtr(nullptr), line(0), column(0) { }
    Mtx(int m, int n): line(m), column(n) {
        OutPtr = new int*[line];
        int i;
        for (i = 0; i < line; i++)
            *(OutPtr + i) = new int[column];
        std::cout << "Push the elements of the matrix:\n";
        for (i = 0; i < line; i++)
            for (int j = 0; j < column; j++)
                std::cin >> *(*(OutPtr + i) + j);
    }
    ~Mtx() {
        for (int i = 0; i < line; i++)
            delete[] *(OutPtr + i);
        delete[] OutPtr;
    }

    void Generate() {
        srand(time(NULL));
        for (int i = 0; i < line; i++)
            for (int j = 0; j < column; j++)
                *(*(OutPtr + i) + j) = rand() % 100 * pow(-1, rand());
    }
    void Show() {
        for (int i = 0; i < line; i++) {
            for (int j = 0; j < column; j++)
                std::cout << std::setw(4) << *(*(OutPtr + i) + j);
            std::cout << std::endl;
        }
    }

    int Variant_3() {
        for (int i = 0; i < line; i++) {
            for (int j = 0; j < column; j++)
                if (*(*(OutPtr + i) + j) > 0)
                    break;
            return i;
        }
    }

    int* operator[](int i) {
        return *(OutPtr + i);
    }
};

int main() {
    int m, n;
    std::cout << "Push the size of the matrix:\n";
    std::cin >> m >> n;
    Mtx arr(m, n);
    std::cout << "Before random generating:\n";
    arr.Show();
    std::cout << "\nAfter:\n";
    arr.Generate();
        for (int i = 0; i < m; i++) {                                  // to use overloaded operator []
            for (int j = 0; j < n; j++)                               // (equivalent of Show() function)
            std::cout << std::setw(4) << arr[i][j];
        std::cout << std::endl;
    }

    return 0;
}

int pow(int b, int p) {
    if (!p) return 1;
    int n = 1;
    for (int i = 0; i < p; i++)
        n *= b;
    return n;
}
