#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 15; // Максимальний розмір
    int size;

    cout << "Enter the size of the box: ";
    cin >> size;

    // Перевірка на коректність вводу
    if (size <= 1) {
        cout << "Error: The size must be greater than 1." << endl;
        return 1;
    }
    if (size > MAX_SIZE) {
        cout << "Error: The size exceeds the maximum allowed (" << MAX_SIZE << ")." << endl;
        return 1;
    }

    // Верхня межа
    cout << '+';
    for (int i = 0; i < size; ++i) {
        cout << '-';
    }
    cout << '+' << endl;

    // Середина
    for (int i = 0; i < size; ++i) {
        cout << '|';
        for (int j = 0; j < size; ++j) {
            cout << ' ';
        }
        cout << '|' << endl;
    }

    // Нижня межа
    cout << '+';
    for (int i = 0; i < size; ++i) {
        cout << '-';
    }
    cout << '+' << endl;

    return 0;
}

