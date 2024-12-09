#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int m = 4; // Кількість рядків
    const int n = 3; // Кількість стовпців

    int array[m][n]; // Двовимірний масив

    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned int>(time(0)));

    // Заповнення масиву випадковими числами від 1 до 100
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = rand() % 100 + 1;
        }
    }

    // Виведення масиву
    cout << "Масив:" << "\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }

    // Підрахунок кількості парних чисел у кожному рядку
    cout << "\nКількість парних чисел у кожному рядку:" << "\n";
    for (int i = 0; i < m; i++) {
        int even_count = 0; // Лічильник парних чисел
        for (int j = 0; j < n; j++) {
            if (array[i][j] % 2 == 0) {
                even_count++;
            }
        }
        cout << "Рядок " << i + 1 << ": " << even_count <<  "\n";
    }

    return 0;
}
