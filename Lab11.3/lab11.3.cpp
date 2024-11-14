#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Employee {
    string surname;
    string initials;
    string position;
    int hireYear;
    double salary;
};

const string FILENAME = "WORK.txt"; // Ім'я файлу встановлено як константу

// Функція для додавання запису про службовця у файл
void AddEmployee() {
    Employee emp;
    cout << "Enter surename: ";
    cin >> emp.surname;
    cout << "Enter initials: ";
    cin >> emp.initials;
    cout << "Enter the position: ";
    cin >> emp.position;
    cout << "Enter the year of recruitment: ";
    cin >> emp.hireYear;
    cout << "Enter salary: ";
    cin >> emp.salary;

    ofstream fout(FILENAME, ios::app);
    if (!fout) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    fout << emp.surname << " " << emp.initials << " " << emp.position << " "
        << emp.hireYear << " " << emp.salary << endl;
    fout.close();

    cout << "The record has been added to the file." << endl;
}

// Функція для виведення списку службовців з файлу
void DisplayEmployees() {
    ifstream fin(FILENAME);
    if (!fin) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    Employee emp;
    cout << left << setw(15) << "Name" << setw(10) << "Initials"
        << setw(15) << "Position" << setw(10) << "Year of admission" << setw(10) << "Salary" << endl;
    cout << "---------------------------------------------------------" << endl;
    while (fin >> emp.surname >> emp.initials >> emp.position >> emp.hireYear >> emp.salary) {
        cout << left << setw(15) << emp.surname << setw(10) << emp.initials
            << setw(15) << emp.position << setw(10) << emp.hireYear << setw(10) << emp.salary << endl;
    }
    fin.close();
}

// Функція для пошуку службовця за прізвищем
void SearchEmployee(const string& surname) {
    ifstream fin(FILENAME);
    if (!fin) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    Employee emp;
    bool found = false;
    while (fin >> emp.surname >> emp.initials >> emp.position >> emp.hireYear >> emp.salary) {
        if (emp.surname == surname) {
            cout << "Employee found:" << endl;
            cout << "Name: " << emp.surname << endl;
            cout << "Initials: " << emp.initials << endl;
            cout << "Position: " << emp.position << endl;
            cout << "Year of admission: " << emp.hireYear << endl;
            cout << "Salary: " << emp.salary << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "An employee with a surname " << surname << " not found." << endl;
    }
    fin.close();
}

// Функція для відображення меню
void DisplayMenu() {
    cout << "\nMENU:" << endl;
    cout << "1 - Add an employee" << endl;
    cout << "2 - View the list of employees" << endl;
    cout << "3 - Find an employee by last name" << endl;
    cout << "0 - Exit" << endl;
    cout << "Select an option: ";
}

// Основна функція
int main() {
    int choice;
    do {
        DisplayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            AddEmployee();
            break;
        case 2:
            DisplayEmployees();
            break;
        case 3: {
            string surname;
            cout << "Enter last name to search: ";
            cin >> surname;
            SearchEmployee(surname);
            break;
        }
        case 0:
            cout << "Exit the program." << endl;
            break;
        default:
            cout << "Wrong choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
