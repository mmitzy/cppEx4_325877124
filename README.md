## Project Structure and Main Points
# TreeNode Class

The TreeNode class represents a node in a tree. Each node has a key and a list of children.
InOrderIterator Class

The InOrderIterator class is used to traverse a tree with more than two children per node in an in-order manner. In-order traversal for a tree with more than two children can be defined as visiting the node after visiting its first half of children, then visiting the remaining children. Here’s how it works:

    Stack Management: The iterator uses a stack to manage the traversal state, with each stack entry being a pair of a node and the index of the next child to visit.
    Initialization: The constructor initializes the stack with the root node and starts moving to the leftmost node using the move_to_leftmost method.
    move_to_leftmost Method: This method traverses the tree to the leftmost node, pushing nodes onto the stack as it goes.
    has_next Method: Returns whether there are more nodes to visit.
    next Method: Returns the key of the current node and moves to the next node.

# PreOrderIterator Class

The PreOrderIterator class is used to traverse a tree with more than two children per node in a pre-order manner. Pre-order traversal involves visiting the root node first, then recursively visiting all the children. Here’s how it works:

    Stack Management: The iterator uses a stack to manage the traversal state.
    Initialization: The constructor initializes the stack with the root node.
    has_next Method: Returns whether there are more nodes to visit.
    next Method: Returns the key of the current node and moves to the next node, pushing all children of the current node onto the stack in reverse order.

# PostOrderIterator Class

The PostOrderIterator class is used to traverse a tree with more than two children per node in a post-order manner. Post-order traversal involves visiting all the children first, then visiting the root node. Here’s how it works:

    Stack Management: The iterator uses two stacks to manage the traversal state.
    Initialization: The constructor initializes the first stack with the root node.
    has_next Method: Returns whether there are more nodes to visit.
    next Method: Returns the key of the current node and moves to the next node by transferring nodes from the first stack to the second stack in the correct order.

# Complex Class

The Complex class provides functionality for complex number operations, including addition, subtraction, and multiplication. This class encapsulates the real and imaginary parts of a complex number and overloads operators to enable arithmetic operations.
