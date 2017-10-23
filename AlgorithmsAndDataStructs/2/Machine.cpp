////
//// Created by jeavie on 25.09.17.
////
//
//#include "Array.h"
//#include "Bit.h"
//#include <cmath>
//#include <iostream>
//
//short Bit::arrayToBit(char *array) {
//    short aB = 0;
//    for (int i = 0; array[i] != '\0'; i++) aB += pow(2, array[i] - '0');
//    return aB;
//}
//short Bit::conj(short bA, short bB, short bC, short bD) {
//    return bA & bB & bC & bD;
//}
//
//void Bit::arrayToBit(char *array) {
//    short bit_help = pow(2, 10);
//    short bit_num = 10;
//    while (bit_help > 1){
//        if (bit_help > array) {
//            bit_help /=2;
//            bit_num--;
//        }
//        else {
//            std::cout << bit_num;
//            array -= bit_help;
//        }
//    }
//    if (array == 1) std::cout << bit_num;
//}
//
//char* Bit::bitToArray(short bit) {
//    char* array = new char[max_size + 1];
//    short bit_help = (short)pow(2, max_size);
//    short bit_num = 10;
//    short i = 0;
//    while (bit_help > 1){
//        if (bit_help > bit) {
//            bit_help /=2;
//            bit_num--;
//        }
//        else {
//            array[i++] = (char)(bit_num + '0');
//            bit -= bit_help;
//        }
//    }
//    if (bit == 1) {
//        array[i++] = '0';
//    }
//    array[i] = '\0';
//    return array;
//}