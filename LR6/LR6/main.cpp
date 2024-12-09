#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter a natural number N: ";
    cin >> N;

    if (N <= 0) {
        cout << "The number must be natural (greater than 0)!" << endl;
        return 1;
    }

    int sum = 0; // Змінна для збереження суми цифр

    while (N > 0) {
        int digit = N % 10; // Отримуємо останню цифру числа
        if (digit > 2 && digit % 2 != 0) { // Перевіряємо умову
            sum += digit; // Додаємо цифру до суми
        }
        N /= 10; // Видаляємо останню цифру числа
    }

    cout << "The sum of all digits greater than 2 and odd is: " << sum << endl;

    return 0;
}

