//
//#include <iostream>
//using namespace std;
//
//// Базовый класс Array
//class Array {
//protected:
//    static const int MAX_SIZE = 100; // Максимальный размер массива
//    unsigned arr[MAX_SIZE]; // Массив
//    int size; // Количество элементов
//
//public:
//    // Конструктор инициализации
//    Array(int sz, unsigned initialValue = 0) : size(sz) {
//        for (int i = 0; i < size; ++i) {
//            arr[i] = initialValue;
//        }
//    }
//
//    // Виртуальная функция поэлементного сложения массивов
//    virtual void addArrays(const Array& other) {
//        int minSize = min(size, other.size);
//        for (int i = 0; i < minSize; ++i) {
//            arr[i] += other.arr[i];
//        }
//    }
//    virtual void addArrays( double a ) {
//        for (int i = 0; i < 2; ++i) {
//            arr[i] += a;
//        }
//    }
//
//    // Вывод массива
//    void printArray() const {
//        for (int i = 0; i < size; ++i) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//// Класс ArrayPlusOne, переопределяющий виртуальную функцию
//class ArrayPlusOne : public Array {
//public:
//    // Конструктор
//    ArrayPlusOne(int sz, unsigned initialValue = 0) : Array(sz, initialValue) {}
//
//    // Переопределение функции поэлементного сложения массивов
//    void addArrays(const Array& other)  {
//        Array::addArrays(other);
//        for (int i = 0; i < size; ++i) {
//            arr[i]++;
//        }
//    }
//
//    // Вывод массива
//    void printArrayplus()  {
//        for (int i = 0; i < size; ++i) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//// Класс ArrayMinusOne, переопределяющий виртуальную функцию
//class ArrayMinusOne : public Array {
//public:
//    // Конструктор
//    ArrayMinusOne(int sz, unsigned initialValue = 0) : Array(sz, initialValue) {}
//
//    // Переопределение функции поэлементного сложения массивов
//    void addArrays(const Array& other)  {
//        Array::addArrays(other);
//        for (int i = 0; i < size; ++i) {
//            arr[i]--;
//        }
//    }
//
//    // Вывод массива
//    void printArrayminus()  {
//        for (int i = 0; i < size; ++i) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//
//
//int main() {
//    setlocale(LC_ALL, "Ru");
//    // Пример использования
//
//    Array arr1(3, 60);
//    Array arr2(3, 40);
//    ArrayPlusOne arr3(3, 10);
//    ArrayMinusOne arr4(3, 20);
//
//    cout << "Вывод значении: " << endl;
//    cout << "Вывод arr1: ";
//    arr1.printArray();
//
//    cout << "Вывод arr2: ";
//    arr2.printArray();
//
//    cout << "Вывод arr3: ";
//    arr3.printArray();
//
//    cout << "Вывод arr4:  ";
//    arr4.printArray();
//    cout << "\n-------------------------------------------------";
//    cout << "\nВызов виртуальной функции поэлементного сложения" << endl;
//    cout << "-------------------------------------------------" << endl;
//    cout << "arr1 + arr2: ";
//    cout << "\n60  +  40:   ";
//    arr1.addArrays(arr2);
//    arr1.printArray();
//
//    cout << "arr2 + arr4: ";
//    cout << "\n40  +  20:   ";
//    arr2.addArrays(arr4);
//    arr2.printArray();
//
//
//
//    cout << "arr3 + arr2: ";
//    cout << "\n10  +  40 + 1:   ";
//    arr3.addArrays(arr2);
//    arr3.printArray();
//
//    cout << "arr4 + arr1: ";
//    cout << "\n20  +  60 - 1:   ";
//    arr4.addArrays(arr1);
//    arr4.printArray();
//
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//// Абстрактный базовый класс Figure
//class Figure {
//public:
//    // Виртуальные методы для вычисления площади и периметра
//    virtual double area() = 0;
//    virtual double perimeter() = 0;
//};
//
//// Производный класс Rectangle
//class Rectangle : public Figure {
//protected:
//    double length;
//    double width;
//
//public:
//    // Конструктор инициализации
//    Rectangle(double l, double w) : length(l), width(w) {}
//
//    // Реализация виртуальных методов
//    double area() {
//        return length * width;
//    }
//
//    double perimeter() {
//        return 2 * (length + width);
//    }
//};
//
//// Производный класс Circle
//class Circle : public Figure {
//protected:
//    double radius;
//
//public:
//    // Конструктор инициализации
//    Circle(double r) : radius(r) {}
//
//    // Реализация виртуальных методов
//    double area() {
//        return 3.14 * radius * radius;
//    }
//
//    double perimeter() {
//        return 2 * 3.14 * radius;
//    }
//};
//
//// Производный класс Trapezium
//class Trapezium : public Figure {
//protected:
//    double sideA;
//    double sideB;
//    double height;
//
//public:
//    // Конструктор инициализации
//    Trapezium(double a, double b, double h) : sideA(a), sideB(b), height(h) {}
//
//    // Реализация виртуальных методов
//    double area() {
//        return (sideA + sideB) * height / 2.0;
//    }
//
//    double perimeter() {
//        return sideA + sideB + 2 * height;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "Ru");
//    Rectangle rectangle(5, 3);
//    Circle circle(4);
//    Trapezium trapezium(3, 7, 4);
//
//    cout << "Результат производного класса Rectangle:" << endl;
//    cout << "Area: " << "5 * 3 = " << rectangle.area() << endl;
//    cout << "Area: " << rectangle.area() << endl;
//    cout << "\nPerimeter: " << "2 * (5 + 3) = " << rectangle.perimeter() << endl;
//    cout << "Perimeter: " << rectangle.perimeter() << endl;
//    cout << "----------------------------------------\n";
//
//    cout << "\nРезультат производного класса Circle:" << endl;
//    cout << "Area: " << "3.14 * 4 * 4 = " << circle.area() << endl;
//    cout << "Area: " << circle.area() << endl;
//    cout << "\nPerimeter: " << "2 * 3,14 * 4 = " << circle.perimeter() << endl;
//    cout << "Perimeter: " << circle.perimeter() << endl;
//    cout << "----------------------------------------\n";
//
//    cout << "\nРезультат производного класса Trapezium:" << endl;
//    cout << "Area: " << "(3 + 7) * 4 / 2.0 = " << trapezium.area() << endl;
//    cout << "Area: " << trapezium.area() << endl;
//    cout << "\nPerimeter: " << "3 + 7 + 2 * 4 = " << trapezium.perimeter() << endl;
//    cout << "Perimeter: " << trapezium.perimeter() << endl;
//
//    return 0;
//}

