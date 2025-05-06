#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* right;
    Node* left;

};

Node* newNode(char value){
    Node* temp = new Node;
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;

}

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

stack<int> s;

void computePostfix(Node* node){
    if(node == NULL) return;
    computePostfix(node->left);
    computePostfix(node->right);
    cout << node->data << " ";
    if(isOperator(node->data)){
    int res = 0;
    int b = s.top();
    s.pop();
    int a = s.top();
    s.pop();

    if(node->data == '+') res = a + b;
    if(node->data == '-') res = a - b;
    if(node->data == '*') res = a * b;
    if(node->data == '/') res = a / b;
    s.push(res);
    }else{
    s.push(node->data - '0');
    }
}

int main(){
    Node* root = newNode('+');
    root->left = newNode('+');
    root->right = newNode('/');
    root->left->left = newNode('-5');
    root->left->right = newNode('-6');
    root->right->left = newNode('+');
    root->right->right = newNode('-2');
    root->right->left->left = newNode('-5');
    root->right->left->right = newNode('-3');
    cout << "Postfix form: ";
    computePostfix(root);

    cout << "\nHasil evalussi post fix: " << s.top() << endl;
    return 0;
}