#ifndef SIMPLE_MAP_H
#define SIMPLE_MAP_H

#include <vector>
#include <utility>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename K, typename V>
class SimpleMap {
private:
    vector<pair<K, V>> data; // A vector to store key-value pairs

public:
    void insert(const K& key, const V& value) {
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i].first == key) {
                data[i].second = value; // Update existing key
                return;
            }
        }
        data.push_back(make_pair(key, value)); // Add new key-value pair
    }

    V get(const K& key) const {
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i].first == key) {
                return data[i].second;
            }
        }
        throw runtime_error("Key not found");
    }

    void display() const {
        for (size_t i = 0; i < data.size(); ++i) {
            cout << "Key: " << data[i].first << ", Value: " << data[i].second << endl;
        }
    }
};

#endif
MAIN

#include "SimpleMap.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    SimpleMap<string, int> myMap;
    int choice;
    string name;
    int age;

    while (true) {
        cout << "Enter your choice:\n1. Insert\n2. Value\n3. Display\n4. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name and age: ";
            cin >> name >> age;
            myMap.insert(name, age);
            break;
        case 2:
            cout << "Enter the name: ";
            cin >> name;
            try {
                age = myMap.get(name);
                cout << "Age of " << name << " is: " << age << endl;
            } catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
        case 3:
            cout << "Map contents:\n";
            myMap.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }

    return 0;
}