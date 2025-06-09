#include <iostream>  // Підключення бібліотеки для роботи з введенням/виведенням
using namespace std;  // Використання простору імен std

int addOne(int &value) {
    return value++;  // Збільшення значення на 1 (після повернення поточного значення)
}

int addValue(int &target, int incrementBy) {
    return target += incrementBy;  // Додавання значення incrementBy до target
}

int main(void) {
    
    int total = 0;  // Ініціалізація змінної total значенням 0

    for(int index = 0; index < 10; index++)  // Цикл від 0 до 9
        if(index % 2)  // Якщо index непарний
            addOne(total);  // Збільшуємо total на 1
        else
            addValue(total, index);  // Додаємо до total значення index

    cout << total << endl;  // Виводимо підсумкове значення total на екран
    return 0;  // Завершення програми
}
