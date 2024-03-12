#include "binaryTree.h"
#include <iostream>

using namespace std;

template<typename T>
BST<T>::BST() : root(nullptr) {}

template<typename T>
void BST<T>::insert(T data) {
    root = insertRecursive(root, data);
}

template<typename T>
Node<T>* insertRecursive(Node<T>* node, T data) {
    if (node == nullptr) {
        node = new Node<T>;
        node->data = data;
        node->left = node->right = nullptr;
    } else if (data < node->data) {
        node->left = insertRecursive(node->left, data);
    } else if (data > node->data) {
        node->right = insertRecursive(node->right, data);
    }
    return node;
}

template<typename T>
bool BST<T>::search(T key) {
    return searchRecursive(root, key);
}

template<typename T>
bool searchRecursive(Node<T>* node, T key) {
    if (node == nullptr) {
        return false;
    }

    if (key == node->data) {
        return true;
    } else if (key < node->data) {
        return searchRecursive(node->left, key);
    } else {
        return searchRecursive(node->right, key);
    }
}

template<typename T>
void BST<T>::remove(T key) {
    root = removeRecursive(root, key);
}

template<typename T>
Node<T>* removeRecursive(Node<T>* node, T key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->data) {
        node->left = removeRecursive(node->left, key);
    } else if (key > node->data) {
        node->right = removeRecursive(node->right, key);
    } else {
        if (node->left == nullptr) {
            Node<T>* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node<T>* temp = node->left;
            delete node;
            return temp;
        }

        Node<T>* temp = findMinNode(node->right);
        node->data = temp->data;
        node->right = removeRecursive(node->right, temp->data);
    }
    return node;
}

template<typename T>
Node<T>* findMinNode(Node<T>* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template<typename T>
void BST<T>::inorderTraversal() {
    inorderRecursive(root);
    cout << endl;
}

template<typename T>
void inorderRecursive(Node<T>* node) {
    if (node != nullptr) {
        inorderRecursive(node->left);
        cout << node->data << " ";
        inorderRecursive(node->right);
    }
}

template<typename T>
void BST<T>::preorderTraversal() {
    preorderRecursive(root);
    cout << endl;
}

template<typename T>
void preorderRecursive(Node<T>* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }
}

template<typename T>
void BST<T>::postorderTraversal() {
    postorderRecursive(root);
    cout << endl;
}

template<typename T>
void postorderRecursive(Node<T>* node) {
    if (node != nullptr) {
        postorderRecursive(node->left);
        postorderRecursive(node->right);
        cout << node->data << " ";
    }
}

template<typename T>
int BST<T>::findMin() {
    Node<T>* minNode = findMinNode(root);
    return minNode != nullptr ? minNode->data : -1;
}

template<typename T>
int BST<T>::findMax() {
    Node<T>* maxNode = findMaxNode(root);
    return maxNode != nullptr ? maxNode->data : -1;
    }

template<typename T>
Node<T>* findMaxNode(Node<T>* node) {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

template<typename T>
int BST<T>::getHeight() {
    return calculateHeight(root);
}

template<typename T>
int calculateHeight(Node<T>* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);

    return 1 + max(leftHeight, rightHeight);
}

template<typename T>
BST<T>::~BST() {
    destroyTree(root);
}

template<typename T>
void destroyTree(Node<T>* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}
