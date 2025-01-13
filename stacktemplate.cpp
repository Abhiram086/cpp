#include <iostream>
using namespace std;

template <typename T>
class Stack {
public:
    T* arr;
    T top;
    T max;

    Stack(int size) {
        max = size;
        arr = new T[size];
        top = -1;
    }

    void push(T obj) {
        if (!isFull()) {
            arr[++top] = obj;
            cout << "Pushed element is " << obj << endl;
        } else {
            cout << "Stack full" << endl;
        }
    }

    void pop() {
        if (!isEmpty()) {
            T temp = arr[top--];
            cout << "Popped element " << temp << endl;
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    T peek() {
        if (!isEmpty()) {
            cout << "Peeked element is " << arr[top] << endl;
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return T();
        }
    }

    bool isFull() {
        return top == max - 1;
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    Stack<int> stack(size);
    int choice, value;

    while (true) {
        cout << "1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
