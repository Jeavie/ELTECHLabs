//
// Created by matgod on 23.10.17.
//

#ifndef ALG_LAB3_NODE_H
#define ALG_LAB3_NODE_H


class Node {
    char d;
    Node* lft;
    Node* rgt;
public:
    Node(): lft(nullptr), rgt(nullptr) {}
    ~Node() {
        if(lft) delete lft;
        if(rgt) delete rgt;
    }
    friend class Tree;
};


#endif //ALG_LAB3_NODE_H
