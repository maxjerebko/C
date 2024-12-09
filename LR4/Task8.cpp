#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    int firstValue, secondValue;
    float reciprocal1, reciprocal2;
    const float epsilon = 0.000001f;
    
    cout << "Enter the first number: ";
    cin >> firstValue;
    
    cout << "Enter the second number: ";
    cin >> secondValue;
    
    if (firstValue == 0 || secondValue == 0) {
        cout << "Division by zero is not allowed!";
        return 1;
    }
    
    reciprocal1 = (float) 1 / firstValue;
    reciprocal2 = (float) 1 / secondValue;
    
    if (fabs(reciprocal1 - reciprocal2) < epsilon) {
        cout << "Results are equal (by 0.000001 epsilon)" << "\n";
    } else {
        cout << "Results are not equal (by 0.000001 epsilon)" << "\n";
    }
    
    return 0;
}

