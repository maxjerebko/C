
#include <iostream>   // Для вводу/виводу
#include <string>
using namespace std;

// Клас звичайного квадрата з кешованим обчисленням площі
class Square {
private:
    double sideLength;    // Довжина сторони
    double squareArea;    // Площа квадрата

public:
    Square(double initialSide);          // Конструктор
    void setSide(double newSide);        // Метод для встановлення сторони
    void printInfo() const;              // Метод для виводу інформації
};

// Конструктор: одразу викликає метод установки сторони
Square::Square(double initialSide) {
    setSide(initialSide);  // Ініціалізація сторони
}

// Установка сторони та автоматичне обчислення площі
void Square::setSide(double newSide) {
    if (newSide >= 0) {
        this->sideLength = newSide;
        this->squareArea = newSide * newSide;
    }
}

// Виведення сторони та площі
void Square::printInfo() const {
    cout << "Square: side = " << sideLength << " area = " << squareArea << endl;
}

// ==================== AdHocSquare ====================

// Клас без кешування площі — обчислює її щоразу при запиті
class AdHocSquare {
public:
    AdHocSquare(double initialSide);     // Конструктор
    void setSide(double newSide);        // Метод встановлення сторони
    double getArea();                    // Метод обчислення площі

private:
    double sideLength;  // Довжина сторони
};

// Конструктор з ініціалізацією сторони
AdHocSquare::AdHocSquare(double initialSide) {
    setSide(initialSide);
}

// Встановлення нової сторони
void AdHocSquare::setSide(double newSide) {
    if (newSide >= 0) {
        this->sideLength = newSide;
    }
}

// Площа обчислюється кожного разу при виклику
double AdHocSquare::getArea() {
    return sideLength * sideLength;
}

// ==================== LazySquare ====================

// Клас із лінивим (відкладеним) обчисленням площі
class LazySquare {
public:
    LazySquare(double initialSide);     // Конструктор
    void setSide(double newSide);       // Метод встановлення сторони
    double getArea();                   // Метод отримання площі

private:
    double sideLength;
    double squareArea;
    bool sideModified;  // Прапорець, що вказує на зміну сторони
};

// Конструктор одразу обчислює площу
LazySquare::LazySquare(double initialSide) {
    this->sideLength = initialSide;
    this->squareArea = initialSide * initialSide;
    this->sideModified = false;
}

// Установка нової сторони та позначення, що площа потребує оновлення
void LazySquare::setSide(double newSide) {
    if (newSide >= 0) {
        this->sideLength = newSide;
        this->sideModified = true;
    }
}

// Обчислення площі лише якщо сторона змінилась
double LazySquare::getArea() {
    if (sideModified) {
        squareArea = sideLength * sideLength;
        sideModified = false;  // Скидання прапорця
    }
    return squareArea;
}

// ==================== main ====================

int main() {
    // Демонстрація роботи класу Square
    Square squareObj(4);
    squareObj.printInfo();               // Виводимо площу при стороні 4

    squareObj.setSide(2.0);              // Змінюємо сторону на 2
    squareObj.printInfo();               // Виводимо нову площу

    squareObj.setSide(-33.0);            // Невалідне значення — не змінюється
    squareObj.printInfo();               // Площа залишається незмінною

    cout << endl;

    // Демонстрація роботи класу AdHocSquare
    AdHocSquare adhoc(4);
    cout << "Area: " << adhoc.getArea() << endl;  // 16

    adhoc.setSide(2.0);
    cout << "Area: " << adhoc.getArea() << endl;  // 4

    adhoc.setSide(-5);                             // Ігнорується
    cout << "Area: " << adhoc.getArea() << endl;  // все ще 4

    cout << "\nLazySquare" << endl;

    // Демонстрація LazySquare
    LazySquare lazy(4);
    cout << "Area: " << lazy.getArea() << endl;   // 16

    lazy.setSide(2.0);
    cout << "Area: " << lazy.getArea() << endl;   // 4

    lazy.setSide(-10);                            // Ігнорується
    cout << "Area: " << lazy.getArea() << endl;   // залишилось 4

    return 0;
}
