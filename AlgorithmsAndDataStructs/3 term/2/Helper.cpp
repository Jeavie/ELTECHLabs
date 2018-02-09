////
//// Created by jeavie on 25.09.17.
////
//
//#include "Helper.h"
//#include "Bit.h"
//#include <iostream>
//
//bool Helper::elemInArr(char elem, char *array) {
//
//}
//
//bool Helper::charToStr(char ch, char *str) {
//    int i = 0;
//    while (str[i] != '\0') {
//        if (ch == str[i++]) return true;
//    }
//    return false;
//}
//
//int Helper::choice() {
//    char ch;
//    int num = 0;
//    while ((ch = getc(stdin)) != '\n') {
//        if (isdigit(ch)) {
//            num = ch - '0';
//        }
//    }
//    return num;
//}
//
//char* Helper::randomArray() {
//    srand(clock());
//    return Bit::bitToArray(rand() % 1024);
//}