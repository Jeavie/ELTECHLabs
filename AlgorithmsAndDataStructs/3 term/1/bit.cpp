//
// Created by matgod on 14.09.17.
//

#include <cmath>
#include <iostream>
#include "bit.h"
#include "mass.h"

short mass_to_bit(char *mass) {
    short b_mass = 0;
    for (int i = 0; mass[i] != '\0'; i++) b_mass += pow(2, mass[i] - '0');
    return b_mass;
}
short coop(short b_A, short b_B, short b_C, short b_D) {
    return b_A & b_B & b_C & b_D;
}

void print_bit(short mass) {
    short bit_help = pow(2, 10);
    short bit_num = 10;
    while (bit_help > 1){
        if (bit_help > mass) {
            bit_help /=2;
            bit_num--;
        }
        else {
            std::cout << bit_num;
            mass -= bit_help;
        }
    }
    if (mass == 1) std::cout << bit_num;
}

char* bit_to_mass(short bit) {
    char* mass = new char[max_size + 1];
    short bit_help = (short)pow(2, max_size);
    short bit_num = 10;
    short i = 0;
    while (bit_help > 1){
        if (bit_help > bit) {
            bit_help /=2;
            bit_num--;
        }
        else {
            mass[i++] = (char)(bit_num + '0');
            bit -= bit_help;
        }
    }
    if (bit == 1) {
        mass[i++] = '0';
    }
    mass[i] = '\0';
    return mass;
}