//
// Created by matgod on 23.10.17.
//

#include <cstdlib>
#include "Node.h"
#include "Tree.h"

Node * Tree::MakeNode(int depth) {
    Node* v = nullptr;
    int Y = (depth < rand() % 6 + 1) && (num <= 'z');
    if (Y) {
        v = new Node;
        v->lft = MakeNode(depth + 1);
        v->rgt = MakeNode(depth + 1);
        v->d = num++;
    }
    return v;
}