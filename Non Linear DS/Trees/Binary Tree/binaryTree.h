#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template <typename T>
class Node
{
public:
    T data;
    Node<T> *left;
    Node<T> *right;
};

template <typename T>
class BST
{
private:
    Node<T> *root;

public:
    BST();
    void insert(T data);
    bool search(T key);
    void remove(T key);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    int findMin();
    int findMax();
    int getHeight();
};
#endif