#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> // для abs()
using namespace std;

// Функція для обчислення НСД (найбільший спільний дільник)
int gcd(int a, int b) {
    // Класичний алгоритм Евкліда
    while (b) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return abs(a); // Повертаємо абсолютне значення
}

// Клас Fraction для представлення дробу
class Fraction {
public:
    // Конструктор
    Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero."); // Перевірка на нуль
        }

        // Якщо знаменник від’ємний — змінюємо знак чисельника
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }

        this->numerator = numerator;
        this->denominator = denominator;

        reduce(); // Скорочення дробу
    }

    // Перетворення дробу у текстовий вигляд
    string toString() {
        int whole = numerator / denominator;               // Ціла частина
        int rem = abs(numerator % denominator);            // Остача
        int absDen = abs(denominator);                     // Абсолютне значення знаменника

        if (rem == 0) return to_string(whole);             // Якщо остача нуль — просто ціле число

        if (whole != 0) {
            // Якщо є ціла частина — змішаний дріб
            return to_string(whole) + " " + to_string(rem) + "/" + to_string(absDen);
        }

        // Якщо ціла частина 0 — виводимо звичайний дріб з урахуванням знака
        string sign = (numerator < 0) ? "-" : "";
        return sign + to_string(rem) + "/" + to_string(absDen);
    }

    // Повертає десяткове представлення дробу
    double toDouble() {
        return static_cast<double>(numerator) / denominator;
    }

    // Додавання дробів
    Fraction plus(Fraction that) {
        int num = numerator * that.denominator + that.numerator * denominator;
        int den = denominator * that.denominator;
        return Fraction(num, den); // Повертаємо скорочений результат
    }

    // Віднімання дробів
    Fraction minus(Fraction that) {
        int num = numerator * that.denominator - that.numerator * denominator;
        int den = denominator * that.denominator;
        return Fraction(num, den);
    }

    // Множення дробів
    Fraction times(Fraction that) {
        int num = numerator * that.numerator;
        int den = denominator * that.denominator;
        return Fraction(num, den);
    }

    // Ділення дробів
    Fraction by(Fraction that) {
        if (that.numerator == 0) throw invalid_argument("Division by zero."); // Перевірка на 0
        int num = numerator * that.denominator;
        int den = denominator * that.numerator;
        return Fraction(num, den);
    }

private:
    int numerator;
    int denominator;

    // Метод скорочення дробу
    void reduce() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }
};

// Головна функція
int main() {
    string input1, input2;
    cout << "Enter first fraction: ";
    getline(cin, input1); // Зчитування першого дробу

    cout << "Enter second fraction: ";
    getline(cin, input2); // Зчитування другого дробу

    int num1, den1, num2, den2;
    char slash;

    // Розбір першого дробу
    stringstream ss1(input1);
    ss1 >> num1 >> slash >> den1;

    // Розбір другого дробу
    stringstream ss2(input2);
    ss2 >> num2 >> slash >> den2;

    try {
        Fraction f1(num1, den1); // Створення першого дробу
        Fraction f2(num2, den2); // Створення другого дробу

        // Виведення операцій з дробами
        cout << f1.toString() << " + " << f2.toString() << " = " << f1.plus(f2).toString() << endl;
        cout << f1.toString() << " - " << f2.toString() << " = " << f1.minus(f2).toString() << endl;
        cout << f1.toString() << " * " << f2.toString() << " = " << f1.times(f2).toString() << endl;
        cout << f1.toString() << " / " << f2.toString() << " = " << f1.by(f2).toString() << endl;
    }
    catch (exception& e) {
        cerr << "Error: " << e.what() << endl; // Обробка помилок
    }

    return 0;
}
