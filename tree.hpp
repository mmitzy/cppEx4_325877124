#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdexcept>
#include <algorithm>
#include <functional>

template <typename T>
class TreeNode {
public:
    T key;
    std::vector<TreeNode*> children;
    sf::Vector2f position;

    TreeNode(T key, int k) : key(key) {
        children.resize(k, nullptr);
    }
};

//Using template for generic type of data
template <typename T>
class Tree {
private:
    TreeNode<T>* root;
    int k;


//Recursive function to delete the tree
    void deleteTree(TreeNode<T>* node) {
        if (!node) return;
        for (auto child : node->children) {
            deleteTree(child);
        }
        delete node;
    }

//Recursive function to calculate the positions of the nodes
    void calculatePositions(TreeNode<T>* node, float& x, float y, float level_height, float sibling_distance) {
        if (!node) return;
        node->position = sf::Vector2f(x, y);
        float child_x = x - sibling_distance * (node->children.size() - 1) / 2;
        for (auto child : node->children) {
            calculatePositions(child, child_x, y + level_height, level_height, sibling_distance);
            child_x += sibling_distance;
        }
    }


public:
    Tree(int k = 2) : root(nullptr), k(k) {}
    ~Tree() {
        deleteTree(root);
    }

//Function to add the root node
    void add_root(T key) {
        if (root) {
            root->key = key;
        }
        else {
            root = new TreeNode<T>(key, k);
        }
    }

//Function to add the sub nodes
    void add_sub_node(T parent_key, T child_key) {
        TreeNode<T>* parent_node = find(root, parent_key);
        if (!parent_node) {
            throw std::runtime_error("Parent node not found");
        }
        for (auto& child : parent_node->children) {
            if (!child) {
                child = new TreeNode<T>(child_key, k);
                return;
            }
        }
        throw std::runtime_error("No available slot for child node");
    }

//Function to find the node
    TreeNode<T>* find(TreeNode<T>* node, T key) {
        if (!node) return nullptr;
        if (node->key == key) return node;
        for (auto child : node->children) {
            TreeNode<T>* res = find(child, key);
            if (res) return res;
        }
        return nullptr;
    }

//Function to calculate the positions of the nodes
    void calculate_tree_positions(float initial_x, float initial_y, float level_height, float sibling_distance) {
        float x = initial_x;
        calculatePositions(root, x, initial_y, level_height, sibling_distance);
    }

//Function to get the root node
    TreeNode<T>* get_root() {
        return root;
    }

//Iterator class to iterate through the tree
    class Iterator {
    public:
        virtual ~Iterator() {}
        virtual bool has_next() = 0;
        virtual T next() = 0;
    };

//PreOrderIterator class to iterate through the tree in pre-order
    class PreOrderIterator : public Iterator {
    private:
        std::stack<TreeNode<T>*> stack;
    public:
        PreOrderIterator(TreeNode<T>* root) {
            if (root) stack.push(root);
        }

        bool has_next() override {
            return !stack.empty();
        }

        T next() override {
            if (stack.empty()) throw std::out_of_range("No more elements");
            TreeNode<T>* node = stack.top();
            stack.pop();
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                if (*it) stack.push(*it);
            }
            return node->key;
        }
    };

//PostOrderIterator class to iterate through the tree in post-order
    class PostOrderIterator : public Iterator {
    private:
        std::stack<TreeNode<T>*> stack;
        std::stack<TreeNode<T>*> out;
    public:
        PostOrderIterator(TreeNode<T>* root) {
            if (root) stack.push(root);
            while (!stack.empty()) {
                TreeNode<T>* node = stack.top();
                stack.pop();
                out.push(node);
                for (auto child : node->children) {
                    if (child) stack.push(child);
                }
            }
        }

        bool has_next() override {
            return !out.empty();
        }

        T next() override {
            if (out.empty()) throw std::out_of_range("No more elements");
            TreeNode<T>* node = out.top();
            out.pop();
            return node->key;
        }
    };

//InOrderIterator class to iterate through the tree in in-order
    class InOrderIterator : public Iterator {
    private:
        std::stack<TreeNode<T>*> stack;
        TreeNode<T>* current;
    public:
        InOrderIterator(TreeNode<T>* root) : current(root) {
            while (current) {
                stack.push(current);
                current = current->children[0];
            }
        }

        bool has_next() override {
            return !stack.empty();
        }

        T next() override {
            if (stack.empty()) throw std::out_of_range("No more elements");
            current = stack.top();
            stack.pop();
            T result = current->key;
            current = current->children[1];
            while (current) {
                stack.push(current);
                current = current->children[0];
            }
            return result;
        }
    };

