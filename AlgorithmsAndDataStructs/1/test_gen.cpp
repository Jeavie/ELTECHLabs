//
// Created by matgod on 19.09.17.
//

#include <cmath>
#include <iostream>
#include "test_gen.h"
#include "bit.h"
#include "bit_mass.h"
#include "spisok.h"
#include "mass.h"
using namespace std;
void test_program(char* A, char* B, char* C, char* D) {
    char *E;
    list *A_list = to_list(A),
            *B_list = to_list(B),
            *C_list = to_list(C),
            *D_list = to_list(D),
            *E_list;
    short b_A = mass_to_bit(A),
            b_B = mass_to_bit(B),
            b_C = mass_to_bit(C),
            b_D = mass_to_bit(D),
            b_E;
    bool *b_m_A = mass_to_bit_mass(A),
            *b_m_B = mass_to_bit_mass(B),
            *b_m_C = mass_to_bit_mass(C),
            *b_m_D = mass_to_bit_mass(D),
            *b_m_E;
    unsigned long start, stop, array_time = 0, list_time = 0, bit_mass_time = 0, machine_word_time = 0,
            count = 100000, tic_in_ms = CLOCKS_PER_SEC / 1000;
    for (unsigned long i = 0; i < count; i++) {
        start = clock();
        E = coop(A, B, C, D);
        stop = clock();
        array_time += (stop - start);
        start = clock();
        E_list = coop(A_list, B_list, C_list, D_list);
        stop = clock();
        list_time += (stop - start);
        start = clock();
        b_m_E = coop(b_m_A, b_m_B, b_m_C, b_m_D);
        stop = clock();
        bit_mass_time += (stop - start);
        start = clock();
        b_E = coop(b_A, b_B, b_C, b_D);
        stop = clock();
        machine_word_time += (stop - start);
        if (i < count - 1) {
            delete[] E;
            E = nullptr;
            delete_list(E_list);
            delete[] b_m_E;
            b_m_E = nullptr;
        }
    }
    cout << "Исходные множества:\nA = ";
    print_bit(b_A);
    cout << "\nB = ";
    print_bit(b_B);
    cout << "\nC = ";
    print_bit(b_C);
    cout << "\nD = ";
    print_bit(b_D);
    cout << "\nРезультат обработки:\narray E = " << E << " time = " << array_time / tic_in_ms << "ms\n";
    cout << "list E = ";
    print_list(E_list);
    cout << " time = " << list_time / tic_in_ms << "ms\n";
    cout << "bit array E = ";
    print_bit_mass(b_m_E);
    cout << " time = " << bit_mass_time / tic_in_ms << "ms\n";
    cout << "machine word E = ";
    print_bit(b_E);
    cout << " time = " << machine_word_time / tic_in_ms << "ms\n";
    delete[] A;
    A = nullptr;
    delete[] B;
    B = nullptr;
    delete[] C;
    C = nullptr;
    delete[] D;
    D = nullptr;
    delete[] E;
    E = nullptr;
    delete_list(A_list);
    delete_list(B_list);
    delete_list(C_list);
    delete_list(D_list);
    delete_list(E_list);
    delete[] b_m_A;
    b_m_A = nullptr;
    delete[] b_m_B;
    b_m_B = nullptr;
    delete[] b_m_C;
    b_m_C = nullptr;
    delete[] b_m_D;
    b_m_D = nullptr;
    delete[] b_m_E;
    b_m_E = nullptr;
}