#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int m = 3; // Кількість рядків
    const int n = 3; // Кількість стовпців
    
    int array[m][n]; // Оголошення масиву
    
    srand(static_cast<unsigned int>(time(0))); // Ініціалізація генератора випадкових чисел
    
    // Заповнення масиву випадковими числами від 1 до 50
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = rand() % 50 + 1;
        }
    }
    
    // Виведення масиву
    cout << "Згенерований масив:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
    
    int main_diagonal_sum = 0;      // Сума елементів головної діагоналі
    int secondary_diagonal_sum = 0; // Сума елементів побічної діагоналі
    
    // Обчислення сум для головної та побічної діагоналей
    for (int i = 0; i < m; i++) {
        main_diagonal_sum += array[i][i];
        secondary_diagonal_sum += array[i][n - i - 1];
    }
    
    // Виведення результатів
    cout << "\nСума чисел по головній діагоналі: " << main_diagonal_sum << "\n";
    cout << "Сума чисел по побічній діагоналі: " << secondary_diagonal_sum << "\n";
    
    return 0;
}
