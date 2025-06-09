#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Базовий клас для IP-адреси
class IPAddress {
protected:
    string address; // Зберігає IP-адресу

public:
    // Конструктор ініціалізації
    IPAddress(const string& addr) : address(addr) {}

    // Конструктор копіювання
    IPAddress(const IPAddress& other) : address(other.address) {}

    // Метод виведення IP-адреси
    virtual void print() const {
        cout << "IP Address: " << address << endl;
    }

    virtual ~IPAddress() {}
};

// Клас-нащадок з перевіркою правильності IP
class IPAddressChecked : public IPAddress {
    bool isCorrect; // Позначає, чи є IP правильним

    // Метод перевірки IP-адреси
    bool checkIP(const string& ip) {
        stringstream ss(ip); // Створюємо потік для розділення по крапках
        string part;
        int count = 0;

        // Проходимо кожну частину IP (до крапки)
        while (getline(ss, part, '.')) {
            if (++count > 4) return false;                 // Більше 4 частин — помилка
            if (part.empty() || part.size() > 3) return false; // Порожня або завелика частина

            for (char ch : part)
                if (!isdigit(ch)) return false;           // Частина містить нецифри

            int num = stoi(part);                          // Перетворення у число
            if (num < 0 || num > 255) return false;        // Невалідне значення
        }

        return count == 4; // Повинно бути рівно 4 частини
    }

public:
    // Конструктор з перевіркою IP
    IPAddressChecked(const string& addr) : IPAddress(addr) {
        isCorrect = checkIP(addr);
    }

    // Конструктор копіювання
    IPAddressChecked(const IPAddressChecked& other)
        : IPAddress(other), isCorrect(other.isCorrect) {}

    // Перевизначений метод виведення
    void print() const override {
        IPAddress::print();
        cout << (isCorrect ? "Correct" : "Not Correct") << endl;
    }
};

int main() {
    string ip1, ip2, ip3;

    // Зчитування IP-адрес
    cout << "Enter first IP (no validation): ";
    getline(cin, ip1);
    IPAddress ipObj(ip1);

    cout << "Enter second IP (with validation): ";
    getline(cin, ip2);
    IPAddressChecked ipChecked1(ip2);

    cout << "Enter third IP (with validation): ";
    getline(cin, ip3);
    IPAddressChecked ipChecked2(ip3);

    // Виведення результатів
    cout << "\n--- Results ---\n";
    ipObj.print();
    cout << endl;
    ipChecked1.print();
    cout << endl;
    ipChecked2.print();
    cout << endl;

    return 0;
}
