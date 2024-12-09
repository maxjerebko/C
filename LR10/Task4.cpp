#include <iostream>
#include <cstdlib>  // Для rand() і srand()
#include <ctime>    // Для time()

using namespace std;

int main() {
    const int m = 4; // Кількість рядків
    const int n = 6; // Кількість стовпців
    int arr[m][n];

    // Ініціалізуємо генератор випадкових чисел
    srand(static_cast<unsigned int>(time(0)));

    // Заповнюємо масив випадковими цілими числами від 1 до 50
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = rand() % 50 + 1; // Випадкові числа від 1 до 50
        }
    }

    // Виводимо масив
    cout << "Згенерований двовимірний масив:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Обчислення та виведення суми елементів кожного стовпця
    for (int j = 0; j < n; ++j) {
        int sum = 0; // Лічильник суми
        for (int i = 0; i < m; ++i) {
            sum += arr[i][j]; // Додаємо значення елемента до суми
        }
        // Виводимо результат для кожного стовпця
        cout << "Сума елементів у стовпці " << j + 1 << ": " << sum << endl;
    }

    return 0;
}
