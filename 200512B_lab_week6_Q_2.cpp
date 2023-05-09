#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class Stack {
    private:
        Node* top;
    public:
        Stack() {
            top = nullptr;
        }
        bool isEmpty() {
            return (top == nullptr);
        }
        void push(int value) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = top;
            top = newNode;
        }
        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return -1;
            } else {
                int value = top->data;
                Node* temp = top;
                top = top->next;
                delete temp;
                return value;
            }
        }
        int stackTop() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return -1;
            } else {
                return top->data;
            }
        }
        void display() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
            } else {
                cout << "Stack elements are: ";
                Node* temp = top;
                while (temp != nullptr) {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Stack top is: " << s.stackTop() << endl;
    s.pop();
    cout << "Stack top after pop is: " << s.stackTop() << endl;
    s.display();
    cout << "Is the stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}