#include <string>    // Для роботи з рядками
#include <iostream>  // Для введення/виведення
#include <cctype>    // Для перевірки символів (isupper, islower тощо)


// Перевірка наявності хоча б однієї великої літери
bool containsUpperCase(const std::string& text) {
    for (char character : text) {
        if (std::isupper(character)) return true;
    }
    return false;
}

// Перевірка наявності хоча б однієї малої літери
bool containsLowerCase(const std::string& text) {
    for (char character : text) {
        if (std::islower(character)) return true;
    }
    return false;
}

// Перевірка наявності хоча б однієї цифри
bool containsDigit(const std::string& text) {
    for (char character : text) {
        if (std::isdigit(character)) return true;
    }
    return false;
}

// Перевірка наявності хоча б одного спеціального символу
bool containsSpecialChar(const std::string& text) {
    for (char character : text) {
        if (!std::isalnum(character)) return true;  // Не літера і не цифра
    }
    return false;
}

// Перевірка пароля за всіма критеріями, результат передається через is_valid
bool validatePassword(const std::string& password, bool& is_valid) {

    if (password.length() < 8) {  // Якщо довжина менше 8
        std::cout << "The password must be 8 characters long\n";
        is_valid = false;
    }

    if (!containsUpperCase(password)) {  // Немає великої літери
        std::cout << "The password must have at least one upper case letter\n";
        is_valid = false;
    }

    if (!containsLowerCase(password)) {  // Немає малої літери
        std::cout << "The password must have at least one lower case letter\n";
        is_valid = false;
    }

    if (!containsDigit(password)) {  // Немає цифри
        std::cout << "The password must have at least one digit\n";
        is_valid = false;
    }

    if (!containsSpecialChar(password)) {  // Немає спецсимволу
        std::cout << "The password must have at least one special character\n";
        is_valid = false;
    }

    return is_valid;  // Повертаємо статус валідності
}

int main() {
    std::string userPassword;  // Змінна для збереження введеного пароля

    while (true) {  // Нескінченний цикл до успішного введення
        std::cout << "Enter your password: ";  // Запрошення на введення
        std::getline(std::cin, userPassword);  // Зчитування пароля з пробілами

        bool isPasswordValid = true;  // Початкове припущення, що пароль валідний

        validatePassword(userPassword, isPasswordValid);  // Перевірка пароля

        if (isPasswordValid) {  // Якщо всі умови виконано
            std::cout << "The password is valid\n";
            break;  // Вихід із циклу
        } else {
            std::cout << "Please try again!\n\n";  // Повідомлення про помилку
        }
    }

    return 0;  // Завершення програми
}
