#include <iostream>
#include <math.h>
using namespace std;

int main() {
   
   double a, b, x;
   
   cout << "Enter value a: " ;
   cin >> a;
   
   cout << "Enter value b: " ;
   cin >> b;
   
    x = pow((11.21*(1+log(b/a)))/(1-sin((a/b)*M_PI)*cos((a/b)*M_PI)), 2./3);
   
   cout << "Results: " << x << "\n";
   
   return 0;
}



