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
    ~String() {
        delete[] str;
    }
};

int main() {
    
    return 0;
}