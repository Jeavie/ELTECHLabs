#include <iostream>
#include "Tree.h"

int main() {
    int n = 0;
    Tree Tr('a', 'z', 8);
    srand(time(nullptr));
    setlocale(LC_ALL, "Russian");
    Tr.MakeTree();
    if (Tr.exist()) {
        Tr.OutTree();
        std::cout << '\n' << "Обход в глубину: ";
        n = Tr.DFS();
        std::cout << " Пройдено узлов = " << n;
        std::cout << '\n' << "Обход в ширину: ";
        n = Tr.BFS();
        std::cout << " Пройдено узлов = " << n;
        std::cout << '\n' << "Внутренний обход: ";
        n = Tr.IFS();
        std::cout << " Пройдено узлов = " << n;
        n = Tr.task();
        std::cout << "\nУзлов с количеством потомков не больше 2: " << n;
    }
    else std::cout << "Дерево пусто!";
    std::cout << "\n=== Конец ===";
    return 0;
}