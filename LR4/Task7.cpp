#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  
    double firstNumber;
    double secondNumber;
    double thirdNumber;
    double fourthNumber;
    double fifthNumber;

    // Введення чисел
    cout << "Enter the first number: ";
    cin >> firstNumber;
   
    cout << "Enter the second number: ";
    cin >> secondNumber;
    
    cout << "Enter the third number: ";
    cin >> thirdNumber;
    
    cout << "Enter the fourth number: ";
    cin >> fourthNumber;
    
    cout << "Enter the fifth number: ";
    cin >> fifthNumber;

    // Виведення чисел із форматуванням
    cout << firstNumber << "\n";
    cout << fixed << setprecision(2) << secondNumber << "\n";
    cout << fixed << setprecision(6) << thirdNumber << "\n";
    cout << fixed << setprecision(2) << fourthNumber << "\n";
    cout << fixed << setprecision(0) << fifthNumber << "\n";
    
    return 0;
}

