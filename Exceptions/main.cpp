#include <iostream>
#include <string>
#include "TQueue.h"
#include "dofile.h"

// dofile task is incomplete

int main() {
    // task1_var3(); - in Excep.cpp
    // anotherTask(); - below




    return 0;
}

//void anotherTask() {
//    Queue<std::string> que;
//
//    size_t respond;
//    do {
//        std::cout << "Choose the action."
//                     "\n1. Insert the element to the queue"
//                     "\n2. Erase the element from the queue"
//                     "\n0. Exit\n";
//        std::cin >> respond;
//        if (respond == 1) {
//            try {
//                std::cout << "\nInput: ";
//                std::string str;
//                std::cin >> str;
//                que.setData(str);
//            } catch (Queue<std::string>::Excep& in) {
//                std::cerr << "\nQueue overflow! Position: " << in.index << '\n';
//            }
//            std::cout << '\n';
//        }
//        else if (respond == 2) {
//            try {
//                std::cout << "Output: ";
//                std::cout << que.getData();
//            }
//            catch (Queue<std::string>::Excep& in) {
//                std::cerr << "\nQueue is empty! Position: " << in.index << '\n';
//            }
//            std::cout << '\n';
//        }
//        else if (!respond)
//            break;
//        else {
//            std::cout << "\nIncorrect input!\n";
//        }
//    } while (true);
//}