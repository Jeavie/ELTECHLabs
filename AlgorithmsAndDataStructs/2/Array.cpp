//
// Created by jeavie on 25.09.17.
//

#include "Array.h"

Array& Array::operator = (const Array &arr) {
    if (&arr != this) {
        short i = 0;
        do {
            this->elements[i] = arr.elements[i];
            i++;
        } while (arr.elements[i - 1] != '\0');
        this->size = arr.size;
    }
    return *this;
}

void Array::addElem(char elem) {
    if (size == max_size) {
        cout << "Ошибка. Массив полон.\n";
    }
    else {
        this->elements[size++] = elem;
        this->elements[size] = '\0';
    }
}

void Array::init() {
    cout << "Введите массив " << name << ": ";
    char ch;
    do {
        ch = cin.get();
        if (isdigit(ch) && !Helper::elemInArr(ch, this->elements)) {
            this->elements[size++] = ch;
            this->elements[size] = '\0';
        }
    } while (ch != '\n');
}

void Array::print() {
    cout << "Массив " << name << ": ";
    if (size == 0) {
        cout << "Пусто";
    }
    cout << elements << endl;
}

Array& Array::conj(const Array &first_arr, const Array &sec_arr, const Array &third_arr, const Array &fourth_arr){
    for (short i = 0; first_arr.elements[i] != '\0'; i++) {
        if (Helper::elemInArr(first_arr.elements[i], sec_arr.elements) &&
            Helper::elemInArr(first_arr.elements[i], third_arr.elements) &&
            Helper::elemInArr(first_arr.elements[i], fourth_arr.elements))
            this->addElem(first_arr.elements[i]);
    }
    return *this;
}