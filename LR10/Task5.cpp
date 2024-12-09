#include <iostream>
#include <cstdlib>  // Для rand() і srand()
#include <ctime>    // Для time()

using namespace std;

int main() {
    const int m = 3; // Кількість рядків
    const int n = 4; // Кількість стовпців
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

    // Знаходимо максимальний елемент і його позицію
    int maxElement = arr[0][0];
    int maxRow = 0;
    int maxCol = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] > maxElement) {
                maxElement = arr[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    // Виводимо результат
    cout << "Максимальний елемент: " << maxElement << endl;
    cout << "Позиція елемента: рядок " << maxRow + 1 << ", стовпець " << maxCol + 1 << endl;

    return 0;
}
