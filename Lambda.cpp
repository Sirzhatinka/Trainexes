#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>

int main() {
    srand(time(nullptr));

    std::vector<int> Vec(5);

    for (int& i: Vec) i = rand() % 100;

    auto out = [](int x) { std::cout << x << ' '; };        // lambda for output of elements

    std::for_each(Vec.begin(), Vec.end(), out);
    std::cout << std::endl;

    int i = 0;
    auto l = [&](int x, int y) {                            // lambda for counting replacements
        if (x < y) i++;
        return x < y;
    };
    std::sort(Vec.begin(), Vec.end(), l);
    std::for_each(Vec.begin(), Vec.end(), out);
    std::cout << "\nThe number of replacements: " << i;

    std::string str;
    std::cout << "\n\nPush the string you'd like to find: ";
    std::cin >> str;
    auto search = [&str](std::string s) {               // for searching substring
        int n = s.find(str);
        return n;
    };
    std::cout << "The index of substring: " << search("Simple string of mine.");
    return 0;
}
