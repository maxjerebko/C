#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int m = 5; // Кількість рядків у масиві
    const int n = 7; // Кількість стовпців у масиві

    int array[m][n]; // Оголошення двовимірного масиву

    srand(static_cast<unsigned int>(time(0))); // Ініціалізація генератора випадкових чисел

    // Заповнення масиву випадковими числами від 1 до 100
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = rand() % 100 + 1;
        }
    }

    // Виведення масиву
    cout << "Масив: " << "\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nСума елементів у кожному рядку:" << "\n";

    // Обчислення суми елементів у кожному рядку
    for (int i = 0; i < m; i++) {
        int row_sum = 0; // Сума елементів у рядку
        for (int j = 0; j < n; j++) {
            row_sum += array[i][j]; // Додавання елемента до суми
        }
        cout << "Рядок " << i + 1 << ": " << row_sum << "\n";
    }

    return 0; // Завершення програми
}
