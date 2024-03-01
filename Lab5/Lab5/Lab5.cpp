//#include <iostream>
//using namespace std;
//
//class Int {
//private:
//    int value;
//
//public:
//    Int(int val = 0) : value(val) {}
//
//    Int operator+(const Int& other) const {
//        return checkOverflow(value, other.value, '+');
//    }
//
//    Int operator-(const Int& other) const {
//        return checkOverflow(value, other.value, '-');
//    }
//
//    Int operator*(const Int& other) const {
//        return checkOverflow(value, other.value, '*');
//    }
//
//    Int operator/(const Int& other) const {
//        if (other.value == 0) {
//            cerr << "Ошибка деление на 0!!!\n";
//            exit(EXIT_FAILURE);
//        }
//        return Int(value / other.value);
//    }
//
//    Int& operator++() {
//        return *this = checkOverflow(value, 1, '+');
//    }
//
//    Int operator++(int) {
//        Int temp = *this;
//        *this = checkOverflow(value, 1, '+');
//        return temp;
//    }
//
//    Int checkOverflow(int a, int b, char op) const {
//        long double result;
//        switch (op) {
//        case '+':
//            result = static_cast<long double>(a) + static_cast<long double>(b);
//            break;
//        case '-':
//            result = static_cast<long double>(a) - static_cast<long double>(b);
//            break;
//        case '*':
//            result = static_cast<long double>(a) * static_cast<long double>(b);
//            break;
//        default:
//            cerr << "Ошибка не верный оператор!!!\n";
//            exit(EXIT_FAILURE);
//        }
//
//        const int INT_MAX_VALUE = 2147483647;
//        const int INT_MIN_VALUE = -2147483648;
//
//        if ((result > INT_MAX_VALUE && b > 0) || (result < INT_MIN_VALUE && b < 0)) {
//            cerr << "Ошибка арифметическое переполнение!!!\n";
//            exit(EXIT_FAILURE);
//        }
//
//        return Int(static_cast<int>(result));
//    }
//    friend ostream& operator<<(ostream& os, const Int& integer);
//};
//
//ostream& operator<<(ostream& os, const Int& integer) {
//    os << integer.value;
//    return os;
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    Int a = 5;
//    Int b = 0;
//
//    Int c = a + b;
//    cout << "a + b = " << c << endl;
//
//    c = a - b;
//    cout << "a - b = " << c << endl;
//
//
//    c = a / b;
//    cout << "a / b = " << c << endl;
//
//    c = b / a;
//    cout << "b / a = " << c << endl;
//    return 0;
//}
//
//
//
//
// 2
//#include <iostream>
//using namespace std;
//
//class Fraction {
//private:
//    double chislo;
//
//public:
//    Fraction(double value = 0.0) : chislo(value) {}
//
//    Fraction operator+(const Fraction& other) const {
//        return Fraction(chislo + other.chislo);
//    }
//
//    Fraction operator-(const Fraction& other) const {
//        return Fraction(chislo - other.chislo);
//    }
//
//    Fraction operator*(const Fraction& other) const {
//        return Fraction(chislo * other.chislo);
//    }
//
//    Fraction operator/(const Fraction& other) const {
//        if (other.chislo == 0) {
//            cerr << "Ошибка: деление на ноль!\n";
//            exit(EXIT_FAILURE);
//        }
//        return Fraction(chislo / other.chislo);
//    }
//
//    Fraction& operator++() {
//        chislo++;
//        return *this;
//    }
//
//    Fraction operator++(int) {
//        Fraction temp = *this;
//        chislo++;
//        return temp;
//    }
//
//    void print() const {
//        cout << chislo;
//    }
//};
//
//int main() {
//    Fraction a(3.5);
//    Fraction b(2.5);
//
//    Fraction c = a + b / a;
//    cout << "a + b = ";
//    c.print();
//
//    cout << endl;
//
//    Fraction d = a * 2;
//    cout << "a * 2 = ";
//    d.print();
//
//    cout << endl;
//
//    Fraction e = ++a;
//    cout << "++a = ";
//    e.print();
//
//    return 0;
//}


// 3
// 
#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l = 0.0, double w = 0.0) : length(l), width(w) {}

    double rect_area(double l, double w) const {
        return l * w;
    }

    double rect_area(double side) const {
        return side * side;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Rectangle rectangle;

    double side;
    cout << "Введите размер фигуры: ";
    cin >> side;

    if (cin.peek() == '\n') {
  
        cout << "Площадь квадрата: " << rectangle.rect_area(side) << endl;
    }
    else {
     
        double side2;
        cin >> side2;
        cout << "Площадь прямоугольника: " << rectangle.rect_area(side, side2) << endl;
    }

    return 0;
}

