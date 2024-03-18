#include<iostream>
using namespace std;

class Node {
public:
    int n;
    Node* next;

    Node(int n) {
        this->n = n;
        next = nullptr;
    }
};

// Insert Element At head
void insertAtHead(int n, Node*& head) {
    // Creating new Node
    Node* node = new Node(n);
    if (head == nullptr) {
        head = node;
    }else{
     node->next = head;
     head = node;
    }
   
}

// Print All Elements
void traverseAllElement(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->n << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *head = nullptr;
    // Testing insertAtHead function
    insertAtHead(3, head);
    insertAtHead(5, head);
    insertAtHead(7, head);

    // Testing traverseAllElement function
    traverseAllElement(head);
    
    return 0;
}
