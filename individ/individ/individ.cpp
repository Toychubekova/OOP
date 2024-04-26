
//
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Person {
//private:
//    string name;
//    string registrationNumber;
//    string registrationDate;
//    string personalInfo;
//    string partnerRequirements;
//    string gender;
//    bool hasMet; // Флаг, указывающий, участвовал ли кандидат во встрече
//
//public:
//    Person(const string& n, const string& regNum, const string& regDate,
//        const string& pInfo, const string& pReq, const string& g)
//        : name(n), registrationNumber(regNum), registrationDate(regDate),
//        personalInfo(pInfo), partnerRequirements(pReq), gender(g), hasMet(false) {}
//
//    void display() const {
//        cout << "Name: " << name << endl;
//        cout << "Registration Number: " << registrationNumber << endl;
//        cout << "Registration Date: " << registrationDate << endl;
//        cout << "Personal Info: " << personalInfo << endl;
//        cout << "Partner Requirements: " << partnerRequirements << endl;
//        cout << "Gender: " << gender << endl;
//    }
//
//    string getPartnerRequirements() const {
//        return partnerRequirements;
//    }
//
//    string getGender() const {
//        return gender;
//    }
//
//    string getPersonalInfo() const {
//        return personalInfo;
//    }
//
//    bool hasMetBefore() const {
//        return hasMet;
//    }
//
//    void setMet(bool value) {
//        hasMet = value;
//    }
//};
//
//class MatchmakingAgency {
//private:
//    vector<Person> potentialMatches;
//    vector<Person> archive; // Для хранения архивированных кандидатов
//
//public:
//    void addPotentialMatch(const Person& person) {
//        potentialMatches.push_back(person);
//    }
//
//    void displayPotentialMatches() const {
//        for (const auto& person : potentialMatches) {
//            person.display();
//            cout << endl;
//        }
//    }
//
//    void deletePotentialMatch(int index) {
//        if (index >= 0 && index < potentialMatches.size()) {
//            potentialMatches.erase(potentialMatches.begin() + index);
//            cout << "Candidate successfully removed." << endl;
//        }
//        else {
//            cout << "Invalid index." << endl;
//        }
//    }
//
//    void prepareMeetings() {
//        bool meetingFound = false;
//        for (size_t i = 0; i < potentialMatches.size(); ++i) {
//            for (size_t j = i + 1; j < potentialMatches.size(); ++j) {
//                if (potentialMatches[i].getPartnerRequirements() == potentialMatches[j].getPersonalInfo() &&
//                    potentialMatches[i].getGender() != potentialMatches[j].getGender()) {
//                    cout << "Meeting prepared between:" << endl;
//                    potentialMatches[i].display();
//                    potentialMatches[j].display();
//                    cout << endl;
//                    meetingFound = true;
//
//                    // Помечаем кандидатов как участвующих во встрече
//                    potentialMatches[i].setMet(true);
//                    potentialMatches[j].setMet(true);
//                }
//            }
//        }
//        if (!meetingFound) {
//            cout << "No compatible matches found for a meeting." << endl;
//        }
//    }
//
//    void archiveMatch() {
//        for (auto it = potentialMatches.begin(); it != potentialMatches.end();) {
//            if (it->hasMetBefore()) {
//                archive.push_back(*it);
//                it = potentialMatches.erase(it);
//            }
//            else {
//                ++it;
//            }
//        }
//        cout << "Candidates who participated in meetings are archived." << endl;
//    }
//
//    void displayArchive() const {
//        for (const auto& person : archive) {
//            person.display();
//            cout << endl;
//        }
//    }
//};
//
//int main() {
//    MatchmakingAgency agency;
//
//    int choice;
//    do {
//        cout << "Menu:" << endl;
//        cout << "1. Add candidate" << endl;
//        cout << "2. Show all candidates" << endl;
//        cout << "3. Delete candidate" << endl;
//        cout << "4. Prepare meetings" << endl;
//        cout << "5. Archive candidates who participated in meetings" << endl;
//        cout << "6. Display archived candidates" << endl;
//        cout << "7. Exit" << endl;
//        cout << "Choose an action: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            string name, regNum, regDate, pInfo, pReq;
//            int genderChoice;
//            cout << "Enter name: ";
//            cin.ignore();
//            getline(cin, name);
//            cout << "Enter registration number: ";
//            cin >> regNum;
//            cout << "Enter registration date: ";
//            cin.ignore();
//            getline(cin, regDate);
//            cout << "Enter personal info: ";
//            getline(cin, pInfo);
//            cout << "Choose partner requirements:" << endl;
//            cout << "1. Caring" << endl;
//            cout << "2. Cute" << endl;
//            cout << "3. Tall" << endl;
//            cout << "4. With a sense of humor" << endl;
//            cout << "Enter number for partner requirements: ";
//            int reqChoice;
//            cin >> reqChoice;
//            switch (reqChoice) {
//            case 1:
//                pReq = "Caring";
//                break;
//            case 2:
//                pReq = "Cute";
//                break;
//            case 3:
//                pReq = "Tall";
//                break;
//            case 4:
//                pReq = "With a sense of humor";
//                break;
//            default:
//                cout << "Invalid choice." << endl;
//                continue;
//            }
//            cout << "Choose gender:" << endl;
//            cout << "1. Male" << endl;
//            cout << "2. Female" << endl;
//            cout << "Enter number for gender: ";
//            cin >> genderChoice;
//            string gender;
//            switch (genderChoice) {
//            case 1:
//                gender = "Male";
//                break;
//            case 2:
//                gender = "Female";
//                break;
//            default:
//                cout << "Invalid choice." << endl;
//                continue;
//            }
//            Person newCandidate(name, regNum, regDate, pInfo, pReq, gender);
//            agency.addPotentialMatch(newCandidate);
//            break;
//        }
//        case 2:
//            agency.displayPotentialMatches();
//            break;
//        case 3: {
//            int index;
//            cout << "Enter index of candidate to delete: ";
//            cin >> index;
//            agency.deletePotentialMatch(index);
//            break;
//        }
//        case 4:
//            agency.prepareMeetings();
//            break;
//        case 5:
//            agency.archiveMatch();
//            break;
//        case 6:
//            cout << "Archived candidates:" << endl;
//            agency.displayArchive();
//            break;
//        case 7:
//            cout << "Exiting the program." << endl;
//            break;
//        default:
//            cout << "Invalid choice" << endl;
//        }
//    } while (choice != 7);
//
//    return 0;
//}
//
//



#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Prisoner {
private:
    string name;
    string article;
    int sentence;
    string incarcerationDate;
    string hierarchy;
    string cell;
    string relatives;
    string personalityTraits;

public:
    Prisoner(string name, string article, int sentence, string incarcerationDate, string hierarchy, string cell, string relatives, string personalityTraits)
        : name(name), article(article), sentence(sentence), incarcerationDate(incarcerationDate), hierarchy(hierarchy), cell(cell), relatives(relatives), personalityTraits(personalityTraits) {}

    void displayInfo() const {
        cout << "Имя: " << name << endl;
        cout << "Преступление: " << article << endl;
        cout << "Срок: " << sentence << " года(лет)" << endl;
        cout << "Дата заключения: " << incarcerationDate << endl;
        cout << "Позиция в иерархии: " << hierarchy << endl;
        cout << "Камера: " << cell << endl;
        cout << "Родственники: " << relatives << endl;
        cout << "Характерные черты: " << personalityTraits << endl;
        cout << "-----------------------------------" << endl;
    }

    string getName() const { return name; }
    string getHierarchy() const { return hierarchy; }
    string getArticle() const { return article; }
};

