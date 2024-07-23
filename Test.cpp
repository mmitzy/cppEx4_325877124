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