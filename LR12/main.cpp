#include <iostream>  // Підключення бібліотеки для введення/виведення

using namespace std;  // Використання простору імен std

int main() {
    int numbers[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };  // Масив цілих чисел
    int size = sizeof(numbers) / sizeof(numbers[0]);  // Обчислення кількості елементів у масиві

    int* minElement = numbers;  // Вказівник на перший елемент масиву (вважається мінімальним)

    for (int* current = numbers + 1; current < numbers + size; current++) {  // Проходимо масив з другого елемента
        if (*current < *minElement) {  // Якщо поточне значення менше мінімального
            *minElement = *current;  // Оновлюємо мінімальне значення
        }
    }

    cout << *minElement << "\n";  // Виводимо мінімальне значення

    return 0;  // Завершення програми
}
