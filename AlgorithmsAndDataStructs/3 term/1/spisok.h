//
// Created by matgod on 13.09.17.
//

#ifndef LAB1_SPISOK_H
#define LAB1_SPISOK_H
struct list;
list* to_list(char* mass);
list* coop(list* A, list* B, list* C, list* D);
void print_list(list* head);
void delete_list(list* sp);
#endif //LAB1_SPISOK_H
