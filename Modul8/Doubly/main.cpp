#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Definisi Doubly LinkedList
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor untuk inisialisasi Doubly LinkedList
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Method untuk menambahkan node di awal
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            // Jika linked list kosong
            head = newNode;
            tail = newNode;
        } else {
            // Jika linked list tidak kosong
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Method untuk menambahkan node di akhir
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            // Jika linked list kosong
            head = newNode;
            tail = newNode;
        } else {
            // Jika linked list tidak kosong
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Method untuk menambahkan node setelah node dengan nilai tertentu
    void insertAfter(int targetValue, int newValue) {
        Node* newNode = new Node(newValue);
        Node* temp = head;
        while (temp != nullptr && temp->data != targetValue) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node dengan nilai " << targetValue << " tidak ditemukan." << endl;
            return;
        }

        if (temp == tail) {
            // Jika node yang akan ditambahkan adalah setelah tail
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        } else {
            // Jika node yang akan ditambahkan adalah di tengah atau awal
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    // Method untuk menambahkan node sebelum node dengan nilai tertentu
    void insertBefore(int targetValue, int newValue) {
        Node* newNode = new Node(newValue);
        Node* temp = head;
        while (temp != nullptr && temp->data != targetValue) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node dengan nilai " << targetValue << " tidak ditemukan." << endl;
            return;
        }

        if (temp == head) {
            // Jika node yang akan ditambahkan adalah sebelum head
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else {
            // Jika node yang akan ditambahkan berada di tengah
            newNode->prev = temp->prev;
            newNode->next = temp;
            temp->prev->next = newNode;
            temp->prev = newNode;
        }
    }

    // Method untuk menampilkan Doubly LinkedList dari depan
    void displayForward() {
        Node* temp = head;
        cout << "Doubly Linked List (forward) : ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Method untuk menampilkan Doubly LinkedList dari belakang
    void displayBackward() {
        Node* temp = tail;
        cout << "Doubly Linked List (backward) : ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    // Method untuk menghapus node dengan nilai tertentu
    void deleteNode(int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node dengan nilai " << value << " tidak ditemukan." << endl;
            return;
        }

        if (temp == head && temp == tail) {
            // Jika linked list hanya memiliki satu node
            head = nullptr;
            tail = nullptr;
        } else if (temp == head) {
            // Jika node yang akan dihapus adalah head
            head = temp->next;
            head->prev = nullptr;
        } else if (temp == tail) {
            // Jika node yang akan dihapus adalah tail
            temp->prev->next = nullptr;
            tail = temp->prev;
        } else {
            // Node yang akan dihapus berada di tengah
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp; // Hapus node dari memori
    }
};

int main() {
    DoublyLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
  
    list.displayForward();
    list.displayBackward();

    list.insertBefore(2, 5);

    list.displayForward();
    
    list.insertAfter(5, 7);

    list.displayForward();

    return 0;
}
