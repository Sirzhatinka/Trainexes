#include <iostream>
#include <string>
#include <ctime>

#include <algorithm>


const std::string faculties[5] = { "Physics and math", "Geography", "Medicine", "Law", "Foreign languages" };
const std::string suff[3] = { "@gmail.com", "@yandex.ru", "@mail.ru" };
struct student {
    std::string firstName,
                lastName,
                group,
                email,
                faculty;
    student(): firstName(""), lastName(""), group(""), email(""), faculty("") { }
    void set() {

        faculty = faculties[rand() % 5];

        int firstSize = rand() % 7 + 4;                         // the size of names between 4 and 11
        int lastSize = rand() % 7 + 4;
        int i;
        for (i = 0; i < firstSize; i++)
            firstName += char(rand() % 26 + 97);                // sequence of chars between 97 and 123 (lowercase letters)
        for (i = 0; i < lastSize; i++)
            lastName += char(rand() % 26 + 97);
        for (i = 0; i < 5; i++) {
            if (i != 2)
                group += char(rand() % 26 + 97);
            else
                group += '-';                                   // the name of group consist of 5 chars, '-' is in the middle
        }
        int emailSize = rand() % 4 + 4;
        for (i = 0; i < emailSize; i++)
            email += char(rand() % 26 + 97);
        email += suff[rand() % 3];
    }
    void get() {
        std::cout << "\nStudent.\nFirst name: " << firstName
                  << "\nLast name: " << lastName
                  << "\nFaculty: " << faculty
                  << "\nGroup: " << group
                  << "\nEmail: " << email;
    }
};

struct anotherStudent {
    std::string group,
            email,
            faculty,
            firstName,
            lastName;
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

    std::cout << "First el:\n";                                 // task4
    (*listOfStudents).get();

    std::cout << "\n\nThe size of the created array: ";
    int size = sizeof(student) * ArraySize;
    std::cout << size;

    auto iter = listOfStudents;                                 // task6
    std::cout << "\n\nThe list of adresses:\n";
    std::cout << iter++ << '\n';
    while (iter != listOfStudents + ArraySize) {
        std::cout << iter << " Difference: " << std::hex << sizeof(*iter) << '\n';
        iter++;
    }

    std::cout << "\n\nThe neighbourous adresses of structure fields:\n";                    // task7
    std::cout << &listOfStudents->group << '\n' << &listOfStudents->faculty << '\n'
              << &listOfStudents->lastName << '\n' << &listOfStudents->firstName << '\n'
              << &listOfStudents->email << '\n';
    return 0;
}

void task2() {
    student st_ar[30];
    for (student& j: st_ar)
        j.set();
}