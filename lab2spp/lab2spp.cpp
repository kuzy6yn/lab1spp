#include <iostream>
#include <cmath>
#include <Windows.h>

// Звичайна функція для знаходження різниці комплексних чисел та їх модуля
double differenceAndModulus(double c1, double d1, double c2, double d2, double& realPart, double& imaginaryPart, double* phase) {
    // Знаходимо різницю комплексних чисел
    realPart = c1 - c2;
    imaginaryPart = d1 - d2;

    // Знаходимо модуль отриманого комплексного числа
    double modulus = sqrt(realPart * realPart + imaginaryPart * imaginaryPart);

    // Обчислення фази (кутового відхилення) комплексного числа
    if (phase != nullptr) {
        *phase = atan2(imaginaryPart, realPart);
    }

    // Повертаємо модуль
    return modulus;
}

// Шаблонна функція для знаходження різниці комплексних чисел та їх модуля
template<typename T>
T differenceAndModulus(T c1, T d1, T c2, T d2, T& realPart, T& imaginaryPart, T* phase) {
    // Знаходимо різницю комплексних чисел
    realPart = c1 - c2;
    imaginaryPart = d1 - d2;

    // Знаходимо модуль отриманого комплексного числа
    T modulus = sqrt(realPart * realPart + imaginaryPart * imaginaryPart);

    // Обчислення фази (кутового відхилення) комплексного числа
    if (phase != nullptr) {
        *phase = atan2(imaginaryPart, realPart);
    }

    // Повертаємо модуль
    return modulus;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    double c1, d1, c2, d2;
    std::cout << "Введіть дійсну частину першого комплексного числа: ";
    std::cin >> c1;
    std::cout << "Введіть уявну частину першого комплексного числа: ";
    std::cin >> d1;
    std::cout << "Введіть дійсну частину другого комплексного числа: ";
    std::cin >> c2;
    std::cout << "Введіть уявну частину другого комплексного числа: ";
    std::cin >> d2;

    double realPart, imaginaryPart;
    double phase;

    // Виклик звичайної функції
    double modulus1 = differenceAndModulus(c1, d1, c2, d2, realPart, imaginaryPart, &phase);

    std::cout << "Різниця комплексних чисел: " << realPart << " + " << imaginaryPart << "i" << std::endl;
    std::cout << "Модуль отриманого комплексного числа: " << modulus1 << std::endl;
    std::cout << "Фаза отриманого комплексного числа: " << phase << std::endl;

    // Виклик шаблонної функції
    float c1f = static_cast<float>(c1);
    float d1f = static_cast<float>(d1);
    float c2f = static_cast<float>(c2);
    float d2f = static_cast<float>(d2);

    float realPartf, imaginaryPartf;
    float phasef;

    float modulus2 = differenceAndModulus(c1f, d1f, c2f, d2f, realPartf, imaginaryPartf, &phasef);

    std::cout << "Різниця комплексних чисел (з використанням шаблону): " << realPartf << " + " << imaginaryPartf << "i" << std::endl;
    std::cout << "Модуль отриманого комплексного числа (з використанням шаблону): " << modulus2 << std::endl;
    std::cout << "Фаза отриманого комплексного числа (з використанням шаблону): " << phasef << std::endl;

    return 0;
}