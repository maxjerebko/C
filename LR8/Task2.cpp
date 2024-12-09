#include <iostream>
using namespace std;

int main() {
    const int m = 10;
    int array[m] = {6, -3, 8, -6, 1, -7, 7, -2, 9, -4};

    // Виведення початкового масиву
    cout << "Початковий масив: ";
    for (int i = 0; i < m; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Знаходимо індекс першого максимального елемента
    int maxIndex = 0;
    for (int i = 0; i < m; i++) {
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    }

    // Замінюємо від'ємні елементи перед першим максимумом
    int i = 0;
    while (i < maxIndex) {
        if (array[i] < 0) {
            array[i] = 0;
        }
        i++;
    }

    // Виведення модифікованого масиву
    cout << "Модифікований масив: ";
    for (int i = 0; i < m; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

