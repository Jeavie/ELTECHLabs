//
// Created by jeavie on 25.09.17.
//

#ifndef INC_2_HELPER_H
#define INC_2_HELPER_H


class Helper {
public:
    static bool charToStr(char ch, char* str);
    static int choice();
    static char* randomArray();
    static bool elemInArr(char elem, char* array){
        for (short i = 0; array[i] != '\0'; i++) {
            if (elem == array[i]) return true;
        }
        return false;
    }
};


#endif //INC_2_HELPER_H
