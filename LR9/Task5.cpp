#include <iostream>
#include <vector>
#include <limits> // Для використання мінімальних значень типу int

using namespace std;

int main() {
    // Заданий масив
    vector<int> arr = {5, 2, 9, 3, 7, 1};

    if (arr.size() < 2) {
        cout << "Масив має містити щонайменше два елементи." << endl;
        return 1;
    }

    int max1 = INT_MIN; // Найбільший елемент
    int max2 = INT_MIN; // Другий за величиною елемент

    // Проходимо по елементах масиву
    for (int num : arr) {
        if (num > max1) {
            // Якщо знайдено новий найбільший елемент
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            // Якщо знайдено елемент, більший за max2, але менший за max1
            max2 = num;
        }
    }

    cout << "Другий за величиною елемент: " << max2 << endl;

    return 0;
}
