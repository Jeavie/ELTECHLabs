//
// Created by jeavie on 25.09.17.
//

#ifndef INC_2_ARRAY_H
#define INC_2_ARRAY_H

#include <iostream>
#include "Helper.h"
using namespace std;

class Array {
public:
    Array() {
        elements = new char[max_size + 1];
        elements[0] = '\0';
        name = arr_count + 'A';
        arr_count++;
    }

    Array(const Array &arr) {
        elements = new char[max_size + 1];
        short i = 0;
        do {
            elements[i++] = arr.elements[i];
        } while (elements[i-1] != '\0');
        name = arr.name;
    }

    ~Array() {
        delete elements;
    }

    Array& operator = (const Array &arr);

    void addElem(char elem);

    void init();

    void print();

    Array& conj(const Array &first_arr, const Array &sec_arr, const Array &third_arr, const Array &fourth_arr);

private:
    char* elements = nullptr;

    short size = 0;

    static const int max_size = 10;

    static short arr_count;

    char name;
};


#endif //INC_2_ARRAY_H
