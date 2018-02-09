//
// Created by matgod on 13.09.17.
//
#include <cstdlib>
#include "spisok.h"
#include <iostream>
struct list {
    char el;
    list* next = NULL;
};

list* add_to_list(list* head, char ch) {
    if (head == NULL) {
        head = new list;
        head->el = ch;
    }
    else {
        list* tec = head;
        while (tec->next != NULL) {
            tec = tec->next;
        }
        tec->next = new list;
        tec->next->el = ch;
    }
    return head;
}

list* to_list(char* mass) {
    int i = 0;
    list* head = NULL;
    while (mass[i] != '\0') {
        head = add_to_list(head, mass[i++]);
    }
    return head;
}

list* coop(list* A, list* B, list* C, list* D) {
    list* E = NULL;
    list* B_tec;
    list* C_tec;
    list* D_tec;
    while (A != NULL) {
        B_tec = B;
        while (B_tec != NULL) {
            if (A->el == B_tec->el) {
                C_tec = C;
                while (C_tec != NULL) {
                    if (B_tec->el == C_tec->el) {
                        D_tec = D;
                        while (D_tec != NULL) {
                            if (C_tec->el == D_tec->el) {
                                E = add_to_list(E, D_tec->el);
                                break;
                            }
                            D_tec = D_tec->next;
                        }
                    }
                    C_tec = C_tec->next;
                }
            }
            B_tec = B_tec->next;
        }
        A = A->next;
    }
    return E;
}

void print_list(list* head) {
    while (head) {
        std::cout << head->el;
        head = head->next;
    }
}

void delete_list(list* sp) {
    list* prev = sp;
    while (sp != NULL) {
        sp = sp->next;
        delete(prev);
        prev = sp;
    }
}
