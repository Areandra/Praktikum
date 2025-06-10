#include <iostream>
using namespace std;

// Kelas Node
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Definisi LinkedList
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        cout << "Linked List : ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteNode() {
        Node* temp = head;
        if (temp) {
            head = head->next;
            cout << "Node dengan nilai " << temp->data << " berhasil dihapus." << endl;
            return;
        } else {
            cout << "Data Kosong" << endl;
        }
        delete temp; 
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(1);
    list.insertAtBeginning(2);
    list.insertAtEnd(3);
    list.insertAtBeginning(4);
    list.display();
    list.deleteNode();
    list.display();

    return 0;
}
