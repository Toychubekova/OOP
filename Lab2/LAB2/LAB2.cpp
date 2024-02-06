
//1 задание

//#include <iostream>
//#include <iomanip>
//#include <vector>
//#include <algorithm>
//#include <clocale>
// #include <windows.h>
//using namespace std;
//
//class Aeroflot {
//public:
//    int flightNumber;
//    string departureCity;
//    string destinationCity;
//    string arrivalTime;
//    string departureTime;
//    int registrationSection;
//
//    Aeroflot(int number, const string& departure, const string& destination,
//        const string& arrival, const string& departureTime, int registrationSection)
//        : flightNumber(number), departureCity(departure), destinationCity(destination),
//        arrivalTime(arrival), departureTime(departureTime), registrationSection(registrationSection) {}
//
//    
//    void displayFlightInfo() const {
//        cout << setw(6) << flightNumber << setw(15) << departureCity << setw(15) << destinationCity
//            << setw(15) << arrivalTime << setw(15) << departureTime << setw(15) << registrationSection << endl;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//    vector<Aeroflot> flights;
//    SetConsoleOutputCP(1251);
//    SetConsoleCP(1251);
//    int numberOfFlights;
//
//    cout << "Введите количество рейсов: ";
//    cin >> numberOfFlights;
//
//    for (int i = 0; i < numberOfFlights; ++i) {
//        int number, regSection;
//        string departure, destination, arrival, departureTime;
//
//        cout << "Введите номер рейса: ";
//        cin >> number;
//
//        cout << "Введите пункт отправления: ";
//        cin >> departure;
//
//        cout << "Введите пункт назначения: ";
//        cin >> destination;
//
//        cout << "Введите время прибытия: ";
//        cin >> arrival;
//
//        cout << "Введите время отправления: ";
//        cin >> departureTime;
//
//        cout << "Введите номер секции для регистрации: ";
//        cin >> regSection;
//
//        flights.emplace_back(number, departure, destination, arrival, departureTime, regSection);
//    }
//
//    
//    sort(flights.begin(), flights.end(), [](const Aeroflot& a, const Aeroflot& b) {
//        return a.destinationCity < b.destinationCity;
//        });
//
//  
//    cout << "\nСписок рейсов:\n";
//    cout << setw(6) << "Номер" << setw(15) << "Отправление" << setw(15) << "Назначение"
//        << setw(15) << "Прибытие" << setw(15) << "Отправление" << setw(15) << "Регистрация\n";
//
//    if (!flights.empty()) {
//        for (const auto& flight : flights) {
//            flight.displayFlightInfo();
//        }
//    }
//    else {
//        cout << "Нет доступных рейсов.\n";
//    }
//
//    return 0;
//}

// /*2 задание*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

class Student {
public:
    string lastName;
    string dateOfBirth;
    string phoneNumber;

    Student(const string& last, const string& dob, const string& phone)
        : lastName(last), dateOfBirth(dob), phoneNumber(phone) {}

    void displayInfo() const {
        cout << "Фамилия: " << lastName << "\n";
        cout << "Дата рождения: " << dateOfBirth << "\n";
        cout << "Телефон: " << phoneNumber << "\n";
    }
};

class StudentGroup {
private:
    vector<Student> students;

public:
    void addStudent(const string& lastName, const string& dateOfBirth, const string& phoneNumber) {
        students.emplace_back(lastName, dateOfBirth, phoneNumber);
    }

    void removeStudent(const string& lastName) {
        students.erase(remove_if(students.begin(), students.end(),
            [&](const Student& student) { return student.lastName == lastName; }),
            students.end());
    }

    Student* findStudentByLastName(const string& lastName) {
        auto it = find_if(students.begin(), students.end(),
            [&](const Student& student) { return student.lastName == lastName; });

        return (it != students.end()) ? &(*it) : nullptr;
    }

    void sortStudentsByLastName() {
        sort(students.begin(), students.end(),
            [](const Student& a, const Student& b) { return a.lastName < b.lastName; });
    }

