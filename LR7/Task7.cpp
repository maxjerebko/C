#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi4 = 0.0;
    long iterations;

    cout << "Enter the number of iterations: ";
    cin >> iterations;

    for (long i = 0; i < iterations; i++) {
        double term = 1.0 / (2.0 * i + 1.0);

        if (i % 2 == 0) {
            pi4 += term; // Додаємо член ряду, якщо індекс парний
        } else {
            pi4 -= term; // Віднімаємо член ряду, якщо індекс непарний
        }
    }

    cout << fixed << setprecision(20); // Форматований вивід
    cout << "Approximation of Pi = " << (pi4 * 4.0) << endl;

    return 0;
}
