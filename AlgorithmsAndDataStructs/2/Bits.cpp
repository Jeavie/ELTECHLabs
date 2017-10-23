//
// Created by jeavie on 26.09.17.
//

#include "Array.h"
#include "Bits.h"
#include <iostream>

//bool* mass_to_bit_mass (char* mass) {
//    bool* bit_mass = new bool[max_size];
//    int i;
//    for (i = 0; i < 10; i++) {
//        bit_mass[i] = false;
//    }
//    i = 0;
//    while (mass[i] != '\0') {
//        bit_mass[mass[i++] - '0'] = true;
//    }
//    return bit_mass;
//}
//
//bool* coop(bool* b_m_A, bool* b_m_B, bool* b_m_C, bool* b_m_D) {
//    bool* b_m_E = new bool[max_size];
//    for (int i = 0; i < max_size; i++) {
//        b_m_E[i] = b_m_A[i] && b_m_B[i] && b_m_C[i] && b_m_D[i];
//    }
//    return b_m_E;
//}
//
//void print_bit_mass(bool* bit_mass) {
//    for (int i = max_size - 1; i >= 0; i--) {
//        if (bit_mass[i]) {
//            std::cout << i;
//        }
//    }
//}