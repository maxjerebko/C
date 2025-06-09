#include <iostream>
#include <ctime>  // Для отримання поточної дати
using namespace std;

// Структура, що представляє дату
struct Date {
    int year;
    int month;
    int day;
};

// Функція для отримання сьогоднішньої дати
Date today() {
    time_t t = time(NULL);         // Отримати поточний час
    tm tl = *localtime(&t);        // Перетворити на локальний час

    Date d;
    d.year = tl.tm_year + 1900;    // tm_year – це кількість років з 1900
    d.month = tl.tm_mon + 1;       // tm_mon – це місяць (0–11), тому додаємо 1
    d.day = tl.tm_mday;            // День місяця

    return d;                      // Повертаємо поточну дату
}

// Перевірка, чи рік високосний
bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Повертає кількість днів у місяці
int monthLength(int year, int month) {
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};  // Стандартна кількість днів

    if (month == 2 && isLeap(year)) {
        return 29;  // Лютий у високосному році
    }
    return daysInMonth[month - 1];  // Для інших місяців
}

// Обчислює кількість днів між двома датами
int daysBetweenBirthday(Date d1, Date d2) {
    int days1 = d1.day;

    // Додаємо всі дні до початку року d1
    for (int y = 1; y < d1.year; y++) {
        days1 += isLeap(y) ? 366 : 365;
    }

    // Додаємо дні з початку року до місяця народження
    for (int m = 1; m < d1.month; m++) {
        days1 += monthLength(d1.year, m);
    }

    int days2 = d2.day;

    // Те саме для другої дати
    for (int y = 1; y < d2.year; y++) {
        days2 += isLeap(y) ? 366 : 365;
    }

    for (int m = 1; m < d2.month; m++) {
        days2 += monthLength(d2.year, m);
    }

    return abs(days2 - days1) + 1;  // Повертаємо абсолютну різницю в днях +1
}

int main() {
    Date user;

    // Ввід дати народження користувача
    cout << "Enter your date (year, month, day): ";
    cin >> user.year >> user.month >> user.day;

    // Вивід дати народження
    cout << "Your birthday is " << user.year << "-"
         << user.month << "-" << user.day << endl;

    // Отримання поточної дати
    Date t = today();
    cout << "Today is " << t.year << "-" << t.month << "-" << t.day << endl;

    // Обчислення пройдених днів
    int daysPassed = daysBetweenBirthday(user, t);
    cout << "Days passed since birthday: " << daysPassed << endl;

    return 0;
}
