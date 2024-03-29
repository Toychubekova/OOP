#include <iostream>
#include <string>

using namespace std;

const int LIMIT = 5;

class SafeArray {
private:
    int arr[LIMIT];
public:
    class Range : public exception {
    private:
        string msg;
    public:
        Range(const string& message) : msg(message) {}/* используется для обработки ошибок при выходе за пределы массива*/
        const string& getMessage() const {
            return msg;
        }
    };

    void putel(int n, int value) {
        if (n < 0 || n >= LIMIT) {
            // cout << "\nОшибочный индекс #";
             //exit(1);
            throw Range("Ошибочный индекс #" + to_string(n));
        }

        arr[n] = value;
    }

    int getel(int n) const {
        if (n < 0 || n >= LIMIT) {
            //cout << "\nОшибочный индекс #";
            //exit(1);
            throw Range("Ошибочный индекс #" + to_string(n));
        }

        return arr[n];
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    SafeArray arr;

    try {
        for (int i = 0; i < LIMIT; i++) {
            arr.putel(i, i * 10);
        }

        for (int i = 0; i < LIMIT + 1; i++) {
            cout << "Элемент #" << i << " = " << arr.getel(i) << endl;
        }
    }
    catch (const exception& e) {
        //cout << "Ошибка: " << e.getMessage() << endl;
        cout << "Ошибка: " << e.what() << endl;
    }


    return 0;
}


#include <iostream>
//#include <iomanip>
//#include <string>
//
//class Tatra;
//
//class Kamaz {
//private:
//    int speed;
//    std::string name;
//
//public:
//    Kamaz(int spd, const std::string& nm) : speed(spd), name(nm) {}
//
//    void display() const {
//        std::cout << std::setw(10) << name << ": " << std::setw(3) << speed << " км/ч";
//    }
//
//    friend int FrCreater(const Kamaz& kamaz, const Tatra& tatra);
//    friend int FrCreater(const Kamaz& kamaz, const Tatra& tatra);
//    friend class Tatra;
//};
//
//class Tatra {
//private:
//    int speed;
//    std::string name;
//
//public:
//    Tatra(int spd, const std::string& nm) : speed(spd), name(nm) {}
//
//    void display() const {
//        std::cout << std::setw(10) << name << ": " << std::setw(3) << speed << " км/ч";
//    }
//
//    friend int FrCreater(const Kamaz& kamaz, const Tatra& tatra);
//
//};
//
//class SpeedComparisonException : public std::exception {
//private:
//    std::string message;
//
//public:
//    SpeedComparisonException(const std::string& msg) : message(msg) {}
//
//    const char* what() const noexcept override {
//        return message.c_str();
//    }
//};
//
//int FrCreater(const Kamaz& kamaz, const Tatra& tatra) {
//    if (kamaz.speed > tatra.speed)
//        return 1;
//    else if (kamaz.speed < tatra.speed)
//        return -1;
//    else
//        throw SpeedComparisonException("Скорость КАМАЗа и Tatra одинакова.");
//}
//
//int main() {
//    setlocale(LC_ALL, "Ru");
//    Kamaz kamaz(120, "КАМАЗ");
//    Tatra tatra(110, "Tatra");
//
//    std::cout << std::setw(20) << "Участок трассы" << std::setw(20) << "Победитель" << std::endl;
//    std::cout << "-----------------------------------------" << std::endl;
//
//    std::cout << std::setw(20) << "Равнина: ";
//    try {
//        int resultPlain = FrCreater(kamaz, tatra);
//        if (resultPlain == 1)
//            std::cout << std::setw(20) << "КАМАЗ";
//        else if (resultPlain == -1)
//            std::cout << std::setw(20) << "Tatra";
//        else
//            std::cout << std::setw(20) << "Ничья";
//    }
//    catch (const SpeedComparisonException& e) {
//        std::cout << std::setw(20) << "Ошибка: " << e.what();
//    }
//    std::cout << std::endl;
//
//    kamaz.display();
//    tatra.display();
//
//    return 0;
//}