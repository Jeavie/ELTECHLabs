#include <iostream>
#include "unsignedLong.h"

int getChoice() {
    char ch;
    int num = 0;
    while ((ch = getc(stdin)) != '\n') {
        if (isdigit(ch)) {
            num = ch - '0';
        }
    }
    return num;
}

union Double {
    Double(double n);
    void doubleOut();
    void count();
    int a;
    double d;
    unsigned char c[sizeof (double)];
};

Double::Double(double n)
{
    d=n;
}

void Double::doubleOut(){
    a=0;
    for (int j = sizeof (double) - 1; j >= 0; j--) {
        for (int i = 128; i; i >>= 1){
            if (i & c[j]) {
                std::cout << "1";
                a++;
            }
            else {
                std::cout << "0";
            }
        }
        std::cout << " ";
    }
}

void Double::count(){
    int n = a, integ = 0, part = 0;
    while (n > 0) {
        if (n > 8){
            integ ++;
            n = n - 8;
        }
        else {
            part = n;
            n = 0;
        }
    }
    int j = sizeof (double) - 1;
    for (; j>=0, integ > 0; j--, integ--) {
            c[j]=0xFF;
    }
    switch(part){
        case 0:
            c[j]=0x00;
            break;
        case 1:
            c[j]=0x80;
            break;
        case 2:
            c[j]=0xC0;
            break;
        case 3:
            c[j]=0xE0;
            break;
        case 4:
            c[j]=0xF0;
            break;
        case 5:
            c[j]=0xF8;
            break;
        case 6:
            c[j]=0xFC;
            break;
        default:
            c[j]=0xFE;
            break;
    }
    j--;
    for (j; j>0; j--){
        c[j]=0;
    }
    c[0]=0;
    for (int k = sizeof (double) - 1; k >= 0; k--) {
        for (int i = 128; i; i >>= 1){
            if (i & c[k]) {
                std::cout << "1";
            }
            else {
                std::cout << "0";
            }
        }
        std::cout << " ";
    }
}

int main() {
    setlocale(0, "Russian");
    std::cout << "Выберите пункт меню:\n\n(1) - unsigned long.\n(2) - double.\n";
    int choice;
    do {
        choice = getChoice();
        switch (choice) {
            case 1: {
                unsigned long u;
                std::cout << "\nВведенное значение типа unsigned long:\n";
                std::cin >> u;
                unsignedLong uLong;
                std::cout << "\nВведенное значение типа unsigned long в двоичном формате:\n";
                uLong.unsignedLongOut(u);
                u=uLong.shift(u);
                std::cout << "\nПреобразованное значение типа unsigned long в двоичном формате:\n";
                uLong.unsignedLongOut(u);
                std::cout << "\nПреобразованное значение типа unsigned long:\n";
                uLong.unsignedLongReturn(u);
                break;
            }
            case 2: {
                double d;
                std::cout << "\nВведенное значение типа double:\n";
                std::cin >> d;
                Double dbl(d);
                std::cout << "\nВведенное значение типа double в двоичном формате:\n";
                dbl.doubleOut();
                std::cout << "\n\nПреобразованное значение типа double в двоичном формате:\n";
                dbl.count();
                std::cout << "\n\nПреобразованное значение типа double:\n";
                std::cout << dbl.d;
                break;
            }
            default: {
                std::cout << "Такого пункта нет. Нажмите любую клавишу для повторного выбора.";
                std::cin.get();
                break;
            }
        }
    } while (choice != 1 && choice != 2);
    return 0;
}