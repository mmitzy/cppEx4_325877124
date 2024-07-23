#include <iostream>
#include "tree.hpp"
#include "complex.hpp"


//Basically the demo
int main() {
    Tree<int> intTree(3); // Set the tree branching factor
    intTree.add_root(1);

    intTree.add_sub_node(1, 2);
    intTree.add_sub_node(1, 3);
    intTree.add_sub_node(1, 4);
    intTree.add_sub_node(2, 5);
    intTree.add_sub_node(3, 6);
    intTree.add_sub_node(3, 7);


    std::cout << "Pre-Order Traversal: ";
    auto preOrderIter = intTree.begin_pre_order();
    while (preOrderIter->has_next()) {
        std::cout << preOrderIter->next() << " ";
    }
    std::cout << std::endl;
    delete preOrderIter;

    std::cout << "Post-Order Traversal: ";
    auto postOrderIter = intTree.begin_post_order();
    while (postOrderIter->has_next()) {
        std::cout << postOrderIter->next() << " ";
    }
    std::cout << std::endl;
    delete postOrderIter;

    std::cout << "In-Order Traversal: ";
    auto inOrderIter = intTree.begin_in_order();
    while (inOrderIter->has_next()) {
        std::cout << inOrderIter->next() << " ";
    }
    std::cout << std::endl;
    delete inOrderIter;

    std::cout << "BFS Traversal: ";
    auto bfsIter = intTree.begin_bfs_scan();
    while (bfsIter->has_next()) {
        std::cout << bfsIter->next() << " ";
    }
    std::cout << std::endl;
    delete bfsIter;

    std::cout << "DFS Traversal: ";
    auto dfsIter = intTree.begin_dfs_scan();
    while (dfsIter->has_next()) {
        std::cout << dfsIter->next() << " ";
    }
    std::cout << std::endl;
    delete dfsIter;

    std::cout << "Heap Traversal: ";
    auto heapIter = intTree.myHeap();
    while (heapIter->has_next()) {
        std::cout << heapIter->next() << " ";
    }
    std::cout << std::endl;
    delete heapIter;

    intTree.print();

    Tree<Complex> complexTree(3);
    complexTree.add_root(Complex(1, 1));
    complexTree.add_sub_node(Complex(1, 1), Complex(2, 2));
    complexTree.add_sub_node(Complex(1, 1), Complex(3, 3));
    complexTree.add_sub_node(Complex(2, 2), Complex(4, 4));
    complexTree.add_sub_node(Complex(2, 2), Complex(5, 5));

    std::cout << "Complex Tree Pre-Order Traversal: ";
    auto complexPreOrderIter = complexTree.begin_pre_order();
    while (complexPreOrderIter->has_next()) {
        std::cout << complexPreOrderIter->next() << " ";
    }
    std::cout << std::endl;
    delete complexPreOrderIter;

    intTree.calculate_tree_positions(400, 50, 100, 100);
    TreeRenderer<int> renderer(intTree, 800, 600, 20);
    renderer.run();

    return 0;
}
