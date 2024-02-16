#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Tatra;

class Kamaz {
private:
    string name;
    double speed;

public:
    Kamaz(const string& name, double speed) : name(name), speed(speed) {}

    friend int FrCreater(const Kamaz& kamaz, const Tatra& tatra);

    void display() const {
        cout << "Камаз " << name << ", скорость: " << speed << " км/ч" << endl;
    }
};

class Tatra {
private:
    string name;
    double speed;

public:
    Tatra(const string& name, double speed) : name(name), speed(speed) {}

    friend int FrCreater(const Kamaz& kamaz, const Tatra& tatra);

    void display() const {
        cout << "Tatra " << name << ", скорость: " << speed << " км/ч" << endl;
    }

    friend class Kamaz;
};

int FrCreater(const Kamaz& kamaz, const Tatra& tatra) {
    if (kamaz.speed > tatra.speed)
        return 1;
    else if (kamaz.speed == tatra.speed)
        return 0;
    else
        return -1;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    
    Kamaz kamaz("Мастер", rand() % 100 + 100); // Скорость от 100 до 200 км/ч
    Tatra tatra("Phoenix", rand() % 80 + 80); // Скорость от 80 до 160 км/ч

    kamaz.display();
    tatra.display();

    int result = FrCreater(kamaz, tatra);

    if (result == 1)
        cout << "Камаз быстрее Tatra на участке трассы" << endl;
    else if (result == 0)
        cout << "Скорости Kamaz и Tatra равны на участке трассы" << endl;
    else
        cout << "Tatra быстрее Kamaz на участке трассы" << endl;

    return 0;
}
