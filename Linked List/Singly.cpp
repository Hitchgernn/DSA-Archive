#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Linkedlist {
private:
    Node* head;

public:
    Linkedlist() {
        head = nullptr;
    }

    void InsertAtHead(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void InsertAtTail(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* cur = head;
        while(cur -> next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
    }

    void insertAfterNode(int target, int data) {
        Node* cur = head;
        while(cur != nullptr && cur->data != target) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            cout << "Not found" << endl;
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = cur->next;
        cur->next = newNode;
    }

    void deleteAtHead() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* cur = head;
        head = head->next;
        delete cur;
    }

    void deleteAtTail() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* cur = head;
        while (cur->next->next != nullptr) {
            cur = cur->next;
        }
        delete cur->next;
        cur->next = nullptr;
    }

    void deleteNode(int target) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->data == target) {
            Node* delNode = head;
            head = head->next;
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
        cur->next = delNode->next;
        delete delNode;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->data << " -> ";
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

int main () {
    Linkedlist list1;
    list1.InsertAtHead(60);
    list1.InsertAtHead(50);
    list1.InsertAtHead(40);
    list1.InsertAtHead(30);
    list1.InsertAtHead(20);
    list1.InsertAtHead(10);
    list1.InsertAtTail(80);
    list1.insertAfterNode(60, 70);
    list1.display();
    list1.deleteAtHead();
    list1.deleteAtTail();
    list1.deleteNode(100);
    list1.display();
    list1.search(60);

    return 0;
}
