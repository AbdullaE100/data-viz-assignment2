#include <iostream>
#include <string>
#include "Email.h"
#include "Stack.h"  // Include Stack.h instead of Stack.cpp

template <typename K, typename V>
class Map {
private:
    struct Node {
        K key;
        V value;
        Node* left;
        Node* right;

        Node(K k, V v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, K key, V value) {
        if (node == nullptr) {
            return new Node(key, value);
        }

        if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        } else {
            node->value = value; // Key already exists, update value
        }
        return node;
    }

    Node* find(Node* node, K key) const {
        if (node == nullptr || node->key == key) {
            return node;
        }

        if (key < node->key) {
            return find(node->left, key);
        } else {
            return find(node->right, key);
        }
    }

    void inOrder(Node* node) const {
        if (node != nullptr) {
            inOrder(node->left);
            std::cout << node->key << ": " << node->value.getName() << std::endl;
            inOrder(node->right);
        }
    }

    void destroy(Node* node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

public:
    Map() : root(nullptr) {}

    ~Map() {
        destroy(root);
    }

    void insert(K key, V& value) {
        root = insert(root, key, value);
    }

    bool find(K key, V& value) const {
        Node* node = find(root, key);
        if (node) {
            value = node->value;
            return true;
        }
        return false;
    }

    // Iterator class for in-order traversal
    class Iterator {
    private:
        Stack<Node> nodeStack;

        void pushLeft(Node* node) {
            while (node) {
                nodeStack.push(node);
                node = node->left;
            }
        }

    public:
        Iterator(Node* root) {
            pushLeft(root);  // Start with the leftmost node
        }

        bool operator!=(const Iterator& other) const {
            return nodeStack != other.nodeStack;
        }

        Iterator& operator++() {
            if (!nodeStack.isEmpty()) {
                Node* node = nodeStack.peek();
                nodeStack.pop();
                if (node->right) {
                    pushLeft(node->right);
                }
            }
            return *this;
        }

        std::pair<K, V> operator*() const {
            Node* node = nodeStack.peek();
            return { node->key, node->value };
        }
    };

    Iterator begin() const {
        return Iterator(root);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }
};
