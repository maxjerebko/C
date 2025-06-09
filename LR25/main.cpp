#include <iostream>
using namespace std;

// Абстрактний базовий клас
class Base {
public:
    virtual char getSymbol() = 0;      // Отримати символ дерева
    virtual int number() = 0;          // Отримати номер дерева
    virtual ~Base() {}

    // Метод для малювання дерева
    virtual void draw() {
        cout << "Малюємо дерево #" << number() << endl;
        
        int height = 3; // Висота дерева

        for (int i = 0; i < height; ++i) {
            string line;

            // Пробіли перед деревом
            for (int j = 0; j < height - i - 1; ++j) line += " ";

            // Ліва коса риска
            line += "/";

            // Символи між косими рисками
            for (int j = 0; j < 2 * i; ++j) line += getSymbol();

            // Права коса риска
            line += "\\";

            cout << line << endl;
        }
    }
};

// Дочірній клас — дерево з косими рисками
class TreeWithSlash : public Base {
public:
    char getSymbol() override {
        return '/';
    }

    int number() override {
        return 1;
    }
};

// Дочірній клас — дерево з зірочками
class TreeWithStars : public Base {
public:
    char getSymbol() override {
        return '*';
    }

    int number() override {
        return 2;
    }
};

// Дочірній клас — дерево з плюсиками
class TreeWithPlus : public Base {
public:
    char getSymbol() override {
        return '+';
    }

    int number() override {
        return 3;
    }
};

int main() {
    // Масив з вказівниками на базовий клас
    Base* forest[3];

    // Створення об'єктів дерев
    TreeWithSlash t1;
    TreeWithStars t2;
    TreeWithPlus t3;

    // Запис у масив
    forest[0] = &t1;
    forest[1] = &t2;
    forest[2] = &t3;

    // Вивід кожного дерева
    for (int i = 0; i < 3; ++i) {
        forest[i]->draw();
        cout << endl;
    }

    return 0;
}
    
