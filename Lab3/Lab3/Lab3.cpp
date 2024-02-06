
//1 задание
//#include <iostream>
//#include <ctime>
//#include <cstdlib>
//#include <iomanip>
//
//using namespace std;
//
//class Timer {
//private:
//    int seconds;
//
//public:
//    
//    Timer(int initialSeconds) : seconds(initialSeconds) {}
//
//    Timer(const string& timeString) {
//        parseTimeString(timeString);
//    }
//
//    Timer(int minutes, int seconds) : seconds(minutes * 60 + seconds) {}
//
//    void run() {
//        while (seconds > 0) {
//            displayTime();
//            sleep(1);  // Задержка на 1 секунду
//            --seconds;
//        }
//        cout << "\aTime's up! Ding ding ding!" << endl;  // Звонок
//    }
//
//private:
//   
//    void displayTime() const {
//        int minutes = seconds / 60;
//        int remainingSeconds = seconds % 60;
//        cout << setw(2) << setfill('0') << minutes << ":"
//            << setw(2) << setfill('0') << remainingSeconds << "\r" << flush;
//    }
//
//    
//    void parseTimeString(const string& timeString) {
//        size_t colonPos = timeString.find(':');
//        if (colonPos != string::npos) {
//            char* end;
//            long minutes = strtol(timeString.c_str(), &end, 10);
//            if (*end == ':' && end != timeString.c_str()) {
//                // Преобразование минут успешно, продолжаем с секундами
//                long seconds = strtol(end + 1, &end, 10);
//                if (*end == '\0') {
//                    // Преобразование секунд успешно, устанавливаем значение таймера
//                    this->seconds = minutes * 60 + seconds;
//                    return;
//                }
//            }
//        }
//
//        
//        cerr << "Invalid time string format. Use \"mm:ss\"." << endl;
//        exit(EXIT_FAILURE);
//    }
//
//    
//    void sleep(int seconds) const {
//        clock_t delay = seconds * CLOCKS_PER_SEC;
//        clock_t start = clock();
//        while ((clock() - start) < delay) {}
//    }
//};
//
//int main() {
//    // Примеры использования конструкторов
//    Timer timer1(180);  // Таймер на 3 минуты
//    Timer timer2("05:30");  // Таймер на 5 минут 30 секунд
//    Timer timer3(2, 30);  // Таймер на 2 минуты 30 секунд
//
//    // Запуск таймеров
//    cout << "Timer 1: ";
//    timer1.run();
//
//    cout << "Timer 2: ";
//    timer2.run();
//
//    cout << "Timer 3: ";
//    timer3.run();
//
//    return 0;
//}

// 2 задание
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Nomenclature {
//private:
//    string productName;
//    double wholesalePrice;
//    double retailMarkup;
//    int quantityInStock;
//
//public:
//    
//    Nomenclature() : productName(""), wholesalePrice(0.0), retailMarkup(0.0), quantityInStock(0) {}
//
//    
//    Nomenclature(const string& name, double wholesale, double markup, int quantity)
//        : productName(name), wholesalePrice(wholesale), retailMarkup(markup), quantityInStock(quantity) {}
//
//   
//    ~Nomenclature() {
//        
//    }
//
//    double calculateNetIncome(int quantitySold) const {
//        double retailPrice = calculateRetailPrice();
//        return quantitySold * (retailPrice - wholesalePrice);
//    }
//
//    
//    void displayProductInfo() const {
//        cout << "Название: " << productName << endl;
//        cout << "Оптовая цена: $" << wholesalePrice << endl;
//        cout << "Розничная наценка: " << retailMarkup << "%" << endl;
//        cout << "Количество на складе: " << quantityInStock << endl;
//        cout << "Розничная цена: $" << calculateRetailPrice() << endl;
//    }
//
//private:
//    
//    double calculateRetailPrice() const {
//        return wholesalePrice * (1 + retailMarkup / 100);
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//    
//    Nomenclature product1("Фотоаппарат", 800.0, 20.0, 50);
//    product1.displayProductInfo();
//
//    cout << "Чистый доход от продажи 10 единиц: $" << product1.calculateNetIncome(10) << endl;
//
//    return 0;
//}

// 3 задание
//#include <iostream>
//#include <string>
//#include <ctime>
//
//using namespace std;
//
//class Soft {
//private:
//    string programName;
//    string developer;
//    double occupiedSpace;
//    time_t licenseExpiration;
//
//public:
//    
//    Soft(const string& name, const string& dev, double space, time_t expiration)
//        : programName(name), developer(dev), occupiedSpace(space), licenseExpiration(expiration) {}
//
//    
//    ~Soft() {
//        cout << "Программа " << programName << " удалена." << endl;
//    }
//
//    
//    int daysUntilLicenseExpiration() const {
//        time_t currentTime;
//        time(&currentTime);
//
//        int secondsRemaining;
//        if (difftime(licenseExpiration, currentTime) > 0) {
//            secondsRemaining = static_cast<int>(difftime(licenseExpiration, currentTime));
//        }
//        else {
//            secondsRemaining = 0;
//        }
//
//        int daysRemaining = secondsRemaining / (60 * 60 * 24);
//
//        return daysRemaining;
//    }
//
//    void displaySoftwareInfo() const {
//        cout << "Название программы: " << programName << endl;
//        cout << "Разработчик: " << developer << endl;
//        cout << "Занимаемый объем: " << occupiedSpace << " MB" << endl;
//
//        char buffer[26];
//        ctime_s(buffer, sizeof(buffer), &licenseExpiration);
//        cout << "Дата завершения лицензии: " << buffer;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    time_t expirationTime;
//    time(&expirationTime);
//    expirationTime += 30 * 24 * 60 * 60;  // Лицензия на 30 дней от текущего момента
//
//    Soft software1("PyCharm", "Тойчубекова Айчурок", 160.5, expirationTime);
//
//
//    cout << "Информация о программном обеспечении:" << endl;
//    software1.displaySoftwareInfo();
//
//    int daysRemaining = software1.daysUntilLicenseExpiration();
//    cout << "Дней до завершения лицензии: " << daysRemaining << endl;
//
//    return 0;
//}
