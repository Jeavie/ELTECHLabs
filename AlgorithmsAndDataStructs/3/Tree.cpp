//
// Created by matgod on 23.10.17.
//

#include <iostream>
#include <cstring>
#include "Tree.h"
#include "STACK.h"
#include "QUEUE.h"

Tree::Tree(char nm, char mnm, int mxr):
    num(nm), maxnum(mnm), maxrow(mxr), offset(40), root(nullptr),
    SCREEN(new char* [maxrow])
{
    for (int i = 0; i < maxrow; ++i) SCREEN[i] = new char[80];
}

Tree::~Tree() {
    for (int i = 0; i < maxrow; ++i) delete []SCREEN[i];
    delete []SCREEN;
    delete root;
}

void Tree::OutTree() {
    clrscr();
    OutNodes(root, 1, offset);
    for (int i = 0; i < maxrow; ++i) {
        SCREEN[i][79] = 0;
        std::cout << '\n' << SCREEN[i];
    }
    std::cout << '\n';
}

void Tree::clrscr() {
    for (int i = 0; i < maxrow; ++i) {
        memset(SCREEN[i], '.', 80);
    }
}

void Tree::OutNodes(Node *v, int r, int c) {
    if (r && c && (c < 80)) SCREEN[r - 1][c - 1] = v->d;
    if (r < maxrow) {
        if (v->lft) OutNodes(v->lft, r + 1, c - (offset >> r));
        if (v->rgt) OutNodes(v->rgt, r + 1, c + (offset >> r));
    }
}

int Tree::DFS() {
    const int MaxS = 20;
    int count = 0;
    STACK <Node*> S(MaxS);
    S.push(root);
    while (!S.empty()) {
        Node* v = S.pop();
        std::cout << v->d << '_';
        ++count;
        if (v->rgt) S.push(v->rgt);
        if (v->lft) S.push(v->lft);
    }
    return count;
}

int Tree::BFS() {
    const int MaxQ = 20;
    int count = 0;
    QUEUE <Node*> Q(MaxQ);
    Q.put(root);
    while (!Q.empty()) {
        Node* v = Q.get();
        std::cout << v->d << '_';
        ++count;
        if (v->lft) Q.put(v->lft);
        if (v->rgt) Q.put(v->rgt);
    }
    return count;
}

int Tree::OutNode(Node* root) {
    int count = 0;
    if (root->lft) count += OutNode(root->lft);
    std::cout << root->d << '_';
    if (root->rgt) count += OutNode(root->rgt);
    return count + 1;
}

int Tree::IFS() {
    return OutNode(root);
}

int Tree::CountOfDefs(Node* root) {
    int count = 0;
    if(root->lft) count += CountOfDefs(root->lft) + 1;
    if(root->rgt) count += CountOfDefs(root->rgt) + 1;
    return count;
}

int Tree::task (Node* root) {
    int count = 0;
    if (root->lft) count += task(root->lft);
    if (root->rgt) count += task(root->rgt);
    if (CountOfDefs(root) <= 2) count++;
    return count;
}

int Tree::task() {
    return task(root);
}