//
// Created by matgod on 13.09.17.
//
#include "mass.h"
#include "help_f.h"
#include <iostream>
char* coop(char* A, char* B, char* C, char* D) {
    int E_size = 0;
    char* E = new char [max_size + 1];
    for (int i = 0; A[i] != '\0'; i++) {
        for (int j = 0; B[j] != '\0'; j++) {
            if (A[i] == B[j]) {
                for (int k = 0; C[k] != '\0'; k++) {
                    if (B[j] == C[k]) {
                        for (int l = 0; D[l] != '\0'; l++) {
                            if (C[k] == D[l]) {
                                E[E_size++] = D[l];
                            }
                        }
                    }
                }
            }
        }
    }
    E[E_size] = '\0';
    return E;
}

char* hand_init() {
    char ch;
    char* mass = new char[max_size + 1];
    int i = 0;
    while ((ch = getc(stdin)) != '\n') {
        if (!char_in_str(ch, mass) && isdigit(ch)) {
            mass[i++] = ch;
            mass[i] = '\0';
        }
    }
    mass[i] = '\0';
    return mass;
}