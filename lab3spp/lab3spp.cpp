#include <iostream>

class IntegerStorage {
private:
    int data[10]; // ����� ��� ��������� ����� ����� �������� 10 ����

public:
    // ����������� �� �������������
    IntegerStorage() {
        // ���������� �� �������� ������ ��������� 0
        for (int i = 0; i < 10; ++i) {
            data[i] = 0;
        }
    }

    // ����� ��� ������������ �������� ������� �������� ������
    void setElement(int index, int value) {
        if (index >= 0 && index < 10) {
            data[index] = value;
        }
        else {
            std::cerr << "Index out of range!" << std::endl;
        }
    }

    // ����� ��� ��������� �������� ������� �������� ������
    int getElement(int index) const {
        if (index >= 0 && index < 10) {
            return data[index];
        }
        else {
            std::cerr << "Index out of range!" << std::endl;
            return 0; // ��������� 0 � ��� ������������ �������
        }
    }

    // �������������� ��������� "+" ��� ��������� ��'���� �����
    IntegerStorage operator+(const IntegerStorage& other) const {
        IntegerStorage result;
        for (int i = 0; i < 10; ++i) {
            result.data[i] = this->data[i] + other.data[i];
        }
        return result;
    }

    // �������������� ��������� "+" ��� ��������� ��'���� ����� �� ������ �����
    IntegerStorage operator+(int value) const {
        IntegerStorage result;
        for (int i = 0; i < 10; ++i) {
            result.data[i] = this->data[i] + value;
        }
        return result;
    }

    // �������������� ��������� "-" ��� �������� ��'���� �����
    IntegerStorage operator-(const IntegerStorage& other) const {
        IntegerStorage result;
        for (int i = 0; i < 10; ++i) {
            result.data[i] = this->data[i] - other.data[i];
        }
        return result;
    }

    // �������������� ��������� "-" ��� �������� ������ ����� �� ��'���� �����
    IntegerStorage operator-(int value) const {
        IntegerStorage result;
        for (int i = 0; i < 10; ++i) {
            result.data[i] = this->data[i] - value;
        }
        return result;
    }

    // �������������� ��������� "<<" ��� ������ ��'���� ����� � ����
    friend std::ostream& operator<<(std::ostream& os, const IntegerStorage& storage) {
        for (int i = 0; i < 10; ++i) {
            os << storage.data[i] << " ";
        }
        return os;
    }
};

int main() {
    IntegerStorage a, b;
    a.setElement(0, 5);
    a.setElement(1, 10);
    b.setElement(0, 3);
    b.setElement(1, 7);

    IntegerStorage sum = a + b; // ��������� ���� ��'���� �����
    std::cout << "Sum: " << sum << std::endl;

    IntegerStorage difference = a - b; // ³������� ������ ��'���� ����� �� ������
    std::cout << "Difference: " << difference << std::endl;

    IntegerStorage c = a + 2; // ��������� ������ ����� �� ��'���� �����
    std::cout << "c: " << c << std::endl;

    return 0;
}
