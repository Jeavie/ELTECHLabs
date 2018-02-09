#include "Array.h"
#include "Helper.h"
#include <iostream>

short Array::arr_count = 0;

int main() {
    setlocale(0, " ");
    Array A, B, C, D, E;
    A.init();
    B.init();
    C.init();
    D.init();
    E.conj(A, B, C, D);
    E.print();
//    char *A, *B, *C, *D;
//    std::cout << "Выберите пункт меню:\n(1) - Ручной ввод множества.\n(2) - Случайные множества.\n";
//    int choice;
//    do {
//        choice = Helper::choice();
//        switch (choice) {
//            case 1: {
//                std::cout << "Введите множество A: ";
//                A = Array::input();
//                std::cout << "Введите множество B: ";
//                B = Array::input();
//                std::cout << "Введите множество C: ";
//                C = Array::input();
//                std::cout << "Введите множество D: ";
//                D = Array::input();
//                break;
//            }
//            case 2: {
//                A = Helper::randomArray();
//                B = Helper::randomArray();
//                C = Helper::randomArray();
//                D = Helper::randomArray();
//                break;
//            }
//            default: {
//                std::cout << "Такого пункта нет. Нажмите любую клавишу для повторного выбора.";
//                std::cin.get();
//                break;
//            }
//        }
//    } while (choice != 1 && choice != 2);
    return 0;
}
