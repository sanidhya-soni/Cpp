#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

Node *head = nullptr, *temp = nullptr;

void add() {

    int data;

    cout << endl << "Enter Value: ";
    cin >> data;
    Node* newnode = new Node();
    newnode-> data = data;
    newnode-> next = nullptr;

    if(head == nullptr) {
        head = newnode;
    }
    else {
        temp-> next = newnode;
    }
    temp = newnode;
}

void insertAtBeginning() {
    int data;
    cout << endl << "Enter Value: ";
    cin >> data;
    Node* newnode = new Node();
    newnode-> data = data;
    newnode-> next = head;
    head = newnode;
}

void insertAtEnd() {
    int data;
    cout << endl << "Enter Value: ";
    cin >> data;
    Node* newnode = new Node();
    newnode-> data = data;
    newnode-> next = nullptr;
    temp-> next = newnode;
    temp = newnode;
}

void deleteFromBeginning() {
    head = head-> next;
}

void deleteFromEnd() {
    Node* p = head;
    while(p-> next-> next != nullptr) {
        p = p-> next;
    }
    p-> next = nullptr;
}

void print() {
    cout << endl;
    Node* p = head;
    while(p != nullptr) {
        cout << p-> data << " ";
        p = p-> next;
    }
}

int main() {

    for(int i = 0; i < 5; i++) {
        add();
    }
    print();
    deleteFromEnd();
    print();

    return 0;
}
