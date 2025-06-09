#include <iostream>  // Підключення бібліотеки для введення/виведення
#include <string>    // Підключення бібліотеки для роботи з рядками

using namespace std;  // Використання простору імен std

// Функція для отримання значення за ключем із рядка у форматі key=value
string extractValue(const string& key, const string& data) {
    size_t position = data.find(key + "=");  // Пошук позиції ключа з форматом key=
    if (position == string::npos) return "";  // Якщо не знайдено — повертаємо порожній рядок

    size_t valueStart = position + key.length() + 1;  // Початок значення після "="
    size_t valueEnd = data.find(',', valueStart);  // Пошук кінця значення (роздільник - кома)
    if (valueEnd == string::npos) valueEnd = data.length();  // Якщо кома не знайдена — кінець рядка

    return data.substr(valueStart, valueEnd - valueStart);  // Повертаємо значення
}

int main() {
    string inputData, inputText;  // Змінні для збереження вхідних даних і тексту

    getline(cin, inputData);  // Зчитування першого рядка (наприклад: "name=Bob,age=30")
    getline(cin, inputText);  // Зчитування другого рядка з текстом, який містить шаблони (наприклад: "Hello [name]")

    string finalText;  // Змінна для збереження результату

    for (size_t index = 0; index < inputText.length(); ) {  // Проходимо кожен символ тексту
        if (inputText[index] == '[') {  // Якщо початок шаблону
            size_t closingBracket = inputText.find(']', index);  // Шукаємо закриваючу дужку
            if (closingBracket != string::npos) {  // Якщо знайдено
                string placeholder = inputText.substr(index + 1, closingBracket - index - 1);  // Отримуємо ключ без дужок
                string replacement = extractValue(placeholder, inputData);  // Отримуємо значення для ключа

                if (replacement != "") {
                    finalText += replacement;  // Якщо значення знайдено — додаємо його
                } else {
                    finalText += "[" + placeholder + "]";  // Якщо не знайдено — залишаємо як є
                }

                index = closingBracket + 1;  // Переходимо до наступного символа після закриваючої дужки
            } else {
                finalText += inputText[index];  // Якщо немає закриваючої дужки — додаємо символ як є
                index++;
            }
        } else {
            finalText += inputText[index];  // Якщо звичайний символ — додаємо до результату
            index++;
        }
    }

    cout << finalText << "\n";  // Виводимо фінальний результат
    return 0;  // Завершення програми
}
