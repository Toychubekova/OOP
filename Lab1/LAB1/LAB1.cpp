
// 1 задание
#include <iostream>
using namespace std;
double power(double n, int p = 2);

int main() {
    double base;
    int exponent;
    cout << "Enter the base of the number: ";
    cin >> base;
    cout << "Enter the exponent of the number (default 2): ";
    if (!(cin >> exponent)) {
        exponent = 2;
    }

    double result = power(base, exponent);
    cout << "Result: " << result << endl;
    return 0;
}


double power(double n, int p) {
    double result = 1.0;

    if (p > 2) {
        for (int i = 0; i < p; ++i) {
            result *= n;
        }
    }
    else {
        result = n * n; 
    }
    return result;
}

// 2 задание 

//#include <iostream>
//using namespace std;
//
//double power(double n, int p = 2) {
//    double result = 1.0;
//
//    for (int i = 0; i < p; ++i) {
//        result *= n;
//    }
//    return result;
//}
//
//double power(char n, int p = 2) {
//    double result = 1.0;
//
//    for (int i = 0; i < p; ++i) {
//        result *= static_cast<double>(n);
//    }
//    return result;
//}
//
//double power(int n, int p = 2) {
//    return power(static_cast<double>(n), p);
//}
//
//double power(long int n, int p = 2) {
//    return power(static_cast<double>(n), p);
//}
//
//double power(float n, int p = 2) {
//    return power(static_cast<double>(n), p);
//}
//
//int main() {
//    cout << "double: " << power(2.5) << endl;
//    cout << "char: " << power('A') << endl;
//    cout << "int: " << power(5) << endl;
//    cout << "long int: " << power(10L) << endl;
//    cout << "float: " << power(3.14f) << endl;
//    return 0;
//}

// 3 задание

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//struct Employee {
//    string Name;
//    int age;
//    string specialty;
//    double averageSalary;
//};
//
//int main() {
//    int N; 
//    cout << "Enter the number of plants: ";
//    cin >> N;
//
//    
//    vector<vector<Employee>> factories(N);
//
//    for (int i = 0; i < N; ++i) {
//        int M; 
//        cout << "Enter the number of employees at the plant " << i + 1 << ": ";
//        cin >> M;
//
//        for (int j = 0; j < M; ++j) {
//            Employee employee;
//            cout << "Enter the employee's name: ";
//            cin >> employee.Name;
//            cout << "Enter the employee's age: ";
//            cin >> employee.age;
//            cout << "Enter the employee's specialty: ";
//            cin >> employee.specialty;
//            cout << "Enter the employee's averge salary: ";
//            cin >> employee.averageSalary;
//
//            factories[i].push_back(employee); 
//        }
//    }
//
//
//    int numberOfSL = 0;
//    int numberOfTOK = 0;
//
//    for (const auto& factory : factories) {
//        for (const auto& employee : factory) {
//            if (employee.specialty == "locksmith") {
//                numberOfSL++;
//            }
//            else if (employee.specialty == "turner") {
//                numberOfTOK++;
//            }
//        }
//    }
//    
//    cout << "Number of locksmiths: " << numberOfSL << endl;
//    cout << "Number of turners: " << numberOfTOK << endl;
//
//    return 0;
//}
