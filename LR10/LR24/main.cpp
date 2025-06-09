#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

// Функція для обчислення найбільшого спільного дільника
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return abs(a); // Повертаємо абсолютне значення
}

// Клас для роботи з дробами
class Fraction {
public:
    // Конструктор з перевіркою та нормалізацією знаку
    Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero."); // Помилка, якщо знаменник = 0
        }

        // Змінюємо знак чисельника, якщо знаменник від’ємний
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        this->numerator = numerator;
        this->denominator = denominator;
        reduce(); // Скорочуємо дріб одразу при створенні
    }

    // Перетворення дробу у рядок
    string toString() {
        int wholePart = numerator / denominator;               // Ціла частина
        int remainder = abs(numerator % denominator);          // Остача
        int absDen = abs(denominator);                         // Абсолютне значення знаменника

        if (remainder == 0) {
            return to_string(wholePart);                       // Якщо остача нуль — просто число
        } else if (wholePart != 0) {
            // Змішаний дріб
            return to_string(wholePart) + " " + to_string(remainder) + "/" + to_string(absDen);
        } else {
            // Звичайний дріб (без цілої частини)
            string sign = (numerator < 0) ? "-" : "";
            return sign + to_string(remainder) + "/" + to_string(absDen);
        }
    }

    // Повертає десяткове представлення дробу
    double toDouble() {
        return static_cast<double>(numerator) / denominator;
    }

    // Порівняння: більше
    bool isGreaterThan(Fraction that) {
        return (this->numerator * that.denominator > that.numerator * this->denominator);
    }

    // Порівняння: менше
    bool isLessThan(Fraction that) {
        return (this->numerator * that.denominator < that.numerator * this->denominator);
    }

    // Порівняння: рівність
    bool isEqual(Fraction that) {
        return (this->numerator * that.denominator == that.numerator * this->denominator);
    }

private:
    int numerator;
    int denominator;

    // Метод для скорочення дробу
    void reduce() {
        int common = gcd(numerator, denominator); // Обчислюємо НСД
        numerator /= common;
        denominator /= common;
    }
};

// Основна функція
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

    // Створення об’єктів дробів
    Fraction f1(num1, den1);
    Fraction f2(num2, den2);

    string result;

    // Порівняння дробів
    if (f1.isGreaterThan(f2)) {
        result = f1.toString() + " > " + f2.toString();
    } else if (f1.isLessThan(f2)) {
        result = f1.toString() + " < " + f2.toString();
    } else {
        result = f1.toString() + " = " + f2.toString();
    }

    // Виведення результату порівняння
    cout << result << endl;

    return 0;
}
