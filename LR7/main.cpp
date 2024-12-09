#include <iostream>
using namespace std;

int main() {
    int c0, count = 0;

    cout << "Enter c0: ";
    cin >> c0;

    if (c0 <= 0) {
        cout << "Invalid input! Please enter a positive integer." << endl;
        return 1;
    }

    while (c0 != 1) {
        cout << c0 << endl;

        if (c0 % 2 == 0) {
            c0 /= 2; // Якщо парне
        } else {
            c0 = c0 * 3 + 1; // Якщо непарне
        }

        count++;
    }

    cout << c0 << endl; // Вивід останнього значення (1)
    cout << "Steps = " << count << endl;

    return 0;
}

