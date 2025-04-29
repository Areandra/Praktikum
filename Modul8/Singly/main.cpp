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
    // Constructor untuk inisialisasi LinkedList
    LinkedList() {
        head = nullptr;
    }

    // Method untuk menambahkan node di awal
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Method untuk menambahkan node di akhir
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

    // Method untuk menambahkan node setelah node tertentu
    void insertAfter(int targetValue, int newValue) {
        Node* temp = head;
        while (temp != nullptr && temp->data != targetValue) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node dengan nilai " << targetValue << " tidak ditemukan." << endl;
            return;
        }

        Node* newNode = new Node(newValue);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Method untuk menambahkan node sebelum node tertentu
    void insertBefore(int targetValue, int newValue) {
        Node* newNode = new Node(newValue);
        
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != targetValue) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node dengan nilai " << targetValue << " tidak ditemukan." << endl;
            return;
        }
        if (prev == nullptr) {
            // Jika node target adalah head
            newNode->next = head;
            head = newNode;
        }
        else {
            // Jika node target berada di tengah atau akhir
            prev->next = newNode;
            newNode->next = temp;
            return;
        }
    }

    // Method untuk menampilkan LinkedList
    void display() {
        Node* temp = head;
        cout << "Linked List : ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Method untuk menghapus node dengan nilai tertentu
    void deleteNode(int value) {
        Node* temp = head;
        Node* prev = nullptr;

        // Cari node dengan data yang sesuai
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        // Jika node tidak ditemukan
        if (temp == nullptr) {
            cout << "Node dengan nilai " << value << " tidak ditemukan." << endl;
            return;
        }

        // Hapus node
        if (prev == nullptr) {
            // Jika node yang akan dihapus adalah head
            head = head->next;
        } else {
            // Jika node yang akan dihapus berada di tengah atau akhir
            prev->next = temp->next;
        }

        delete temp; // Bebaskan memori yang dialokasikan untuk node yang dihapus
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAfter(2, 4);
    list.insertBefore(3, 5);
    list.display();

    return 0;
}
