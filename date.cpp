#include <iostream>
using namespace std;

class Date {
public:
    int m; // month
    int day; // day
    int year; // year
    int leap; // leap year flag

public:
    Date() {
        cout << "Enter the date (day month year): ";
        cin >> day >> m >> year;
        leap = 0; // Initialize leap to 0
    }

    void check() {
        // Check for leap year
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            leap = 1;
        }

        // Validate the date
        if (day < 1 || m < 1 || m > 12 || year < 1) {
            cout << "Date is invalid" << endl;
        } else if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && day <= 31) {
            cout << "Date is valid for 31-day months" << endl;
        } else if ((m == 4 || m == 6 || m == 9 || m == 11) && day <= 30) {
            cout << "Date is valid for 30-day months" << endl;
        } else if (m == 2) {
            if ((leap && day <= 29) || (!leap && day <= 28)) {
                cout << "Date is valid for February" << endl;
            } else {
                cout << "Date is invalid for February" << endl;
            }
        } else {
            cout << "Date is invalid" << endl;
        }
    }
};

int main() {
    Date d;
    d.check();
    return 0;
}