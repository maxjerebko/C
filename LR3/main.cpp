#include <iostream>
using namespace std;

int main() {
    int N;

    // Введення тризначного числа
    cout << "Enter a three-digit positive number N: ";
    cin >> N;

    // Перевірка, чи є число тризначним
    if (N < 100 || N > 999) {
        cout << "Error: The number must be a three-digit positive number." << endl;
        return 1; // Завершення програми з кодом помилки
    }

    // Розклад числа на цифри
    int hundreds = N / 100;       // Сотні
    int tens = (N / 10) % 10;     // Десятки
    int units = N % 10;           // Одиниці

    // Лічильник цифр, більших за 5
    int count = 0;
    if (hundreds > 5) count++;
    if (tens > 5) count++;
    if (units > 5) count++;

  
   
    cout << "Number of digits greater than 5: " << count << endl;

    return 0;
}


