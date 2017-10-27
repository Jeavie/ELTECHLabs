//
// Created by matgod on 23.10.17.
//

#ifndef ALG_LAB3_TREE_H
#define ALG_LAB3_TREE_H


#include "Node.h"

class Tree {
    Node* root;
    char num, maxnum;
    int maxrow, offset, taskCount;
    char** SCREEN;
    void clrscr();
    Node* MakeNode(int depth);
    void OutNodes(Node* v, int r, int c);
    Tree(const Tree&);
    Tree(Tree&&){};
    Tree operator = (const Tree &) const;
    Tree operator = (Tree&&) const{};
    int OutNode(Node*);
    int task (Node*);
    int CountOfDefs(Node*);
public:
    Tree(char num, char maxnum, int maxrow);
    ~Tree();
    void MakeTree() {
        root = MakeNode(0);
    }
    bool exist() {
           return (root != nullptr);
    }
    int DFS();
    int BFS();
    int IFS();
    void OutTree();
    int task();
};


#endif //ALG_LAB3_TREE_H
