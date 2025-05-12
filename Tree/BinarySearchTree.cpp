#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (node->data > data) {
            node->left = insert(node->left, data);
        } else if (node->data < data) {
            node->right = insert(node->right, data);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    
    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    bool search(Node* node, int key) {
        if (node == nullptr) return false;
        if (node->data ==  key) return true;
        if (node->data > key) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }
};

int main() {
    BST bst;
    bst.root = bst.insert(bst.root, 40);
    bst.root = bst.insert(bst.root, 20);
    bst.root = bst.insert(bst.root, 60);
    bst.root = bst.insert(bst.root, 10);
    bst.root = bst.insert(bst.root, 30);
    bst.root = bst.insert(bst.root, 50);
    bst.root = bst.insert(bst.root, 70);

    cout << "Inorder: ";
    bst.inorder(bst.root);
    cout << endl;
    cout << "Preorder: ";
    bst.preorder(bst.root);
    cout << endl;
    cout << "Postorder: ";
    bst.postorder(bst.root);

    int key = 30;
    cout << endl;
    cout << "Searching for " << key << ": ";
    cout << (bst.search(bst.root, key) ? "Found" : "Not Found") << endl;
    return 0;
}
