#include <iostream>   // Для введення/виведення
#include <string>     // Для роботи з рядками
using namespace std;  // Використання стандартного простору імен

// Клас, що представляє людину
class Person {
public:
    string firstName;   // Ім'я
    string lastName;    // Прізвище
    int age;            // Вік
    double height;      // Зріст у сантиметрах

    // Метод для самопредставлення
    void introduceYourself() {
        cout << "Hello, I'm " << firstName << " " << lastName
             << ", a " << age << "-year-old." << endl;  // Виведення імені, прізвища та віку
        cout << "Height: " << height << " cm." << endl;  // Виведення зросту
        cout << endl;
    }
};

// Функція для виведення інформації про людину
void displayPersonInfo(Person* personPtr) {
    cout << personPtr->firstName << " " << personPtr->lastName
         << " is " << personPtr->age << " years old." << endl;  // Виведення віку
    cout << "Height: " << personPtr->height << " cm." << endl;  // Виведення зросту
    cout << endl;
}

int main() {
    // Створення першого об'єкта Person
    Person mainCharacter;
    mainCharacter.firstName = "Dima";        // Присвоєння імені
    mainCharacter.lastName = "Osipov";        // Присвоєння прізвища
    mainCharacter.age = 22;                   // Присвоєння віку
    mainCharacter.height = 185.5;             // Присвоєння зросту

    cout << "Meet " << mainCharacter.firstName << "!" << endl;  // Знайомство з першим персонажем

    displayPersonInfo(&mainCharacter);        // Виклик функції для виведення інформації
    mainCharacter.introduceYourself();        // Виклик методу для самопредставлення

    // Створення другого об'єкта Person
    Person friendCharacter;
    friendCharacter.firstName = "Maxim";
    friendCharacter.lastName = "Sherebko";
    friendCharacter.age = 19;
    friendCharacter.height = 170;

    cout << "Meet " << friendCharacter.firstName << "!" << endl;

    displayPersonInfo(&friendCharacter);      // Виведення інформації про другого персонажа
    friendCharacter.introduceYourself();      // Самопредставлення другого персонажа

    return 0;  // Завершення програми
}

