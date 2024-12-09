#include <iostream>
using namespace std;

int main() {
    const int limit = 15; // Кількість чисел, для яких обчислюємо факторіал
    
    // Виведення факторіалів від 0 до 15
    for (int i = 0; i <= limit; i++) {
        unsigned long long factorial = 1; // Використовуємо `unsigned long long` для великих значень
        for (int j = 1; j <= i; j++) {
            factorial *= j; // Обчислення факторіалу
        }
        cout << "Factorial of " << i << " is " << factorial << endl;
    }
    
    return 0;
}
