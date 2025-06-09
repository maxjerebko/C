#include <iostream> // Підключення бібліотеки для вводу/виводу
using namespace std; // Використання простору імен std

const int DivideByZero = 111; // Константа, що позначає помилку ділення на нуль

// Функція, яка виконує внутрішнє ділення без перевірки
float internaldiv(float arg1, float arg2) {
    return arg1 / arg2; // Повертає результат ділення
}

// Функція, що виконує ділення з перевіркою на нуль
float div(float arg1, float arg2) {
    if (arg2 == 0.0) // Якщо другий аргумент дорівнює нулю
        throw DivideByZero;  // Генеруємо виключення з кодом DivideByZero
    return internaldiv(arg1, arg2); // Інакше виконуємо ділення
}

int main(void) {
    float a, b; // Змінні для введення чисел
    while (cin >> a >> b) { // Читаємо пари чисел з введення, поки є дані
        try {
            float r = div(a, b); // Прагнемо виконати ділення
            cout << r << endl; // Виводимо результат
        }
        catch (int e) { // Обробка виключення
            if (e == DivideByZero) { // Якщо це помилка ділення на нуль
                cout << "Are you kidding me?" << endl; // Повідомлення користувачу
                cout << "Your input is not valid. You can't divide by zero." << endl; // Пояснення помилки
            }
        }
    }
    return 0; // Завершення програми
}
