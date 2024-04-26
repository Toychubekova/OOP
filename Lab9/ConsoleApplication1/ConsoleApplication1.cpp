//#include <iostream>
//#include <string>
//
//using namespace std;
//
//const int LIMIT = 5;
//
//class SafeArray {
//private:
//    int arr[LIMIT];
//public:
//    class Range : public exception {
//    private:
//        string msg;
//    public:
//        Range(const string& message) : msg(message) {}/* используется для обработки ошибок при выходе за пределы массива*/
//        const string& getMessage() const {
//            return msg;
//        }
//    };
//
//    void putel(int n, int value) {
//        if (n < 0 || n >= LIMIT) {
//            throw Range("Ошибочный индекс #" + to_string(n));
//        }
//
//        arr[n] = value;
//    }
//
//    int getel(int n) const {
//        if (n < 0 || n >= LIMIT) {
//            throw Range("Ошибочный индекс #" + to_string(n));
//        }
//
//        return arr[n];
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "ru");
//
//    SafeArray arr;
//
//    try {
//        for (int i = 0; i < LIMIT; i++) {
//            arr.putel(i, i * 10);
//        }
//
//        for (int i = 0; i < LIMIT + 1; i++) {
//            cout << "Элемент #" << i << " = " << arr.getel(i) << endl;
//        }
//    }
//    catch (const exception& e) {
//        cout << "Ошибка: " << e.what() << endl;
//    }
//
//
//
//    return 0;
//}

//
//char a;
//try {
//    cin >> a;
//}
//catch (const std::exception& e) {
//    cout << "Ошибка: " << e.what() << endl;
//
//}


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

//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//
//class Gun {
//private:
//    static double p; // Вероятность попадания
//public:
//    static int shoot(int n) {
//        srand(static_cast<unsigned int>(time(0)));
//        for (int i = 0; i < n; ++i) {
//            if ((double)rand() / RAND_MAX < p) {
//                return 1; // Самолет сбит
//            }
//        }
//        return 0; // Самолет не сбит
//    }
//
//    static double estimateProbability(int n) {
//        return 1 - pow((1 - p), n);
//    }
//
//    static void setProbability(double probability) {
//        p = probability;
//    }
//};
//
//double Gun::p = 0.0; // Инициализация статического поля
//
//int main() {
//    Gun::setProbability(0.3); // Устанавливаем вероятность попадания
//
//    int n;
//    std::cout << "Введите количество выстрелов: ";
//    std::cin >> n;
//
//    int result = Gun::shoot(n);
//    std::cout << "Результат стрельбы: " << (result == 1 ? "Цель уничтожена" : "Цель не поражена") << std::endl;
//
//    double estimatedProbability = Gun::estimateProbability(n);
//    std::cout << "Оценочное значение вероятности поражения цели: " << estimatedProbability << std::endl;
//
//    return 0;
//}
#include <iostream>
#include <stdexcept>

class Parent {
private:
    static int staticField;
public:
    static int& getStaticField() {
        return staticField;
    }
};

int Parent::staticField = 10;

class Child : private Parent {
public:
    void displayStaticField() {
        try {
            int fieldValue = Parent::getStaticField(); // Доступ к приватному полю через метод родительского класса
            std::cout << "Value of staticField in Parent: " << fieldValue << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }
};

int main() {
    Child childObj;
    childObj.displayStaticField();

    return 0;
}

