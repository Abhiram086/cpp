#include <iostream>
#include <string>
using namespace std;

template <typename K, typename V>
class map {
public:
    struct keyvalue {
        K key;
        V value;
    };

    int size;
    int capacity;
    keyvalue* m;

    map() {
        size = 0;
        capacity = 1;
        m = new keyvalue[capacity];
    }

    void push(K key, V value) {
        if (size == capacity) {
            capacity *= 2;
            keyvalue* temp = new keyvalue[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = m[i];
            }
            delete[] m;
            m = temp;
        }
        m[size].key = key;
        m[size].value = value;
        size++;
    }

    void display(K key) const {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (m[i].key == key) {
                cout << "Key: " << m[i].key << ", Value: " << m[i].value << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Key not found!\n";
        }
    }

    ~map() {
        delete[] m;
    }
};

int main() {
    map<int, string> v;
    int choice;
    int key;
    string value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Element\n";
        cout << "2. Display Specific Element by Key\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the key (integer): ";
                cin >> key;
                cout << "Enter the value (string): ";
                 // Clear input buffer
                cin>>value;
                v.push(key, value);
                cout << "Element added successfully.\n";
                break;

            case 2:
                cout << "Enter the key to display: ";
                cin >> key;
                v.display(key);
                break;

            case 3:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
