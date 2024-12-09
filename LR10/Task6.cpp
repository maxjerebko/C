#include <iostream>
#include <cstdlib>  // Для rand() і srand()
#include <ctime>    // Для time()

using namespace std;

int main() {
    const int m = 4; // Кількість рядків
    const int n = 7; // Кількість стовпців
    int arr[m][n];

    // Ініціалізуємо генератор випадкових чисел
    srand(static_cast<unsigned int>(time(0)));

    // Заповнюємо масив випадковими цілими числами від 1 до 100
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = rand() % 100 + 1; // Випадкові числа від 1 до 100
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

    // Знаходимо мінімальний елемент і його позицію
    int minElement = arr[0][0];
    int minRow = 0;
    int minCol = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] < minElement) {
                minElement = arr[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }

    // Виводимо результат
    cout << "Мінімальний елемент: " << minElement << endl;
    cout << "Позиція елемента: рядок " << minRow + 1 << ", стовпець " << minCol + 1 << endl;

    return 0;
}
