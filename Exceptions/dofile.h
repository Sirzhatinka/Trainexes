//
// Created by mazur on 02.12.2020.
//

#ifndef EXCEPTIONS_DOFILE_H
#define EXCEPTIONS_DOFILE_H

#include <iostream>
#include <fstream>
#include <string>

class dofile {
    std::ifstream in;
    std::ofstream out;
public:
    dofile(const std::string&);
    ~dofile();

    void readf();
    void writef(const char*);

    class fileExcep {
    public:
        int bit;
    };

};


#endif //EXCEPTIONS_DOFILE_H
