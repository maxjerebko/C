#include <iostream>
using namespace std;

int main() {
    char firstLetter;

    // Введення першої літери назви країни
    cout << "Enter the first letter of the country's name (A-G): ";
    cin >> firstLetter;

    // Використання switch для визначення континенту та площі
    switch (toupper(firstLetter)) { // Перетворення літери у верхній регістр
        case 'A':
            cout << "Country: Australia\n";
            cout << "Continent: Australia\n";
            cout << "Area: 7,692,024 km²\n";
            break;
        case 'B':
            cout << "Country: Brazil\n";
            cout << "Continent: South America\n";
            cout << "Area: 8,515,767 km²\n";
            break;
        case 'C':
            cout << "Country: Canada\n";
            cout << "Continent: North America\n";
            cout << "Area: 9,984,670 km²\n";
            break;
        case 'D':
            cout << "Country: Denmark\n";
            cout << "Continent: Europe\n";
            cout << "Area: 42,933 km²\n";
            break;
        case 'E':
            cout << "Country: Egypt\n";
            cout << "Continent: Africa\n";
            cout << "Area: 1,010,408 km²\n";
            break;
        case 'F':
            cout << "Country: France\n";
            cout << "Continent: Europe\n";
            cout << "Area: 551,695 km² (mainland)\n";
            break;
        case 'G':
            cout << "Country: Greenland\n";
            cout << "Continent: North America\n";
            cout << "Area: 2,166,086 km²\n";
            break;
        default:
            cout << "Error: No country found for the entered letter.\n";
            break;
    }

    return 0;
}

