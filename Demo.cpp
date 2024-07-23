/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "tree.hpp"
#include "node.hpp"

using namespace std;

int main()
{

    Tree<double> tree; // Binary tree that contains doubles.
    
    tree.add_root(1.1);

    tree.add_sub_node(1.1, 1.2);
    tree.add_sub_node(1.1, 1.3);
    tree.add_sub_node(1.2, 1.4);
    tree.add_sub_node(1.2, 1.5);
    tree.add_sub_node(1.3, 1.6);
   
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */


    cout<<"Pre order traversal: \n";
    // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    auto preOrderIter = tree.begin_pre_order();
    while (preOrderIter->has_next()) {
        std::cout << preOrderIter->next() << " ";
    }
    std::cout << std::endl;
    delete preOrderIter;

    cout<<"Post order traversal: \n";
    // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    auto postOrderIter = tree.begin_post_order();
    while (postOrderIter->has_next()) {
        std::cout << postOrderIter->next() << " ";
    }
    std::cout << std::endl;
    delete postOrderIter;

    cout<<"In order traversal: \n";
    // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    auto inOrderIter = tree.begin_in_order();
    while (inOrderIter->has_next()) {
        std::cout << inOrderIter->next() << " ";
    }
    cout<<endl;
    delete inOrderIter;

    cout<<"bfs scan:"<<endl;
    // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    auto bfsIter = tree.begin_bfs_scan();
    while (bfsIter->has_next()) {
        std::cout << bfsIter->next() << " ";
    }
    cout<<endl;
    delete bfsIter;

    cout<<"dfs scan:"<<endl;
    // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    auto dfsIter = tree.begin_dfs_scan();
    while (dfsIter->has_next()) {
        std::cout << dfsIter->next() << " ";
    }
    cout<<endl;
    delete dfsIter;

    cout << "Min-Heap Traversal:" << endl;
    // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    auto heapIter = tree.myHeap();
    while (heapIter->has_next()) {
        std::cout << heapIter->next() << " ";
    }
    cout << endl;
    delete heapIter;
    // cout << tree; // Should print the graph using GUI.

    // Tree<double> three_ary_tree(3); // 3-ary tree.
    // three_ary_tree.add_root(root_node);
    // for (auto neighbor : three_ary_tree.getRoot()->neighbors)
    // {
    //     cout << neighbor->get_value() << " ";
    // } // prints: 1.2, 1.3, 1.4
    // three_ary_tree.add_sub_node(root_node, n1);
    // three_ary_tree.add_sub_node(root_node, n2);
    // three_ary_tree.add_sub_node(root_node, n3);
    // three_ary_tree.add_sub_node(n1, n4);
    // three_ary_tree.add_sub_node(n2, n5);
    // cout<<"In order traversal: \n";
    // for (auto node = three_ary_tree.begin_post_order(); node != three_ary_tree.end_post_order(); ++node)
    // {
    //     cout << node->get_value() << " ";
        
    // }
    // cout<<endl;
     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */
    return 0;
    
}