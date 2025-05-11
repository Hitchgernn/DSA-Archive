#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;

    Node (int data) {
        this->data = data; 
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedlist {
private:
    Node *head, *tail;

public:
    DoublyLinkedlist() {
        head = nullptr; tail = nullptr;
    }

    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtTail(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAfterNode(int target, int data) {
        Node* newNode = new Node(data);
        Node* cur = head;
        while (cur != nullptr && cur->data != target) {
            cur = cur->next;
        } 
        if (cur == nullptr) {
            cout << "Not found" << endl;
            return;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        newNode->prev = cur;

        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        } else {
            tail = newNode;
        }
    }
    void deleteAtHead() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* delNode = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete delNode;
    }
    
    void deleteAtTail() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* delNode = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete delNode;
    }

    void deleteNode(int target) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->data == target) {
            Node* delNode = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete delNode;
            return;
        }
        if (tail->data == target) {
            Node* delNode = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete delNode;
            return;
        }
        Node* cur = head;
        while (cur->next != nullptr && cur->next->data != target) {
            cur = cur->next;
        }
        if (cur->next == nullptr) {
            cout << "Not found" << endl;
            return;
        }
        Node* delNode = cur->next;
        if (cur->next->next != nullptr) {
            cur->next = cur->next->next;
            cur->next->prev = cur;
        } else {
            tail = cur;
        }
        delete delNode;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node *cur = head;
        cout << "NULL <-> ";
        while (cur != nullptr) {
            cout << cur->data << " <-> ";
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }

    void search(int key) {
        Node* cur = head;
        int idx = 0;
        while (cur != nullptr && cur->data != key) {
            cur = cur->next;
            idx++;
        }
        if (cur != nullptr && cur->data == key) {
            cout << "Found at index " << idx << endl;
            return;
        }
        cout << "Not found" << endl;
    }
};

int main() {
    DoublyLinkedlist list1;
    list1.insertAtHead(60);
    list1.insertAtHead(50);
    list1.insertAtHead(40);
    list1.insertAtHead(30);
    list1.insertAtHead(20);
    list1.insertAtHead(10);
    list1.insertAtTail(80);
    list1.insertAfterNode(60, 70);
    list1.display();
    list1.deleteAtHead();
    list1.deleteAtTail();
    list1.deleteNode(100);
    list1.display();
    list1.search(60);

    return 0;
}
