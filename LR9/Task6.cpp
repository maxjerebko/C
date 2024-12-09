#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

int main() {
   
   srand(static_cast<unsigned int>(time(0)));

  
   const int size = 10;
   int arr[size];

   
   for (int i = 0; i < size; ++i) {
       arr[i] = rand() % 21 - 10;
   }


   cout << "Generated array: ";
   for (int i = 0; i < size; ++i) {
       cout << arr[i] << " ";
   }
   cout <<  "\n";

   
   int index = -1;
   for (int i = 0; i < size; ++i) {
       if (arr[i] == 0) {
           index = i;
           break;
       }
   }

  
   if (index != -1) {
       cout << "The index of the first zero element is: " << index <<  "\n";
   } else {
       cout << "The array does not contain any zero elements." <<  "\n";
   }

   return 0;
}
