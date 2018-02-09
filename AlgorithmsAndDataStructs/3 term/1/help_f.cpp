//
// Created by matgod on 14.09.17.
//

#include <iostream>
#include "help_f.h"
#include "bit.h"

bool char_in_str(char ch, char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (ch == str[i++]) return true;
    }
    return false;
}

int get_choise() {
    char ch;
    int num = 0;
    while ((ch = getc(stdin)) != '\n') {
        if (isdigit(ch)) {
            num = ch - '0';
        }
    }
    return num;
}

char* random_array() {
    srand(clock());
    return bit_to_mass(rand() % 1024);
}