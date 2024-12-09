#include <iostream>
#include <ctime> // для time()
using namespace std;

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел
    
    const int m = 12; // Розмір масиву
    int array[m];
    
    // Генерація випадкового масиву
    for (int i = 0; i < m; i++) {
        array[i] = rand() % 100; // Генерація чисел від 0 до 99
    }
    
    // Виведення початкового масиву
    cout << "Original array: ";
    for (int i = 0; i < m; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    // Сортування масиву за зростанням
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Міняємо місцями, якщо порядок неправильний
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    
    // Виведення масиву, відсортованого за зростанням
    cout << "Array sorted in ascending order: ";
    for (int i = 0; i < m; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    // Сортування масиву за спаданням
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                // Міняємо місцями, якщо порядок неправильний
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    
    // Виведення масиву, відсортованого за спаданням
    cout << "Array sorted in descending order: ";
    for (int i = 0; i < m; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    return 0;
}
