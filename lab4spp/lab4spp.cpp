#include <iostream>
#include <string>

using namespace std;

// ������� ���� "������"
class Person {
protected:
    int x, y; // ����������
    int age; // ³�
    string firstName; // ��'�
    string lastName; // �����

public:
    // �����������
    Person(int initialX, int initialY, int initialAge, const string& initialFirstName, const string& initialLastName)
        : x(initialX), y(initialY), age(initialAge), firstName(initialFirstName), lastName(initialLastName) {}

    // ����� ����������
    void move() {
        x++;
        y++;
    }

    // ����� ������ ���������� ��� ������
    void displayInfo() {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Age: " << age << endl;
        cout << "Coordinates: (" << x << ", " << y << ")" << endl;
    }
};

// ������� ���� "������"
class Man : public Person {
private:
    int height; // г��
    int weight; // ����

public:
    // �����������
    Man(int initialX, int initialY, int initialAge, const string& initialFirstName, const string& initialLastName, int initialHeight, int initialWeight)
        : Person(initialX, initialY, initialAge, initialFirstName, initialLastName), height(initialHeight), weight(initialWeight) {}

    // ����� ��
    void eat() {
        weight++;
    }

    // ����� ���
    void sleep() {
        cout << firstName << " " << lastName << " is sleeping Zzz..." << endl;
    }

    // �������������� ����� ����������
    void move() {
        // ������ �� ����� ���������� �� �������
        x += 2;
        y += 2;
    }

    // �������������� ����� ������ ����������
    void displayInfo() {
        Person::displayInfo();
        cout << "Height: " << height << " cm" << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

int main() {
    // ��������� ��'���� ������
    Person person1(0, 0, 49, "Yaroslav", "Kuzyshyn");
    cout << "Person 1 Info:" << endl;
    person1.displayInfo();
    person1.move(); // ����������
    cout << "After moving:" << endl;
    person1.displayInfo();

    // ��������� ��'���� �������
    Man man1(0, 0, 17, "Taras", "Kuzyshyn", 184, 80);
    cout << "\nMan 1 Info:" << endl;
    man1.displayInfo();
    man1.move(); // ���������� ������� (����������� �������������� �����)
    cout << "After moving:" << endl;
    man1.displayInfo();
    man1.eat(); // ���
    cout << "After eating:" << endl;
    man1.displayInfo();

    return 0;
}
