//
// Created by matgod on 24.10.17.
//

#ifndef ALG_LAB3_STACK_H
#define ALG_LAB3_STACK_H


template <class Item> class STACK {
    Item* S;
    int t;
public:
    STACK(int maxt) : S(new Item[maxt]), t(0) {}
    int empty() const {
        return (t == 0);
    }
    void push (Item item) {
        S[t++] = item;
    }
    Item pop() {
        return (t ? S[--t] : 0);
    }
};


#endif //ALG_LAB3_STACK_H
