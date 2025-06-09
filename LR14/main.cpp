#include <iostream>   // Підключення бібліотеки для введення/виведення
#include <ctime>      // Для генерації випадкових чисел на основі часу
#include <cstdlib>    // Для використання rand() і srand()

using namespace std;

int main() {

    srand((unsigned)time(0));  // Ініціалізація генератора випадкових чисел

    // ===== Exercise 1 =====

    double* arr = new double[10];  // Динамічне виділення масиву з 10 елементів типу double
    double* ptr = &arr[0];         // Вказівник на перший елемент масиву

    // Заповнення масиву випадковими числами від -2.0 до 2.0
    for (int i = 0; i < 10; i++) {
        *(ptr + i) = ((double)rand() / RAND_MAX) * 4.0 - 2.0;  // Випадкове число у діапазоні [-2, 2]
    }

    // Виведення елементів масиву
    for (int i = 0; i < 10; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    int positive = 0;
    int negative = 0;

    // Підрахунок додатних і від’ємних значень у масиві
    for (int i = 0; i < 10; i++) {
        if (*(ptr + i) > 0)
            positive++;       // Якщо число додатне
        else if (*(ptr + i) < 0)
            negative++;       // Якщо число від’ємне
    }

    // Виведення результатів
    cout << "Quantity of positive values: " << positive << endl;
    cout << "Quantity of negative values: " << negative << endl;

    delete[] arr;  // Звільнення пам’яті, виділеної під масив

    // ===== Exercise 2 =====

    srand((unsigned)time(0));  // Повторна ініціалізація генератора (можна опустити)

    int size = 3;  // Розмір квадратного масиву 3x3

    // Динамічне створення двовимірного масиву
    int** arrTwo = new int*[size];
    for (int i = 0; i < size; i++) {
        arrTwo[i] = new int[size];
    }


    // Заповнення масиву випадковими числами від 0 до 99
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arrTwo[i][j] = rand() % 100;
        }
    }

    // Виведення масиву у вигляді таблиці
    for (int i = 0; i < size ; i++) {
        for (int j = 0; j < size; j++) {
            cout << "\t" << arrTwo[i][j];
        }
        cout << endl;
    }

    // Виведення головної діагоналі
    cout << "\nMain diagonal: ";
    for (int i = 0; i < size; i++) {
        cout << arrTwo[i][i] << " ";
    }
    cout << endl;

    // Виведення побічної діагоналі
    cout << "Side diagonal: ";
    for (int i = 0; i < size; i++) {
        cout << arrTwo[i][size - 1 - i] << " ";
    }
    cout << endl;

    int evenCount = 0, oddCount = 0;

    // Підрахунок парних і непарних чисел у масиві
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arrTwo[i][j] % 2 == 0)
                evenCount++;     // Якщо число парне
            else
                oddCount++;      // Якщо число непарне
        }
    }

    cout << endl;
    cout << "Quantity of even values: " << evenCount << endl;
    cout << "Quantity of odd values: " << oddCount << endl;

    // Звільнення пам’яті, виділеної під двовимірний масив
    for (int i = 0; i < size; i++) {
        delete[] arrTwo[i];
    }
    delete[] arrTwo;

    return 0;  // Завершення програми
}
