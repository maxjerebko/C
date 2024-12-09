#include <iostream>
#include <math.h>
using namespace std;

int main(){
    
    double x, y, a,b;
    
    cout << " x: " ;
    cin >> x;
    
    cout << "a: " ;
    cin >> a;
    
    cout << "b: " ;
    cin >> b;
    
    if (b == 0) {
        cout << "There is no solution. Enter another value for b: ";
        cin >> b;
    }
    
    
    if(x >= 0){
        y = cos(x) - pow(sin(x), 3) ;
    }
    else{
        y =  x * exp(-x)+(1/x-1.3) ;
    }
    
    
    
    cout << "Results: " << y << "\n";
    
    return 0;
}
