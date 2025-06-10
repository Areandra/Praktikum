#include <iostream>
#define SIZE 5

using namespace std;

class Queue {
private:
    int data[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        data[rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Data : ";
        for (int i = front; i <= rear; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    cout << "Nama : Muh. Ariel\nNim : F55124049\n";

    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    
    q.dequeue();
    q.dequeue();
    q.display();
    
    q.enqueue(60);
    q.display();

    return 0;
}