    void displayAllStudents() const {
        if (students.empty()) {
            cout << "Группа пуста." << endl;
        }
        else {
            cout << "Список студентов:\n";
            for (const auto& student : students) {
                student.displayInfo();
                cout << "\n";
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    StudentGroup group;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить студента\n";
        cout << "2. Удалить студента\n";
        cout << "3. Найти студента по фамилии\n";
        cout << "4. Сортировать студентов по фамилии\n";
        cout << "5. Показать всех студентов\n";
        cout << "0. Выйти\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string lastName, dateOfBirth, phoneNumber;
            cout << "Введите фамилию: ";
            cin >> lastName;
            cout << "Введите дату рождения: ";
            cin >> dateOfBirth;
            cout << "Введите номер телефона: ";
            cin >> phoneNumber;
            group.addStudent(lastName, dateOfBirth, phoneNumber);
            break;
        }
        case 2: {
            string lastName;
            cout << "Введите фамилию студента, которого нужно удалить: ";
            cin >> lastName;
            group.removeStudent(lastName);
            break;
        }
        case 3: {
            string lastName;
            cout << "Введите фамилию студента, которого нужно найти: ";
            cin >> lastName;
            Student* foundStudent = group.findStudentByLastName(lastName);
            if (foundStudent) {
                cout << "Студент найден:\n";
                foundStudent->displayInfo();
            }
            else {
                cout << "Студент не найден.\n";
            }
            break;
        }
        case 4:
            group.sortStudentsByLastName();
            cout << "Студенты отсортированы по фамилии.\n";
            break;
        case 5:
            group.displayAllStudents();
            break;
        case 0:
            cout << "Программа завершена.\n";
            break;
        default:
            cout << "Неверный ввод. Повторите попытку.\n";
        }

    } while (choice != 0);

    return 0;
}

//3 задание

//#include <iostream>
//#include <stack>
//#include <fstream>
//#include <windows.h>
//using namespace std;
//
//class Wagon {
//public:
//    int wagonNumber;
//    Wagon(int number) : wagonNumber(number) {}
//};
//
//
//class SortingNode {
//private:
//    stack<Wagon> leftTrack;  // Стек для левого направления
//    stack<Wagon> rightTrack; // Стек для правого направления
//
//public:
//    
//    void addToLeftTrack(int wagonNumber) {
//        leftTrack.push(Wagon(wagonNumber));
//        cout << "Вагон " << wagonNumber << " добавлен в левое направление." << endl;
//    }
//
//    
//    void addToRightTrack(int wagonNumber) {
//        rightTrack.push(Wagon(wagonNumber));
//        cout << "Вагон " << wagonNumber << " добавлен в правое направление." << endl;
//    }
//
//   
//    void displayState() const {
//        cout << "Состояние левого направления: ";
//        displayTrack(leftTrack);
//
//        cout << "Состояние правого направления: ";
//        displayTrack(rightTrack);
//    }
//
//private:
//    
//    void displayTrack(const stack<Wagon>& track) const {
//        if (track.empty()) {
//            cout << "Пусто" << endl;
//        }
//        else {
//            stack<Wagon> temp = track;
//            while (!temp.empty()) {
//                cout << temp.top().wagonNumber << " ";
//                temp.pop();
//            }
//            cout << endl;
//        }
//    }
//};
//
//
//void loadFromInputFile(SortingNode& sortingNode, const string& filename) {
//   
//    string fullPath = "C:/Users/Asus/Desktop/OOPLab/Lab2/" + filename;
//
//
//    ifstream inputFile(fullPath);
//    if (!inputFile.is_open()) {
//        cerr << "Ошибка открытия файла." << endl;
//        return;
//    }
//
//    int wagonNumber;
//    char trackDirection;
//
//    while (inputFile >> wagonNumber >> trackDirection) {
//        if (trackDirection == 'L') {
//            sortingNode.addToLeftTrack(wagonNumber);
//        }
//        else if (trackDirection == 'R') {
//            sortingNode.addToRightTrack(wagonNumber);
//        }
//        else {
//            cerr << "Неверный формат файла." << endl;
//            break;
//        }
//    }
//
//    inputFile.close();
//}
//
//int main() {
//    SortingNode sortingNode;
//    setlocale(LC_ALL, "Russian");
//    SetConsoleOutputCP(1251);
//    SetConsoleCP(1251);
//
//    int choice;
//    do {
//        cout << "\nМеню:\n";
//        cout << "1. Добавить вагон в левое направление\n";
//        cout << "2. Добавить вагон в правое направление\n";
//        cout << "3. Загрузить вагоны из файла\n";
//        cout << "4. Вывести состояние сортировочного узла\n";
//        cout << "0. Выйти\n";
//        cout << "Выберите действие: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            int wagonNumber;
//            cout << "Введите номер вагона: ";
//            cin >> wagonNumber;
//            sortingNode.addToLeftTrack(wagonNumber);
//            break;
//        }
//        case 2: {
//            int wagonNumber;
//            cout << "Введите номер вагона: ";
//            cin >> wagonNumber;
//            sortingNode.addToRightTrack(wagonNumber);
//            break;
//        }
//        case 3: {
//            string filename;
//            cout << "Введите имя файла: ";
//            cin >> filename;
//            loadFromInputFile(sortingNode, filename);
//            break;
//        }
//        case 4:
//            sortingNode.displayState();
//            break;
//        case 0:
//            cout << "Программа завершена.\n";
//            break;
//        default:
//            cout << "Неверный ввод. Повторите попытку.\n";
//        }
//
//    } while (choice != 0);
//
//    return 0;
//}
