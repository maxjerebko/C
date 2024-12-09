#include <iostream>
#include <iomanip> // Для використання setw() та setfill()

using namespace std;

// Структура Date для збереження годин та хвилин
struct Date {
    int hours;
    int minutes;
};

// Функція для обчислення тривалості між двома моментами часу
Date calculateDuration(const Date& start, const Date& end) {
    Date duration;
    
    // Перетворюємо час у хвилини для зручності обчислень
    int startMinutes = start.hours * 60 + start.minutes;
    int endMinutes = end.hours * 60 + end.minutes;

    // Якщо час завершення менший за час початку, вважаємо, що подія переходить через північ
    if (endMinutes < startMinutes) {
        endMinutes += 24 * 60; // Додаємо 24 години у хвилинах
    }

    // Загальна різниця в хвилинах
    int totalMinutes = endMinutes - startMinutes;

    // Перетворюємо хвилини назад у години та хвилини
    duration.hours = totalMinutes / 60;
    duration.minutes = totalMinutes % 60;

    return duration;
}

int main() {
    Date startTime, endTime;

    // Введення часу початку події
    cout << "Введіть час початку (години хвилини): ";
    cin >> startTime.hours >> startTime.minutes;

    // Перевірка коректності введеного часу
    if (startTime.hours < 0 || startTime.hours >= 24 || startTime.minutes < 0 || startTime.minutes >= 60) {
        cout << "Некоректний час початку!" << endl;
        return 1;
    }

    // Введення часу завершення події
    cout << "Введіть час завершення (години хвилини): ";
    cin >> endTime.hours >> endTime.minutes;

    // Перевірка коректності введеного часу
    if (endTime.hours < 0 || endTime.hours >= 24 || endTime.minutes < 0 || endTime.minutes >= 60) {
        cout << "Некоректний час завершення!" << endl;
        return 1;
    }

    // Обчислення тривалості події
    Date duration = calculateDuration(startTime, endTime);

    // Виведення тривалості події
    cout << "Тривалість події: "
         << duration.hours << ":"
         << setw(2) << setfill('0') << duration.minutes << endl;

    return 0;
}
