#include <iostream>
using namespace std;

int main() {
    bool isConditionMet; 
    int inputValue;

    cout << "Enter a value: ";
    cin >> inputValue;

    isConditionMet = (inputValue >= 0 && inputValue <= 10) ||
                     (inputValue * 2 < 20 && inputValue - 2 > -2) ||
                     (inputValue - 1 > 1 && inputValue / 2.0 < 10) ||
                     (inputValue == 111);

    cout << (isConditionMet ? "THAT'S TRUE :)" : "THAT'S NOT TRUE :(") << endl;
    return 0;
}
