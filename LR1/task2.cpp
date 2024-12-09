#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, result;

   
    cout << "Enter value a: ";
    cin >> a;

    cout << "Enter value b: ";
    cin >> b;

    result = pow(
        (0.5 * sin(log(exp(1)) * (b + a) * (M_PI / 8)) +
         1.308 * cos(log(exp(1)) * (a - b) * (M_PI / 8))),
        2.0 / 3.0);

  
    cout << "Result: " << result << endl;

    return 0;
}

