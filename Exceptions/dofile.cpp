//
// Created by mazur on 02.12.2020.
//

#include "dofile.h"


dofile::dofile(const std::string& name) {
    in.open(name);
    out.open(name);
    if (!(in.is_open() && out.is_open()))
        throw fileExcep();
}
dofile::~dofile() { in.close(); out.close(); }

void dofile::readf() {
    std::cout << in.rdbuf();
}

void dofile::writef(const char* str) {
    out << str;
}