#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> // для abs()

using namespace std;

class Fraction {
public:
    // Конструктор дробу
    Fraction(int numerator, int denominator) {
        // Якщо знаменник від’ємний, переносимо знак до чисельника
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }

        this->numerator = numerator;       // Ініціалізуємо чисельник
        this->denominator = denominator;   // Ініціалізуємо знаменник
    }

    // Повертає рядкове представлення дробу (у вигляді змішаного дробу)
    string toString() {
        int whole = numerator / denominator;              // Ціла частина
        int remainder = abs(numerator % denominator);     // Залишок
        int absDenominator = abs(denominator);            // Абсолютне значення знаменника

        if (remainder == 0) {
            return to_string(whole);                      // Якщо залишок 0 — просто ціле число
        }

        if (whole != 0) {
            // Якщо є ціла частина, повертаємо змішаний дріб
            return to_string(whole) + " " + to_string(remainder) + "/" + to_string(absDenominator);
        }

        // Якщо ціла частина 0, обробляємо знак
        string prefix = (numerator < 0) ? "-" : "";
        return prefix + to_string(remainder) + "/" + to_string(absDenominator);
    }

    // Повертає десяткове значення дробу
    double toDouble() {
        return static_cast<double>(numerator) / static_cast<double>(denominator); // Явне перетворення до double
    }

private:
    int numerator;     // чисельник
    int denominator;   // знаменник
};

int main() {
    string input;
    cout << "Enter a fraction: ";
    getline(cin, input);              // Зчитування повного рядка

    stringstream ss(input);          // Створення потоку для розбору введення
    int num, den;
    char slash;

    ss >> num >> slash >> den;       // Зчитування чисельника, символу '/' та знаменника

    if (den == 0) {                  // Перевірка на ділення на нуль
        cerr << "Denominator cannot be zero!" << endl;
        return 1;                    // Повертаємо код помилки
    }

    Fraction fraction(num, den);     // Створюємо об’єкт дробу

    // Виводимо як рядок і десяткове значення
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;

    return 0; // Успішне завершення
}
