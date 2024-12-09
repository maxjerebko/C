#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Заданий масив
    vector<int> arr = {5, 2, 9, 3, 7, 1, 10, 4};
    
    // Введення числа A
    int A;
    cout << "Введіть число A: ";
    cin >> A;

    // Лічильник для елементів, більших за A
    int count = 0;

    // Перевірка кожного елемента масиву
    for (int num : arr) {
        if (num > A) {
            count++;
        }
    }

    // Виведення результату
    cout << "Кількість елементів масиву, більших за " << A << ": " << count << endl;

    return 0;
}
