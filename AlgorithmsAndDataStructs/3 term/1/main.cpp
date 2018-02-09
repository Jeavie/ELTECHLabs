#include <iostream>
#include "mass.h"
#include "test_gen.h"
#include "help_f.h"

using namespace std;

int main() {
    setlocale(0, " ");
    char *A, *B, *C, *D;
    cout << "Выберите пункт меню:\n(1) - Ручной ввод множества.\n(2) - Случайные множества.\n";
    int choise;
    do {
        choise = get_choise();
        switch (choise) {
            case 1: {
                cout << "Введите множество A: ";
                A = hand_init();
                cout << "Введите множество B: ";
                B = hand_init();
                cout << "Введите множество C: ";
                C = hand_init();
                cout << "Введите множество D: ";
                D = hand_init();
                break;
            }
            case 2: {
                A = random_array();
                B = random_array();
                C = random_array();
                D = random_array();
                break;
            }
            default: {
                cout << "Такого пункта нет. Нажмите любую клавишу для повторного выбора.";
                cin.get();
                system("clear");
                break;
            }
        }
    } while (choise != 1 && choise != 2);
    test_program(A, B, C, D);
    return 0;
}
