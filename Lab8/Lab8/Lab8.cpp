//#include <iostream>

//template<typename T>
//class ArrayUtility {
//public:
//    static T findMax(T arr[], int size) {
//        T max = arr[0];
//        for (int i = 1; i < size; ++i) {
//            if (arr[i] > max) {
//                max = arr[i];
//            }
//        }
//        return max;
//    }
//
//    static void sortArray(T arr[], int size) {
//        for (int i = 0; i < size - 1; ++i) {
//            for (int j = 0; j < size - i - 1; ++j) {
//                if (arr[j] > arr[j + 1]) {
//                    T temp = arr[j];
//                    arr[j] = arr[j + 1];
//                    arr[j + 1] = temp;
//                }
//            }
//        }
//    }
//};
//
//int main() {
//    int intArr[] = { 3, 7, 1, 9, 5 };
//    double doubleArr[] = { 3.5, 7.2, 1.9, 9.6, 5.3 };
//
//    int intSize = sizeof(intArr) / sizeof(int);
//    int doubleSize = sizeof(doubleArr) / sizeof(double);
//
//    std::cout << "Max of intArr: " << ArrayUtility<int>::findMax(intArr, intSize) << std::endl;
//    ArrayUtility<int>::sortArray(intArr, intSize);
//    std::cout << "Sorted intArr: ";
//    for (int i = 0; i < intSize; ++i) {
//        std::cout << intArr[i] << " ";
//    }
//    std::cout << std::endl;
//
//    std::cout << "Max of doubleArr: " << ArrayUtility<double>::findMax(doubleArr, doubleSize) << std::endl;
//    ArrayUtility<double>::sortArray(doubleArr, doubleSize);
//    std::cout << "Sorted doubleArr: ";
//    for (int i = 0; i < doubleSize; ++i) {
//        std::cout << doubleArr[i] << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}*/


//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//
//template<typename T, int size>
//class ArraySum {
//private:
//    T array1[size];
//    T array2[size];
//
//public:
//    ArraySum() {
//        // Заполнение массивов случайными числами
//        srand(time(nullptr));
//        for (int i = 0; i < size; ++i) {
//            array1[i] = rand() % 100; // Пример генерации случайного числа от 0 до 99
//            array2[i] = rand() % 100;
//        }
//    }
//
//    T sum() const {
//        T totalSum = 0;
//        for (int i = 0; i < size; ++i) {
//            totalSum += array1[i] + array2[i];
//        }
//        return totalSum;
//    }
//};
//
//int main() {
//    // Использование шаблона класса ArraySum для различных типов данных и размеров массивов
//    ArraySum<int, 5> intArraySum;
//    std::cout << "Sum of integer arrays: " << intArraySum.sum() << std::endl;
//
//    ArraySum<double, 3> doubleArraySum;
//    std::cout << "Sum of double arrays: " << doubleArraySum.sum() << std::endl;
//
//    return 0;
//}

// Шаблон класса "стек"
#include <iostream>
#include <stack>
#include <string>

// Определение структуры Employee
struct Employee {
    std::string Name;
    int age;
    std::string specialty;
    double averageSalary;
};

// Шаблон класса "стек"
template <typename T>
class Stack {
private:
    std::stack<T> data;
public:
    void push(const T& item) {
        data.push(item);
    }

    // Метод для поиска максимального элемента в числовом массиве
    template <typename U>
    U maxElement(U arr[], int size) {
        U max = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    T pop() {
        T top = data.top();
        data.pop();
        return top;
    }

    bool isEmpty() const {
        return data.empty();
    }
};

int main() {
    // Создаем стек для хранения информации о работниках
    Stack<Employee> workersStack;

    // Вводим информацию о работниках завода
    // Пример ввода для тестирования

    workersStack.push({ "Smith", 35, "turner", 2500 });
    workersStack.push({ "Johnson", 28, "turner", 2200 });
    workersStack.push({ "Williams", 40, "locksmith", 2800 });
    workersStack.push({ "Brown", 32, "locksmith", 2600 });

    // Создаем массив чисел для тестирования
    double doubleArr[] = { 3.5, 1.2, 6.7, 2.9, 8.1 };

    // Вызываем метод maxElement для класса Stack с числовым массивом
    std::cout << "Max element of doubleArr: " << workersStack.maxElement(doubleArr, 5) << std::endl;

    // Подсчитываем количество слесарей и токарей
    int locksmithsCount = 0;
    int turnersCount = 0;

    Stack<Employee> tempStack; // Временный стек для обработки данных

    while (!workersStack.isEmpty()) {
        Employee worker = workersStack.pop();
        tempStack.push(worker); // Возвращаем работника обратно в стек

        if (worker.specialty == "locksmith") {
            locksmithsCount++;
        }
        else if (worker.specialty == "turner") {
            turnersCount++;
        }
    }

    // Выводим количество слесарей и токарей
    std::cout << "Number of locksmiths: " << locksmithsCount << std::endl;
    std::cout << "Number of turners: " << turnersCount << std::endl;

    return 0;
}
