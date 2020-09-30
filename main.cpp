#include <iostream>


/*for strcpy(), strcat(), strcmp() include <cstring>
for exit()  (<process.h> is also allowed) include <cstdlib>*/

class String {
    char* str;
public:
    String() { }
    String(char* s) {
        int l = strlen(s);
        str = new char[l + 1];
        strcpy(str, s);
    }
    ~String() { delete[] str; }
    void task6() {
        int i, l = strlen(str);
        if (l % 2 == 0) {
            for (i = 0; i <= l / 2; i++)
                if (*(str + i) == '.') *(str + i) = ',';
        }
        else {
            for (i = l / 2 + 1; str[i]; i++)
                str[i - 1] = str[i];
            str[i - 1] = '\0';
        }
    }
    void task7() {
        for (int i = 1; str[i]; i++)
            if (str[i - 1] == str[i])
                str[i] = str[i - 1] = '*';
    }
    void task1() {
        int i;
        for (i = 0; str[i + 1]; i++);
        for (int j = 0; str[j + 1]; j++)
            if (*(str + j) == 'a')
                *(str + j) = *(str + i);
    }
    void get_str() {
        std::cout << str;
    }
};

int main() {
    String s1 = "sadk. ad.aa ad. a eiead adas";
    s1.task7();
    s1.get_str();
    return 0;
}