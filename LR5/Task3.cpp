#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double a, b, h; // Початок, кінець відрізка і крок
    cout << "Enter the start of the range (a): ";
    cin >> a;
    cout << "Enter the end of the range (b): ";
    cin >> b;
    cout << "Enter the step (h): ";
    cin >> h;

    // Перевірка на коректність кроку
    if (h <= 0) {
        cout << "Step must be positive!" << endl;
        return 1;
    }

    cout << "-------------------" << endl;
    cout << ": X       : Y       :" << endl;
    cout << "-------------------" << endl;

    double x = a; // Початкове значення
    while (x <= b) {
        // Перевірка області визначення функції
        if (x == 0 || (x + 3) < 0) {
            cout << "Value x = " << x << " is out of domain (division by zero or negative root)!" << endl;
            break;
        }

        // Обчислення функції
        double y = (1 / x) + sqrt(x + 3) + 6;

        // Виведення результату
        cout << ": " << setw(7) << fixed << setprecision(2) << x
             << " : " << setw(7) << fixed << setprecision(2) << y << " :" << endl;

        // Збільшення x на крок
        x += h;
    }

    cout << "-------------------" << endl;
    return 0;
}
