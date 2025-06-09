#include <iostream> // Підключення бібліотеки для роботи з введенням та виведенням
using namespace std; // Використання простору імен стандартної бібліотеки

const int InvalidArgument = 222; // Константа, що позначає помилку некоректного аргументу (ділення на нуль)

// Функція ділення з перевіркою на нуль
float div(float arg1, float arg2) {
    if (arg2 == 0.0) // Якщо другий аргумент — нуль
        throw InvalidArgument;  // Генеруємо виключення з кодом помилки
    return arg1 / arg2; // Виконуємо ділення і повертаємо результат
}

int main(void) {
    float a, b; // Оголошення змінних для введення чисел
    while (cin >> a >> b) { // Зчитування пари чисел з введення у циклі
        try {
            float r = div(a, b); // Спроба виконати ділення
            cout << r << endl; // Виведення результату ділення
        }
        catch (int e) { // Обробка виключення типу int
            if (e == InvalidArgument) { // Якщо помилка відповідає діленню на нуль
                cout << "Are you kidding me?" << endl; // Повідомлення користувачу
                cout << "Your input is not valid. You can't divide by zero." << endl; // Пояснення помилки
            }
        }
    }
    return 0; // Завершення програми
}
