#include <iostream>
#include <string>
#include <ctime>

#include <algorithm>


const std::string faculties[5] = { "Physics and math", "Geography", "Medicine", "Law", "Foreign languages" };
enum suff { gmail, yandex, mail };

struct student {
    std::string fullName;
    int faculty;
    size_t group;
    short email;

    student(): fullName(""), group(0), email(rand() % 3), faculty(0) { }
    void set() {

        faculty = rand() % 5;

        int firstSize = rand() % 7 + 14;                         // the size of name between 14 and 21
        int space = rand() % 4 + 4;
        int i;
        for (i = 0; i < firstSize; i++) {
            if (i == space) fullName += ' ';
            fullName += char(rand() % 26 + 97);                // sequence of chars between 97 and 123 (lowercase letters)
        }
        group = rand() % 3 + 1;
        email = suff(rand() % 3 + 1);
    }
    void get() {
        std::cout << "\nStudent.\nFull name: " << fullName
                  << "\nFaculty: " << faculties[faculty]
                  << "\nGroup: " << group
                  << "\nEmail: ";
        std::string milo;
        for (int j = 0; j < rand() % 6 + 3; j++)
            milo += char(rand() % 26 + 97);
        switch (email) {
            case 1: std::cout << milo << "@gmail.com";
                break;
            case 2: std::cout << milo << "@yandex.ru";
                break;
            case 3: std::cout << milo << "@mail.ru";
                break;
            default: std::cout << milo << "@gmail.com";
                break;
        }
    }
};

struct anotherStudent {
    size_t group;
    std::string fullName;
    short email;
    int faculty;
};



void task2();
void task3();

int main() {
    srand(time(nullptr));
    task2();

    int ArraySize;                                              // task3 starts here
    std::cout << "Input the number of students: ";
    std::cin >> ArraySize;
    auto listOfStudents = new student[ArraySize];

    std::for_each(listOfStudents, listOfStudents + ArraySize, [](student &s) { s.set(); });

    std::cout << "First element:";                                 // task4
    (*listOfStudents).get();

    std::cout << "\n\nThe size of the created array: ";
    std::cout << sizeof(student) * ArraySize;

    auto iter = listOfStudents;                                 // task6
    std::cout << "\n\nThe list of adresses:\n";
    std::cout << iter++ << '\n';
    while (iter != listOfStudents + ArraySize) {
        std::cout << iter << " Difference: " << sizeof(*iter) << '\n';
        iter++;
    }


    std::cout << "\n\nThe neighbourous adresses of structure fields and their sizes:\n";                    // task7
    std::cout << std::dec << sizeof(listOfStudents->fullName) << ' ' << sizeof(listOfStudents->faculty) << ' '
              << sizeof(listOfStudents->group) << ' ' << sizeof(listOfStudents->email) << "\n\n";
    std::cout << &listOfStudents->fullName << '\n' << &listOfStudents->faculty << '\n'
              << &listOfStudents->group << '\n' << &listOfStudents->email << '\n';

    std::cout << "\nAs it's seen, substraction the adress from the previous one returns 40."
                 " You can check it yourself.\n"
                 "The sum of all fields of one object gives 38, but the whole object takes 40 bytes of memory."
                 "\nLet's create the same structure, but change the sequence of fields.";

    auto ans = new anotherStudent[2];
    ans->group = 4;
    ans->fullName = "amkMd sdasd";
    ans->email = 2;
    ans->faculty = 3;
    (ans + 1)->group = 3;
    (ans + 1)->fullName = "andklamd amdskasd";
    (ans + 1)->email = 1;
    (ans + 1)->faculty = 0;
    std::cout << "\n\nSizes of new objects: " << sizeof(*ans) << ' ' << sizeof(*(ans + 1));
    std::cout << "\n\nTheir adtesses:\n";
    std::cout << ans << '\n' << ans + 1;
    std::cout << "\n\nThe neighborous adresses of first object and its sizes:\n";
    std::cout << sizeof(ans->group) << ' ' << std::dec << sizeof(ans->fullName) << ' '
              << sizeof(ans->email) << ' ' << sizeof(ans->faculty) << "\n\n";
    std::cout << &ans->group << '\n' << &ans->fullName << '\n'
              << &ans->email << '\n' << &ans->faculty << '\n';

    std::cout << "If you compare adresses, you'll see that 2-bytes-field differs from the next one by 4 bytes!"
                 "\nThis is what they call alignment.";
    return 0;
}

void task2() {
    student st_ar[30];
    for (student& j: st_ar)
        j.set();
}
