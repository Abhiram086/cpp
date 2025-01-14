#include <iostream>
#include <string>
using namespace std;

template <typename K, typename V>
class map {
public:
    struct KeyValue {
        K key;
        V value;
    };

    KeyValue* m;
    int size;
    int capacity;

    map() {
        size = 0;
        capacity = 1;
        m = new KeyValue[capacity];
    }

    void add(K key, V value) {
        if (size == capacity) {
            capacity *= 2;
            KeyValue* temp = new KeyValue[capacity];
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

    void del(K key) {
        int pos = -1;
        for (int i = 0; i < size; i++) {
            if (m[i].key == key) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "Key not found!\n";
            return;
        }

        for (int i = pos; i < size - 1; i++) {
            m[i] = m[i + 1];
        }
        size--;
        cout << "Element deleted successfully.\n";
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

    void displayAll() const {
        if (size == 0) {
            cout << "Map is empty.\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << "Key: " << m[i].key << ", Value: " << m[i].value << "\n";
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
        cout << "2. Delete Element\n";
        cout << "3. Display All Elements\n";
        cout << "4. Display Specific Element by Key\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the key (integer): ";
                cin >> key;
                cout << "Enter the value (string): ";
                cin.ignore(); // Clear input buffer
                getline(cin, value);
                v.add(key, value);
                cout << "Element added successfully.\n";
                break;

            case 2:
                cout << "Enter the key to delete: ";
                cin >> key;
                v.del(key);
                break;

            case 3:
                v.displayAll();
                break;

            case 4:
                cout << "Enter the key to display: ";
                cin >> key;
                v.display(key);
                break;

            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