//BFSIterator class to iterate through the tree in BFS
    class BFSIterator : public Iterator {
    private:
        std::queue<TreeNode<T>*> queue;
    public:
        BFSIterator(TreeNode<T>* root) {
            if (root) queue.push(root);
        }

        bool has_next() override {
            return !queue.empty();
        }

        T next() override {
            if (queue.empty()) throw std::out_of_range("No more elements");
            TreeNode<T>* node = queue.front();
            queue.pop();
            for (auto child : node->children) {
                if (child) queue.push(child);
            }
            return node->key;
        }
    };


//DFSIterator class to iterate through the tree in DFS
    class DFSIterator : public Iterator {
    private:
        std::stack<TreeNode<T>*> stack;
    public:
        DFSIterator(TreeNode<T>* root) {
            if (root) stack.push(root);
        }

        bool has_next() override {
            return !stack.empty();
        }

        T next() override {
            if (stack.empty()) throw std::out_of_range("No more elements");
            TreeNode<T>* node = stack.top();
            stack.pop();
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                if (*it) stack.push(*it);
            }
            return node->key;
        }
    };

//HeapIterator class to iterate through the tree in heap order
    class HeapIterator : public Iterator {
    private:
        std::vector<T> heap;
        size_t index;
    public:
        HeapIterator(TreeNode<T>* root) : index(0) {
            std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
            buildHeap(root, pq);
            while (!pq.empty()) {
                heap.push_back(pq.top());
                pq.pop();
            }
        }

//Function to build the heap
        void buildHeap(TreeNode<T>* node, std::priority_queue<T, std::vector<T>, std::greater<T>>& pq) {
            if (!node) return;
            pq.push(node->key);
            for (auto child : node->children) {
                buildHeap(child, pq);
            }
        }

        bool has_next() override {
            return index < heap.size();
        }

        T next() override {
            if (index >= heap.size()) throw std::out_of_range("No more elements");
            return heap[index++];
        }
    };

//Function to get the iterators
    Iterator* begin_pre_order() {
        return new PreOrderIterator(root);
    }
    Iterator* begin_post_order() {
        return new PostOrderIterator(root);
    }

    Iterator* begin_in_order() {
        if (k != 2) {
            return new DFSIterator(root);
        }
        else { 
            return new InOrderIterator(root);
        }
    }

    Iterator* begin_bfs_scan() {
        return new BFSIterator(root);
    }

    Iterator* begin_dfs_scan() {
        return new DFSIterator(root);
    }

    Iterator* myHeap() {
        return new HeapIterator(root);
    }


//Function to print the tree
    void print() {
        if (!root) return;
        std::queue<TreeNode<T>*> q;
        q.push(root);
        while (!q.empty()) {
            int level_size = q.size();
            for (int i = 0; i < level_size; ++i) {
                TreeNode<T>* node = q.front();
                q.pop();
                std::cout << node->key << " ";
                for (auto child : node->children) {
                    if (child) q.push(child);
                }
            }
            std::cout << std::endl;
        }
    }
};

//TreeRenderer class to render the tree
template <typename T>
class TreeRenderer {
private:
    Tree<T>& tree;
    sf::RenderWindow window;
    float node_radius;
    sf::Font font;

    void drawNode(sf::RenderWindow& window, TreeNode<T>* node) {
        if (!node) return;

        sf::CircleShape circle(node_radius / 1.5);
        circle.setFillColor(sf::Color::White);
        circle.setOutlineColor(sf::Color::Green);
        circle.setOutlineThickness(2);
        circle.setPosition(node->position.x - node_radius / 1.5, node->position.y - node_radius / 1.5);

        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(node->key));
        text.setCharacterSize(12);
        text.setFillColor(sf::Color::Black);
        text.setPosition(node->position.x - node_radius / 3.5, node->position.y - node_radius / 3.5);



        for (auto child : node->children) {
            if (child) {
                sf::Vertex line[] =
                {
                    sf::Vertex(node->position, sf::Color::Black),
                    sf::Vertex(child->position, sf::Color::Black)
                };
                window.draw(line, 2, sf::Lines);
                drawNode(window, child);
            }
        }

        window.draw(circle);
        window.draw(text);
    }

public:
    TreeRenderer(Tree<T>& tree, int window_width, int window_height, float node_radius)
        : tree(tree), window(sf::VideoMode(window_width, window_height), "Tree Visualization"), node_radius(node_radius) {
        if (!font.loadFromFile("font.ttf")) {
            throw std::runtime_error("Failed to load font");
        }
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);
            drawNode(window, tree.get_root());
            window.display();
        }
    }
};
