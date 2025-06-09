#include <iostream>
using namespace std;

// ===== Exercise 1 =====

// Функція перевіряє, чи є рік високосним
bool isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;  // Якщо рік високосний
    } else {
        return false; // Інакше - не високосний
    }
}

// ===== Exercise 2 =====

// Функція повертає кількість днів у місяці певного року
int monthLength(int year, int month) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;  // Місяці з 31 днем
        case 4: case 6: case 9: case 11:
            return 30;  // Місяці з 30 днями
        case 2:
            if (isLeap(year)) {
                return 29;  // Лютий у високосному році
            } else {
                return 28;  // Лютий у звичайному році
            }
        default:
            return -1;  // Невірний номер місяця
    }
}

int main() {

    // ===== Перевірка функції isLeap для років 95–104 =====
    for (int yr = 95; yr < 105; yr++) {
        cout << yr << " -> " << isLeap(yr) << endl;  // Вивід: чи рік високосний
    }

    cout << endl;

    // ===== Вивід кількості днів у кожному місяці для 2000 та 2001 років =====
    for (int yr = 2000; yr < 2002; yr++) {
        for (int mo = 1; mo <= 12; mo++) {
            cout << monthLength(yr, mo) << " ";  // Кількість днів у місяці
        }
        cout << endl;  // Перехід на новий рядок для нового року
    }

    cout << endl;

    return 0;  // Завершення програми
}
