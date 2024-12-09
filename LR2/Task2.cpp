#include <iostream>
using namespace std;

int main() {
    double x, y;

   
    cout << "Enter the x-coordinate of the point: ";
    cin >> x;

    cout << "Enter the y-coordinate of the point: ";
    cin >> y;

    
    if (x >= 0 && x <= 2 && y >= 0 && y <= 2 - x) {
        cout << "The point (" << x << ", " << y << ") is inside the shaded area." << endl;
    } else {
        cout << "The point (" << x << ", " << y << ") is outside the shaded area." << endl;
    }

    return 0;
}

