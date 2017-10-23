//
// Created by jeavie on 26.09.17.
//

#include "unsignedLong.h"
#include <iostream>
#include <cmath>

void unsignedLong::setBit(unsigned long &src, int index, bool val){
        if (val)
            src|=(1<<index);
        else
            src&=~(1<<index);
}

unsigned long unsignedLong::shift(unsigned long input) {
    for (int i = 0; i < 31; ++i){
        for (int j = 31; j > 0, j > i; --j){
            if (((input >> i) & 1)&&((input >> j) & 1) == 0){
                setBit(input, i, 0);
                setBit(input, j, 1);
            }
        }
    }
    return input;
}

void unsignedLong::unsignedLongOut(unsigned long input) {
    for (int i = 0; i < 32; ++i) {
        std::cout << ((input >> (32 - i - 1)) & 1);
        if (i%8==7){
            std::cout << " ";
        }
    }
   std::cout << std::endl;
}

void unsignedLong::unsignedLongReturn(unsigned long input) {
    unsigned long j=0;
    for (int i = 32; i >= 0; --i) {
        if(input >> (i-1) & 1 == 1) {
            j += pow(2, (i-1));
        }
    }
    std::cout << j << std::endl;
}