#include <iostream>
using namespace std;

int main(){
    
    int num1, num2, num3, num4;
    
    cout << "Enter thxe first number: ";
    cin >> num1;
    
    cout << "Enter the second number: ";
    cin >> num2;
    
    cout << "Enter the third number: ";
    cin >> num3;
    
    cout << "Enter the fourth number: ";
    cin >> num4;
    
    if((num1 >= 1 && num1 <=255) &&
       (num2 >= 1 && num2 <=255) &&
       (num3 >= 1 && num3 <=255) &&
       (num4 >= 1 && num4 <=255)){
        cout << num1 << "." << num2 << "." << num3 << "." << num4 << "." << "\n" ;
    }else{
        cout << "Incorrect numbers"<< "/n";
    }
    
    return 0;
}
