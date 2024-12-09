#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    double inputValues[5];
    double calculatedResults[5];

    cout << "Enter five values for x: ";
    
    // Введення значень для inputValues
    for (int i = 0; i < 5; i++) {
        cin >> inputValues[i];
    }
    
    // Розрахунок значень для calculatedResults
    for (int i = 0; i < 5; i++) {
        calculatedResults[i] = pow(sin(inputValues[i]), 5) + fabs(5 * inputValues[i] - 1.5);
    }
    
    // Виведення результатів
    for (int i = 0; i < 5; i++) {
        cout << "y = " << calculatedResults[i] << "\n";
    }
    
    return 0;
}
