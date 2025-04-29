#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int top;
    int data[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }
    
    void push (int value) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = value;
    }

    void pop () {
        if (isEmpty()) {
            cout << "Stack is underflow!" << endl;
            return;
        }
        top--;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Data : ";
        for(int i=0; i <= top; i++) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }
};
    
int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(20);
    stack.display();
    stack.pop();
    stack.display();
    return 0;
}