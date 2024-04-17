#include <iostream>
#include <string>

using namespace std;

// Базовий клас "Людина"
class Person {
protected:
    int x, y; // Координати
    int age; // Вік
    string firstName; // Ім'я
    string lastName; // Фамілія

public:
    // Конструктор
    Person(int initialX, int initialY, int initialAge, const string& initialFirstName, const string& initialLastName)
        : x(initialX), y(initialY), age(initialAge), firstName(initialFirstName), lastName(initialLastName) {}

    // Метод переміщення
    void move() {
        x++;
        y++;
    }

    // Метод виводу інформації про людину
    void displayInfo() {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Age: " << age << endl;
        cout << "Coordinates: (" << x << ", " << y << ")" << endl;
    }
};

// Дочірній клас "Чоловік"
class Man : public Person {
private:
    int height; // Ріст
    int weight; // Вага

public:
    // Конструктор
    Man(int initialX, int initialY, int initialAge, const string& initialFirstName, const string& initialLastName, int initialHeight, int initialWeight)
        : Person(initialX, initialY, initialAge, initialFirstName, initialLastName), height(initialHeight), weight(initialWeight) {}

    // Метод їжі
    void eat() {
        weight++;
    }

    // Метод сну
    void sleep() {
        cout << firstName << " " << lastName << " is sleeping Zzz..." << endl;
    }

    // Перевизначений метод переміщення
    void move() {
        // Додаємо до кожної координати дві одиниці
        x += 2;
        y += 2;
    }

    // Перевизначений метод виводу інформації
    void displayInfo() {
        Person::displayInfo();
        cout << "Height: " << height << " cm" << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

int main() {
    // Створення об'єкту людини
    Person person1(0, 0, 49, "Yaroslav", "Kuzyshyn");
    cout << "Person 1 Info:" << endl;
    person1.displayInfo();
    person1.move(); // Переміщення
    cout << "After moving:" << endl;
    person1.displayInfo();

    // Створення об'єкту чоловіка
    Man man1(0, 0, 17, "Taras", "Kuzyshyn", 184, 80);
    cout << "\nMan 1 Info:" << endl;
    man1.displayInfo();
    man1.move(); // Переміщення чоловіка (викликається перевизначений метод)
    cout << "After moving:" << endl;
    man1.displayInfo();
    man1.eat(); // Їжа
    cout << "After eating:" << endl;
    man1.displayInfo();

    return 0;
}
