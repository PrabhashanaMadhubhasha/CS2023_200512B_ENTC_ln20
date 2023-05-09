#include <iostream>
#include <chrono>
using namespace std;

class Stack {
private:
    int top;
    int size;
    int* arr;
public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
        }
        else {
            arr[++top] = x;
        }
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
        }
        else {
            top--;
        }
    }
    bool isEmpty() {
        return (top == -1);
    }
    bool isFull() {
        return (top == size - 1);
    }
    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        else {
            return arr[top];
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        }
        else {
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s(100);

    auto start_stack_array = chrono::high_resolution_clock::now();
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    for (int i = 0; i < 5 ; i++){
        s.pop();
    }
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    auto end_stack_array = chrono::high_resolution_clock::now();
    auto elapsed_stack_array = chrono::duration_cast<chrono::microseconds>(end_stack_array - start_stack_array);
    cout <<"Time taken for execution operations of  stack implimented by using array: " << elapsed_stack_array.count() << " microseconds" << endl;

    return 0;
}