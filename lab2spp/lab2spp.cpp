#include <iostream>
#include <cmath>
#include <Windows.h>

// �������� ������� ��� ����������� ������ ����������� ����� �� �� ������
double differenceAndModulus(double c1, double d1, double c2, double d2, double& realPart, double& imaginaryPart, double* phase) {
    // ��������� ������ ����������� �����
    realPart = c1 - c2;
    imaginaryPart = d1 - d2;

    // ��������� ������ ���������� ������������ �����
    double modulus = sqrt(realPart * realPart + imaginaryPart * imaginaryPart);

    // ���������� ���� (�������� ���������) ������������ �����
    if (phase != nullptr) {
        *phase = atan2(imaginaryPart, realPart);
    }

    // ��������� ������
    return modulus;
}

// �������� ������� ��� ����������� ������ ����������� ����� �� �� ������
template<typename T>
T differenceAndModulus(T c1, T d1, T c2, T d2, T& realPart, T& imaginaryPart, T* phase) {
    // ��������� ������ ����������� �����
    realPart = c1 - c2;
    imaginaryPart = d1 - d2;

    // ��������� ������ ���������� ������������ �����
    T modulus = sqrt(realPart * realPart + imaginaryPart * imaginaryPart);

    // ���������� ���� (�������� ���������) ������������ �����
    if (phase != nullptr) {
        *phase = atan2(imaginaryPart, realPart);
    }

    // ��������� ������
    return modulus;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    double c1, d1, c2, d2;
    std::cout << "������ ����� ������� ������� ������������ �����: ";
    std::cin >> c1;
    std::cout << "������ ����� ������� ������� ������������ �����: ";
    std::cin >> d1;
    std::cout << "������ ����� ������� ������� ������������ �����: ";
    std::cin >> c2;
    std::cout << "������ ����� ������� ������� ������������ �����: ";
    std::cin >> d2;

    double realPart, imaginaryPart;
    double phase;

    // ������ �������� �������
    double modulus1 = differenceAndModulus(c1, d1, c2, d2, realPart, imaginaryPart, &phase);

    std::cout << "г����� ����������� �����: " << realPart << " + " << imaginaryPart << "i" << std::endl;
    std::cout << "������ ���������� ������������ �����: " << modulus1 << std::endl;
    std::cout << "���� ���������� ������������ �����: " << phase << std::endl;

    // ������ �������� �������
    float c1f = static_cast<float>(c1);
    float d1f = static_cast<float>(d1);
    float c2f = static_cast<float>(c2);
    float d2f = static_cast<float>(d2);

    float realPartf, imaginaryPartf;
    float phasef;

    float modulus2 = differenceAndModulus(c1f, d1f, c2f, d2f, realPartf, imaginaryPartf, &phasef);

    std::cout << "г����� ����������� ����� (� ������������� �������): " << realPartf << " + " << imaginaryPartf << "i" << std::endl;
    std::cout << "������ ���������� ������������ ����� (� ������������� �������): " << modulus2 << std::endl;
    std::cout << "���� ���������� ������������ ����� (� ������������� �������): " << phasef << std::endl;

    return 0;
}