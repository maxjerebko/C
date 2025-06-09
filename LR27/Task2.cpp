#include <iostream>
using namespace std;

int main(void) {
    int a = 0, b = 0, c = 0;

    // Зчитуємо значення для змінних a та b
    cin >> a;
    cin >> b;

    try {
        // Перевіряємо, чи ділиться на нуль
        if (b == 0) {
            throw "Ваше введення некоректне: не можна ділити на нуль.";
        }

        // Якщо ділити можна — виконуємо операцію
        c = a / b;

        // Виводимо результат
        cout << c << endl;
    } catch (const char* msg) {
        // Обробка винятку — виводимо повідомлення про помилку
        cout << msg << endl;
    }

    return 0;
}