#include <iostream>
#include <iomanip>
using namespace std;

// Абстрактный базовый класс
class Currency {
public:
    // Виртуальная функция для конвертации в рубли
    virtual double toRubles(double amount, double exchangeRate) const = 0;

    // Виртуальная функция для отображения типа валюты
    virtual void display() const = 0;

};

// Производный класс Dollar
class Dollar : public Currency {
public:
    // Реализация функции конвертации в рубли
    double toRubles(double amount, double exchangeRate) const override {
        return amount * exchangeRate;
    }

    // Реализация функции отображения типа валюты
    void display() const override {
        cout << "Тип валюты: Dollar" << endl;
    }
};

// Производный класс Euro
class Euro : public Currency {
public:
    // Реализация функции конвертации в рубли
    double toRubles(double amount, double exchangeRate) const override {
        return amount * exchangeRate;
    }

    // Реализация функции отображения типа валюты
    void display() const override {
        cout << "Тип валюты: Euro" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Ru");


    // Создание объектов классов Dollar и Euro
    Dollar dollar;
    Euro euro;

    double amount, exchangeRate;

    cout << "Производный класс Dollar: " << endl;
    cout << "\nВведите сумму в долларах: ";
    cin >> amount;

    cout << "Введите текущий курс доллара к рублю: ";
    cin >> exchangeRate;

    // Отображение результата для долларов
    cout << "\nРезультат для Долларов:\n";
    dollar.display();
    cout << "Сумма в рублях: " << dollar.toRubles(amount, exchangeRate) << endl;
    cout << endl << "----------------------------------\n";

    cout << "Производный класс Euro: " << endl;
    cout << "\nВведите сумму в евро: ";
    cin >> amount;

    cout << "Введите текущий курс евро к рублю: ";
    cin >> exchangeRate;

    // Отображение результата для евро
    cout << "\nРезультат для Евро:\n";
    euro.display();
    cout << "Сумма в рублях: " << euro.toRubles(amount, exchangeRate) << endl;

    return 0;
}