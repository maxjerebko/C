#include <iostream>
using namespace std;

// Функція перевіряє, чи є число простим
bool isPrime(int num) {
    if (num <= 1) {
        return false;  // Числа менші або рівні 1 не є простими
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;  // Якщо є дільник — число не просте
        }
    }

    return true;  // Число просте
}

int main() {

    // ===== Exercise 1 =====

    int number;

    cout << "Enter your number: ";  // Введення числа користувачем
    cin >> number;

    if (number <= 1) {
        cout << "Incorrect number" << endl;  // Перевірка на некоректне значення
        return 1;
    }

    // Перевірка та вивід результату
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;  // Просте число
    } else {
        cout << number << " is not a prime number." << endl;  // Не просте
    }

    // ===== Exercise 2 =====

    // Вивід усіх простих чисел від 0 до 21
    for (int i = 0; i <= 21; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;  // Завершення програми
}
