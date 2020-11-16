#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

int main() {
    srand(time(nullptr));

    int N, first = rand() % 100;
    std::cout << "Vector size: ";
    std::cin >> N;

    std::vector<int> Vec(N);

    std::for_each(Vec.begin(), Vec.end(), [&](int& x) { x = first++; });

    std::vector<int> NewVec(N);
    std::cout << "Skip first elements: ";
    std::cin >> N;

    first = *(Vec.begin() + N);
    std::for_each(NewVec.begin(), NewVec.end(), [&](int& x) { x = first++; });

    for (int& i: Vec)
        std::cout << i << ' ';
    std::cout << std::endl;
    for (int& i: NewVec)
        std::cout << i << ' ';
    return 0;
}
