#include "binaryTree.h"
#include <iostream>

using namespace std;

template <class T>
Node<T>::Node(T data) : data(data), left(nullptr), right(nullptr) {}

template <class T>
BST<T>::BST() : root(nullptr) {}

template <class T>
void BST<T>::insert(T data)
{
    root = insertRecursive(root, data);
}

template <class T>
Node<T> *insertRecursive(Node<T> *node, T data)
{
    if (node == nullptr)
    {
        node = new Node<T>(data);
    }
    else if (data < node->data)
    {
        node->left = insertRecursive(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insertRecursive(node->right, data);
    }
    return node;
}

template <class T>
bool BST<T>::search(T key)
{
    return searchRecursive(root, key);
}

template <class T>
bool searchRecursive(Node<T> *node, T key)
{
    if (node == nullptr)
    {
        return false;
    }

    if (key == node->data)
    {
        return true;
    }
    else if (key < node->data)
    {
        return searchRecursive(node->left, key);
    }
    else
    {
        return searchRecursive(node->right, key);
    }
}

template <class T>
void BST<T>::remove(T key)
{
    root = removeRecursive(root, key);
}

template <class T>
Node<T> *removeRecursive(Node<T> *node, T key)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (key < node->data)
    {
        node->left = removeRecursive(node->left, key);
    }
    else if (key > node->data)
    {
        node->right = removeRecursive(node->right, key);
    }
    else
    {
        if (node->left == nullptr)
            return node->right;
        else if (node->right == nullptr)
            return node->left;

        Node<T> *temp = findMinNode(node->right);
        node->data = temp->data;
        node->right = removeRecursive(node->right, temp->data);
    }

    return node;
}

template <class T>
Node<T> *findMinNode(Node<T> *node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

template <class T>
void BST<T>::inorderTraversal()
{
    inorderRecursive(root);
    cout << endl;
}

template <class T>
void inorderRecursive(Node<T> *node)
{
    if (node != nullptr)
    {
        inorderRecursive(node->left);
        cout << node->data << " ";
        inorderRecursive(node->right);
    }
}

template <class T>
void BST<T>::preorderTraversal()
{
    preorderRecursive(root);
    cout << endl;
}

template <class T>
void preorderRecursive(Node<T> *node)
{
    if (node != nullptr)
    {
        cout << node->data << " ";
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }
}

template <class T>
void BST<T>::postorderTraversal()
{
    postorderRecursive(root);
    cout << endl;
}

template <class T>
void postorderRecursive(Node<T> *node)
{
    if (node != nullptr)
    {
        postorderRecursive(node->left);
        postorderRecursive(node->right);
        cout << node->data << " ";
    }
}

template <class T>
int BST<T>::findMin()
{
    Node<T> *minNode = findMinNode(root);
    return minNode != nullptr ? minNode->data : -1;
}

template <class T>
int BST<T>::findMax()
{
    Node<T> *maxNode = findMaxNode(root);
    return maxNode != nullptr ? maxNode->data : -1;
}

template <class T>
Node<T> *findMaxNode(Node<T> *node)
{
    while (node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}

template <class T>
int BST<T>::getHeight()
{
    return calculateHeight(root);
}

template <class T>
int calculateHeight(Node<T> *node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);

    return 1 + max(leftHeight, rightHeight);
}

template <class T>
BST<T>::~BST()
{
    destroyTree(root);
}

template <class T>
void destroyTree(Node<T> *node)
{
    if (node != nullptr)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}
template<class T>
void BST<T>::bfsTraversal() {
    if (root == nullptr) {
        return;
    }

    queue<Node<T>*> bfsQueue;
    bfsQueue.push(root);

    while (!bfsQueue.empty()) {
        Node<T>* current = bfsQueue.front();
        cout << current->data << " ";
        bfsQueue.pop();

        if (current->left != nullptr) {
            bfsQueue.push(current->left);
        }

        if (current->right != nullptr) {
            bfsQueue.push(current->right);
        }
    }
}

