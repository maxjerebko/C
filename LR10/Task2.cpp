#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int m = 6; // Кількість рядків у масиві
    const int n = 4; // Кількість стовпців у масиві

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

    cout << "\nКількість парних чисел у кожному стовпці:" << "\n";

    // Обчислення кількості парних чисел у кожному стовпці
    for (int j = 0; j < n; j++) {
        int even_count = 0; // Лічильник парних чисел
        for (int i = 0; i < m; i++) {
            if (array[i][j] % 2 == 0) { // Перевірка на парність
                even_count++;
            }
        }
        cout << "Стовпець " << j + 1 << ": " << even_count << "\n";
    }

    return 0; // Завершення програми
}
