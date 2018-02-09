//
// Created by jeavie on 25.09.17.
//

#ifndef INC_2_BIT_H
#define INC_2_BIT_H


class Bit {
public:
    static short arrayToBit(char *array);
    static short conj(short bA, short bB, short bC, short bD);
    static void printBit(short);
    static char* bitToArray(short bit);
};


#endif //INC_2_BIT_H
