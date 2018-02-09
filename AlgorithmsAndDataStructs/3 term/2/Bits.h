//
// Created by jeavie on 26.09.17.
//

#ifndef INC_2_BITS_H
#define INC_2_BITS_H


class Bits {
public:
    Bits(){
        arrayOfBits = new bool[max_size];
        name = bits_count + 'A';
        bits_count++;
    }

    Bits(const Bits &bits) {
        arrayOfBits = new bool[max_size];
    }

    ~Bits() {
        delete arrayOfBits;
    }

    Bits& operator = (const Bits &bits);

    Bits& conj(const Bits &first_bits, const Bits &sec_bits, const Bits &third_bits, const Bits &fourth_bits);

    void print();

private:

    bool* arrayOfBits = nullptr;

    short size = 0;

    static const int max_size = 10;

    static short bits_count;

    char name;
};


#endif //INC_2_BITS_H