class Prison {
private:
    vector
        <Prisoner> prisoners;

public:
    void addPrisoner(const Prisoner& prisoner) {
        prisoners.push_back(prisoner);
    }

    void displayAllPrisoners() const {
        for (const auto& prisoner : prisoners) {
            prisoner.displayInfo();
        }
    }

    void searchByAttribute(const string& attribute) const {
        for (const auto& prisoner : prisoners) {
            if (prisoner.getHierarchy() == attribute) {
                prisoner.displayInfo();
            }
        }
    }

    void generateCrimeStats() const {
        map<string, int> crimeCounts;
        for (const auto& prisoner : prisoners) {
            crimeCounts[prisoner.getArticle()]++;
        }

        cout << "\nСтатистика преступлений:\n";
        for (const auto& pair : crimeCounts) {
            cout << pair.first << ": " << pair.second << " заключенных(ых)\n";
        }
    }

    void searchByArbitraryAttribute() const {
        string attributeName, attributeValue;
        cin.ignore(); // очистка буфера ввода
        cout << "\nВведите название атрибута для поиска: ";
        getline(cin, attributeName);
        cout << "Введите значение атрибута: ";
        getline(cin, attributeValue);

        cout << "\nРезультаты поиска:\n";
        for (const auto& prisoner : prisoners) {
            if (attributeName == "Имя" && prisoner.getName() == attributeValue) {
                prisoner.displayInfo();
            }
            else if (attributeName == "Позиция в иерархии" && prisoner.getHierarchy() == attributeValue) {
                prisoner.displayInfo();
            }
            else if (attributeName == "Преступление" && prisoner.getArticle() == attributeValue) {
                prisoner.displayInfo();
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Prison prison;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Добавить заключенного\n";
        cout << "2. Показать всех заключенных\n";
        cout << "3. Поиск заключенных по позиции в иерархии\n";
        cout << "4. Генерировать статистику по преступлениям\n";
        cout << "5. Поиск заключенных по произвольному атрибуту\n";
        cout << "6. Выход\n";
        cout << "Выберите опцию: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string name, article, incarcerationDate, hierarchy, cell, relatives, personalityTraits;
            int sentence;
            cout << "\nВведите информацию о новом заключенном:\n";
            cout << "Имя: ";
            getline(cin, name);
            cout << "Преступление: ";
            getline(cin, article);
            cout << "Срок (в годах): ";
            cin >> sentence;
            cin.ignore();
            cout << "Дата заключения (ДД.ММ.ГГГГ): ";
            getline(cin, incarcerationDate);
            cout << "Позиция в иерархии: ";
            getline(cin, hierarchy);
            cout << "Камера: ";
            getline(cin, cell);
            cout << "Родственники: ";
            getline(cin, relatives);
            cout << "Характерные черты: ";
            getline(cin, personalityTraits);

            Prisoner newPrisoner(name, article, sentence, incarcerationDate, hierarchy, cell, relatives, personalityTraits);
            prison.addPrisoner(newPrisoner);
            break;
        }
        case 2: {
            cout << "\nИнформация о всех заключенных:\n";
            prison.displayAllPrisoners();
            break;
        }
        case 3: {
            string searchAttribute;
            cout << "\nВведите позицию в иерархии для поиска заключенных: ";
            getline(cin, searchAttribute);
            cout << "\nРезультаты поиска:\n";
            prison.searchByAttribute(searchAttribute);
            break;
        }
        case 4: {
            prison.generateCrimeStats();
            break;
        }
        case 5: {
            prison.searchByArbitraryAttribute();
            break;
        }
        case 6: {
            cout << "\nПрограмма завершена.\n";
            return 0;
        }
        default:
            cout << "Неверный выбор. Пожалуйста, выберите опцию из меню.\n";
        }
    }

    return 0;
}





