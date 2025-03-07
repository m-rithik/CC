#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};



class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) 
            head = tail = newNode;
         else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) 
            head = tail = newNode;
         else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
 void printForward() {
        Node* current = head;
        cout << "Forward Traversal: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printBackward() {
        Node* current = tail;
        cout << "Backward Traversal: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};




int main() {
    DoublyLinkedList dll;
    dll.insertAtHead(10);
    dll.insertAtHead(20);
    dll.insertAtTail(30);
    dll.insertAtTail(40);
    dll.printForward();
    dll.printBackward();

    return 0;
}
