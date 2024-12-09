#include <iostream>
#include <iomanip> // Для використання setw() та setfill()

using namespace std;

// Структура Date для збереження годин та хвилин
struct Date {
    int hours;
    int minutes;
};

// Функція для додавання хвилин до часу
Date addMinutes(const Date& start, int additionalMinutes) {
    Date result;
    int totalMinutes = start.hours * 60 + start.minutes + additionalMinutes;

    // Переводимо загальну кількість хвилин у формат ГГ:ХХ
    result.hours = (totalMinutes / 60) % 24; // Знаходимо години (циклічно 0-23)
    result.minutes = totalMinutes % 60;     // Знаходимо хвилини
    return result;
}

int main() {
    Date time;
    int additionalMinutes;

    // Введення початкового часу
    cout << "Введіть години (0-23): ";
    cin >> time.hours;
    cout << "Введіть хвилини (0-59): ";
    cin >> time.minutes;

    // Перевірка на коректність введених даних
    if (time.hours < 0 || time.hours >= 24 || time.minutes < 0 || time.minutes >= 60) {
        cout << "Некоректний час!" << endl;
        return 1;
    }

    // Введення додаткових хвилин
    cout << "Введіть кількість хвилин, які потрібно додати: ";
    cin >> additionalMinutes;

    // Обчислення нового часу
    Date newTime = addMinutes(time, additionalMinutes);

    // Виведення нового часу у форматі ГГ:ХХ
    cout << "Новий час: "
         << setw(2) << setfill('0') << newTime.hours << ":"
         << setw(2) << setfill('0') << newTime.minutes << endl;

    return 0;
}

