//
// Created by matgod on 24.10.17.
//

#ifndef ALG_LAB3_QUEUE_H
#define ALG_LAB3_QUEUE_H


template <class Item> class QUEUE {
    Item* Q;
    int h, t, N;
public:
    QUEUE (int maxQ) : h(0), t(0), N(maxQ), Q (new Item[maxQ + 1]) {}
    int empty() const {
        return (h % N) == t;
    }
    void put (Item item) {
        Q[t++] = item;
        t %= N;
    }
    Item get() {
        h %= N;
        return Q[h++];
    }
};


#endif //ALG_LAB3_QUEUE_H
