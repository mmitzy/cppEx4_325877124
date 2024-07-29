//dani.bendav@gmail.com 325877124

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tree.hpp"
#include "complex.hpp"
#include <iostream>

using namespace std;
 
    TEST_CASE("pre order traversal") {
        Tree<double> tree; // Binary tree that contains doubles.
        tree.add_root(1.1);

        tree.add_sub_node(1.1, 1.2);
        tree.add_sub_node(1.1, 1.3);
        tree.add_sub_node(1.2, 1.4);
        tree.add_sub_node(1.2, 1.5);
        tree.add_sub_node(1.3, 1.6);
        auto preOrderIter = tree.begin_pre_order();
        CHECK(preOrderIter->next() == 1.1);
        CHECK(preOrderIter->next() == 1.2);
        CHECK(preOrderIter->next() == 1.4);
        CHECK(preOrderIter->next() == 1.5);
        CHECK(preOrderIter->next() == 1.3);
        CHECK(preOrderIter->next() == 1.6);
        delete preOrderIter;
    }

    TEST_CASE("post order traversal") {
        Tree<double> tree; // Binary tree that contains doubles.
        tree.add_root(1.1);

        tree.add_sub_node(1.1, 1.2);
        tree.add_sub_node(1.1, 1.3);
        tree.add_sub_node(1.2, 1.4);
        tree.add_sub_node(1.2, 1.5);
        tree.add_sub_node(1.3, 1.6);
        auto postOrderIter = tree.begin_post_order();
        CHECK(postOrderIter->next() == 1.4);
        CHECK(postOrderIter->next() == 1.5);
        CHECK(postOrderIter->next() == 1.2);
        CHECK(postOrderIter->next() == 1.6);
        CHECK(postOrderIter->next() == 1.3);
        CHECK(postOrderIter->next() == 1.1);
        delete postOrderIter;
    }

    TEST_CASE("in order traversal") {
        Tree<double> tree; // Binary tree that contains doubles.
        tree.add_root(1.1);

        tree.add_sub_node(1.1, 1.2);
        tree.add_sub_node(1.1, 1.3);
        tree.add_sub_node(1.2, 1.4);
        tree.add_sub_node(1.2, 1.5);
        tree.add_sub_node(1.3, 1.6);
        auto inOrderIter = tree.begin_in_order();
        CHECK(inOrderIter->next() == 1.4);
        CHECK(inOrderIter->next() == 1.2);
        CHECK(inOrderIter->next() == 1.5);
        CHECK(inOrderIter->next() == 1.1);
        CHECK(inOrderIter->next() == 1.6);
        CHECK(inOrderIter->next() == 1.3);
        delete inOrderIter;
    }

    TEST_CASE("bfs scan") {
        Tree<double> tree; // Binary tree that contains doubles.
        tree.add_root(1.1);

        tree.add_sub_node(1.1, 1.2);
        tree.add_sub_node(1.1, 1.3);
        tree.add_sub_node(1.2, 1.4);
        tree.add_sub_node(1.2, 1.5);
        tree.add_sub_node(1.3, 1.6);
        auto bfsIter = tree.begin_bfs_scan();
        CHECK(bfsIter->next() == 1.1);
        CHECK(bfsIter->next() == 1.2);
        CHECK(bfsIter->next() == 1.3);
        CHECK(bfsIter->next() == 1.4);
        CHECK(bfsIter->next() == 1.5);
        CHECK(bfsIter->next() == 1.6);
        delete bfsIter;
    }

    TEST_CASE("dfs scan") {
        Tree<double> tree; // Binary tree that contains doubles.
        tree.add_root(1.1);

        tree.add_sub_node(1.1, 1.2);
        tree.add_sub_node(1.1, 1.3);
        tree.add_sub_node(1.2, 1.4);
        tree.add_sub_node(1.2, 1.5);
        tree.add_sub_node(1.3, 1.6);
        auto dfsIter = tree.begin_dfs_scan();
        CHECK(dfsIter->next() == 1.1);
        CHECK(dfsIter->next() == 1.2);
        CHECK(dfsIter->next() == 1.4);
        CHECK(dfsIter->next() == 1.5);
        CHECK(dfsIter->next() == 1.3);
        CHECK(dfsIter->next() == 1.6);
        delete dfsIter;
    }

    TEST_CASE("heap traversal") {
        Tree<double> tree; // Binary tree that contains doubles.
        tree.add_root(1.1);

        tree.add_sub_node(1.1, 1.2);
        tree.add_sub_node(1.1, 1.3);
        tree.add_sub_node(1.2, 1.4);
        tree.add_sub_node(1.2, 1.5);
        tree.add_sub_node(1.3, 1.6);
        auto heapIter = tree.myHeap();
        CHECK(heapIter->next() == 1.1);
        CHECK(heapIter->next() == 1.2);
        CHECK(heapIter->next() == 1.3);
        CHECK(heapIter->next() == 1.4);
        CHECK(heapIter->next() == 1.5);
        CHECK(heapIter->next() == 1.6);
        delete heapIter;
    }

    TEST_CASE("pre order traversal with complex numbers") {
        Tree<Complex> tree; // Binary tree that contains complex numbers.
        tree.add_root(Complex(1, 1));

        tree.add_sub_node(Complex(1, 1), Complex(1, 2));
        tree.add_sub_node(Complex(1, 1), Complex(1, 3));
        tree.add_sub_node(Complex(1, 2), Complex(1, 4));
        tree.add_sub_node(Complex(1, 2), Complex(1, 5));
        tree.add_sub_node(Complex(1, 3), Complex(1, 6));
        auto preOrderIter = tree.begin_pre_order();
        CHECK(preOrderIter->next() == Complex(1, 1));
        CHECK(preOrderIter->next() == Complex(1, 2));
        CHECK(preOrderIter->next() == Complex(1, 4));
        CHECK(preOrderIter->next() == Complex(1, 5));
        CHECK(preOrderIter->next() == Complex(1, 3));
        CHECK(preOrderIter->next() == Complex(1, 6));
        delete preOrderIter;
    }

    TEST_CASE("post order traversal with complex numbers") {
        Tree<Complex> tree; // Binary tree that contains complex numbers.
        tree.add_root(Complex(1, 1));

        tree.add_sub_node(Complex(1, 1), Complex(1, 2));
        tree.add_sub_node(Complex(1, 1), Complex(1, 3));
        tree.add_sub_node(Complex(1, 2), Complex(1, 4));
        tree.add_sub_node(Complex(1, 2), Complex(1, 5));
        tree.add_sub_node(Complex(1, 3), Complex(1, 6));
        auto postOrderIter = tree.begin_post_order();
        CHECK(postOrderIter->next() == Complex(1, 4));
        CHECK(postOrderIter->next() == Complex(1, 5));
        CHECK(postOrderIter->next() == Complex(1, 2));
        CHECK(postOrderIter->next() == Complex(1, 6));
        CHECK(postOrderIter->next() == Complex(1, 3));
        CHECK(postOrderIter->next() == Complex(1, 1));
        delete postOrderIter;
    }

    TEST_CASE("in order traversal with complex numbers") {
        Tree<Complex> tree; // Binary tree that contains complex numbers.
        tree.add_root(Complex(1, 1));

        tree.add_sub_node(Complex(1, 1), Complex(1, 2));
        tree.add_sub_node(Complex(1, 1), Complex(1, 3));
        tree.add_sub_node(Complex(1, 2), Complex(1, 4));
        tree.add_sub_node(Complex(1, 2), Complex(1, 5));
        tree.add_sub_node(Complex(1, 3), Complex(1, 6));
        auto inOrderIter = tree.begin_in_order();
        CHECK(inOrderIter->next() == Complex(1, 4));
        CHECK(inOrderIter->next() == Complex(1, 2));
        CHECK(inOrderIter->next() == Complex(1, 5));
        CHECK(inOrderIter->next() == Complex(1, 1));
        CHECK(inOrderIter->next() == Complex(1, 6));
        CHECK(inOrderIter->next() == Complex(1, 3));
        delete inOrderIter;
    }

    TEST_CASE("bfs scan with complex numbers") {
        Tree<Complex> tree; // Binary tree that contains complex numbers.
        tree.add_root(Complex(1, 1));

        tree.add_sub_node(Complex(1, 1), Complex(1, 2));
        tree.add_sub_node(Complex(1, 1), Complex(1, 3));
        tree.add_sub_node(Complex(1, 2), Complex(1, 4));
        tree.add_sub_node(Complex(1, 2), Complex(1, 5));
        tree.add_sub_node(Complex(1, 3), Complex(1, 6));
        auto bfsIter = tree.begin_bfs_scan();
        CHECK(bfsIter->next() == Complex(1, 1));
        CHECK(bfsIter->next() == Complex(1, 2));
        CHECK(bfsIter->next() == Complex(1, 3));
        CHECK(bfsIter->next() == Complex(1, 4));
        CHECK(bfsIter->next() == Complex(1, 5));
        CHECK(bfsIter->next() == Complex(1, 6));
        delete bfsIter;
    }

    TEST_CASE("dfs scan with complex numbers") {
        Tree<Complex> tree; // Binary tree that contains complex numbers.
        tree.add_root(Complex(1, 1));

        tree.add_sub_node(Complex(1, 1), Complex(1, 2));
        tree.add_sub_node(Complex(1, 1), Complex(1, 3));
        tree.add_sub_node(Complex(1, 2), Complex(1, 4));
        tree.add_sub_node(Complex(1, 2), Complex(1, 5));
        tree.add_sub_node(Complex(1, 3), Complex(1, 6));
        auto dfsIter = tree.begin_dfs_scan();
        CHECK(dfsIter->next() == Complex(1, 1));
        CHECK(dfsIter->next() == Complex(1, 2));
        CHECK(dfsIter->next() == Complex(1, 4));
        CHECK(dfsIter->next() == Complex(1, 5));
        CHECK(dfsIter->next() == Complex(1, 3));
        CHECK(dfsIter->next() == Complex(1, 6));
        delete dfsIter;
    }

    TEST_CASE("heap traversal with complex numbers") {
        Tree<Complex> tree; // Binary tree that contains complex numbers.
        tree.add_root(Complex(1, 1));

        tree.add_sub_node(Complex(1, 1), Complex(1, 2));
        tree.add_sub_node(Complex(1, 1), Complex(1, 3));
        tree.add_sub_node(Complex(1, 2), Complex(1, 4));
        tree.add_sub_node(Complex(1, 2), Complex(1, 5));
        tree.add_sub_node(Complex(1, 3), Complex(1, 6));
        auto heapIter = tree.myHeap();
        CHECK(heapIter->next() == Complex(1, 1));
        CHECK(heapIter->next() == Complex(1, 2));
        CHECK(heapIter->next() == Complex(1, 3));
        CHECK(heapIter->next() == Complex(1, 4));
        CHECK(heapIter->next() == Complex(1, 5));
        CHECK(heapIter->next() == Complex(1, 6));
        delete heapIter;
    }

    TEST_CASE("pre order traversal with trinary"){
        Tree<int> intTree(3); // Set the tree branching factor
        intTree.add_root(1);

        intTree.add_sub_node(1, 2);
        intTree.add_sub_node(1, 3);
        intTree.add_sub_node(1, 4);
        intTree.add_sub_node(2, 5);
        intTree.add_sub_node(3, 6);
        intTree.add_sub_node(3, 7);

        auto preOrderIter = intTree.begin_pre_order();
        CHECK(preOrderIter->next() == 1);
        CHECK(preOrderIter->next() == 2);
        CHECK(preOrderIter->next() == 5);
        CHECK(preOrderIter->next() == 3);
        CHECK(preOrderIter->next() == 6);
        CHECK(preOrderIter->next() == 7);
        CHECK(preOrderIter->next() == 4);
        delete preOrderIter;
    }

    TEST_CASE("post order traversal with trinary"){
        Tree<int> intTree(3); // Set the tree branching factor
        intTree.add_root(1);

        intTree.add_sub_node(1, 2);
        intTree.add_sub_node(1, 3);
        intTree.add_sub_node(1, 4);
        intTree.add_sub_node(2, 5);
        intTree.add_sub_node(3, 6);
        intTree.add_sub_node(3, 7);

        auto postOrderIter = intTree.begin_post_order();
        CHECK(postOrderIter->next() == 5);
        CHECK(postOrderIter->next() == 2);
        CHECK(postOrderIter->next() == 6);
        CHECK(postOrderIter->next() == 7);
        CHECK(postOrderIter->next() == 3);
        CHECK(postOrderIter->next() == 4);
        CHECK(postOrderIter->next() == 1);
        delete postOrderIter;
    }

    TEST_CASE("in order traversal with trinary"){
        Tree<int> intTree(3); // Set the tree branching factor
        intTree.add_root(1);

        intTree.add_sub_node(1, 2);
        intTree.add_sub_node(1, 3);
        intTree.add_sub_node(1, 4);
        intTree.add_sub_node(2, 5);
        intTree.add_sub_node(3, 6);
        intTree.add_sub_node(3, 7);

        auto inOrderIter = intTree.begin_in_order();
        CHECK(inOrderIter->next() == 1);
        CHECK(inOrderIter->next() == 2);
        CHECK(inOrderIter->next() == 5);
        CHECK(inOrderIter->next() == 3);
        CHECK(inOrderIter->next() == 6);
        CHECK(inOrderIter->next() == 7);
        CHECK(inOrderIter->next() == 4);
        delete inOrderIter;
    }

    TEST_CASE("bfs scan with trinary"){
        Tree<int> intTree(3); // Set the tree branching factor
        intTree.add_root(1);

        intTree.add_sub_node(1, 2);
        intTree.add_sub_node(1, 3);
        intTree.add_sub_node(1, 4);
        intTree.add_sub_node(2, 5);
        intTree.add_sub_node(3, 6);
        intTree.add_sub_node(3, 7);

        auto bfsIter = intTree.begin_bfs_scan();
        CHECK(bfsIter->next() == 1);
        CHECK(bfsIter->next() == 2);
        CHECK(bfsIter->next() == 3);
        CHECK(bfsIter->next() == 4);
        CHECK(bfsIter->next() == 5);
        CHECK(bfsIter->next() == 6);
        CHECK(bfsIter->next() == 7);
        delete bfsIter;
    }

    TEST_CASE("dfs scan with trinary"){
        Tree<int> intTree(3); // Set the tree branching factor
        intTree.add_root(1);

        intTree.add_sub_node(1, 2);
        intTree.add_sub_node(1, 3);
        intTree.add_sub_node(1, 4);
        intTree.add_sub_node(2, 5);
        intTree.add_sub_node(3, 6);
        intTree.add_sub_node(3, 7);

        auto dfsIter = intTree.begin_dfs_scan();
        CHECK(dfsIter->next() == 1);
        CHECK(dfsIter->next() == 2);
        CHECK(dfsIter->next() == 5);
        CHECK(dfsIter->next() == 3);
        CHECK(dfsIter->next() == 6);
        CHECK(dfsIter->next() == 7);
        CHECK(dfsIter->next() == 4);
        delete dfsIter;
    }

    TEST_CASE("heap traversal with trinary"){
        Tree<int> intTree(3); // Set the tree branching factor
        intTree.add_root(1);

        intTree.add_sub_node(1, 2);
        intTree.add_sub_node(1, 3);
        intTree.add_sub_node(1, 4);
        intTree.add_sub_node(2, 5);
        intTree.add_sub_node(3, 6);
        intTree.add_sub_node(3, 7);

        auto heapIter = intTree.myHeap();
        CHECK(heapIter->next() == 1);
        CHECK(heapIter->next() == 2);
        CHECK(heapIter->next() == 3);
        CHECK(heapIter->next() == 4);
        CHECK(heapIter->next() == 5);
        CHECK(heapIter->next() == 6);
        CHECK(heapIter->next() == 7);
        delete heapIter;
    }

    TEST_CASE("pre order traversal with trinary and complex numbers"){
        Tree<Complex> tree(3); // Set the tree branching factor
        tree.add_root(Complex(1, 1));

        tree.add_sub_node(Complex(1, 1), Complex(1, 2));
        tree.add_sub_node(Complex(1, 1), Complex(1, 3));
        tree.add_sub_node(Complex(1, 1), Complex(1, 4));
        tree.add_sub_node(Complex(1, 2), Complex(1, 5));
        tree.add_sub_node(Complex(1, 3), Complex(1, 6));
        tree.add_sub_node(Complex(1, 3), Complex(1, 7));

        auto preOrderIter = tree.begin_pre_order();
        CHECK(preOrderIter->next() == Complex(1, 1));
        CHECK(preOrderIter->next() == Complex(1, 2));
        CHECK(preOrderIter->next() == Complex(1, 5));
        CHECK(preOrderIter->next() == Complex(1, 3));
        CHECK(preOrderIter->next() == Complex(1, 6));
        CHECK(preOrderIter->next() == Complex(1, 7));
        CHECK(preOrderIter->next() == Complex(1, 4));
        delete preOrderIter;
    }

    TEST_CASE("post order traversal with trinary and complex numbers"){
        Tree<Complex> tree(3); // Set the tree branching factor
        tree.add_root(Complex(1, 1));

        tree.add_sub_node(Complex(1, 1), Complex(1, 2));
        tree.add_sub_node(Complex(1, 1), Complex(1, 3));
        tree.add_sub_node(Complex(1, 1), Complex(1, 4));
        tree.add_sub_node(Complex(1, 2), Complex(1, 5));
        tree.add_sub_node(Complex(1, 3), Complex(1, 6));
        tree.add_sub_node(Complex(1, 3), Complex(1, 7));

        auto postOrderIter = tree.begin_post_order();
        CHECK(postOrderIter->next() == Complex(1, 5));
        CHECK(postOrderIter->next() == Complex(1, 2));
        CHECK(postOrderIter->next() == Complex(1, 6));
        CHECK(postOrderIter->next() == Complex(1, 7));
        CHECK(postOrderIter->next() == Complex(1, 3));
        CHECK(postOrderIter->next() == Complex(1, 4));
        CHECK(postOrderIter->next() == Complex(1, 1));
        delete postOrderIter;
    }

    TEST_CASE("in order traversal with trinary and complex numbers"){
        Tree<Complex> tree(3); // Set the tree branching factor
        tree.add_root(Complex(1, 1));

        tree.add_sub_node(Complex(1, 1), Complex(1, 2));
        tree.add_sub_node(Complex(1, 1), Complex(1, 3));
        tree.add_sub_node(Complex(1, 1), Complex(1, 4));
        tree.add_sub_node(Complex(1, 2), Complex(1, 5));
        tree.add_sub_node(Complex(1, 3), Complex(1, 6));
        tree.add_sub_node(Complex(1, 3), Complex(1, 7));

        auto inOrderIter = tree.begin_in_order();
        CHECK(inOrderIter->next() == Complex(1, 1));
        CHECK(inOrderIter->next() == Complex(1, 2));
        CHECK(inOrderIter->next() == Complex(1, 5));
        CHECK(inOrderIter->next() == Complex(1, 3));
        CHECK(inOrderIter->next() == Complex(1, 6));
        CHECK(inOrderIter->next() == Complex(1, 7));
        CHECK(inOrderIter->next() == Complex(1, 4));
        delete inOrderIter;
    }
    
    TEST_CASE("bfs scan with trinary and complex numbers"){
        Tree<Complex> tree(3); // Set the tree branching factor
        tree.add_root(Complex(1, 1));

        tree.add_sub_node(Complex(1, 1), Complex(1, 2));
        tree.add_sub_node(Complex(1, 1), Complex(1, 3));
        tree.add_sub_node(Complex(1, 1), Complex(1, 4));
        tree.add_sub_node(Complex(1, 2), Complex(1, 5));
        tree.add_sub_node(Complex(1, 3), Complex(1, 6));
        tree.add_sub_node(Complex(1, 3), Complex(1, 7));

        auto bfsIter = tree.begin_bfs_scan();
        CHECK(bfsIter->next() == Complex(1, 1));
        CHECK(bfsIter->next() == Complex(1, 2));
        CHECK(bfsIter->next() == Complex(1, 3));
        CHECK(bfsIter->next() == Complex(1, 4));
        CHECK(bfsIter->next() == Complex(1, 5));
        CHECK(bfsIter->next() == Complex(1, 6));
        CHECK(bfsIter->next() == Complex(1, 7));
        delete bfsIter;
    }

    TEST_CASE("dfs scan with trinary and complex numbers"){
        Tree<Complex> tree(3); // Set the tree branching factor
        tree.add_root(Complex(1, 1));

        tree.add_sub_node(Complex(1, 1), Complex(1, 2));
        tree.add_sub_node(Complex(1, 1), Complex(1, 3));
        tree.add_sub_node(Complex(1, 1), Complex(1, 4));
        tree.add_sub_node(Complex(1, 2), Complex(1, 5));
        tree.add_sub_node(Complex(1, 3), Complex(1, 6));
        tree.add_sub_node(Complex(1, 3), Complex(1, 7));

        auto dfsIter = tree.begin_dfs_scan();
        CHECK(dfsIter->next() == Complex(1, 1));
        CHECK(dfsIter->next() == Complex(1, 2));
        CHECK(dfsIter->next() == Complex(1, 5));
        CHECK(dfsIter->next() == Complex(1, 3));
        CHECK(dfsIter->next() == Complex(1, 6));
        CHECK(dfsIter->next() == Complex(1, 7));
        CHECK(dfsIter->next() == Complex(1, 4));
        delete dfsIter;
    }

    TEST_CASE("heap traversal with trinary and complex numbers"){
        Tree<Complex> tree(3); // Set the tree branching factor
        tree.add_root(Complex(1, 1));

        tree.add_sub_node(Complex(1, 1), Complex(1, 2));
        tree.add_sub_node(Complex(1, 1), Complex(1, 3));
        tree.add_sub_node(Complex(1, 1), Complex(1, 4));
        tree.add_sub_node(Complex(1, 2), Complex(1, 5));
        tree.add_sub_node(Complex(1, 3), Complex(1, 6));
        tree.add_sub_node(Complex(1, 3), Complex(1, 7));

        auto heapIter = tree.myHeap();
        CHECK(heapIter->next() == Complex(1, 1));
        CHECK(heapIter->next() == Complex(1, 2));
        CHECK(heapIter->next() == Complex(1, 3));
        CHECK(heapIter->next() == Complex(1, 4));
        CHECK(heapIter->next() == Complex(1, 5));
        CHECK(heapIter->next() == Complex(1, 6));
        CHECK(heapIter->next() == Complex(1, 7));
        delete heapIter;
    }
