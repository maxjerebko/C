#include <iostream>
#include <vector>
#include <algorithm> // Для std::min_element і std::max_element

using namespace std;

int main() {
    // Приклад масиву
    vector<int> arr = {5, 2, 9, 3, 7, 1};

    cout << "Початковий масив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Знаходимо ітератори мінімального і максимального елементів
    auto minIt = min_element(arr.begin(), arr.end());
    auto maxIt = max_element(arr.begin(), arr.end());

    // Міняємо їх місцями
    iter_swap(minIt, maxIt);

    cout << "Масив після зміни місцями найбільшого і найменшого елементів: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
