#include <iostream>

using namespace std;

int main() {
    int num;

    // Введення числа
    cout << "Enter Number: ";
    cin >> num;

    // Проводимо ітерацію для кожного рядка
    for (int i = num; i >= 1; i--) {
        // Додаємо пробіли перед зірочками та цифрами
        for (int j = 1; j <= num - i; j++) {
            cout << " ";
        }
        // Додаємо зірочки
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        // Додаємо цифри
        for (int j = 0; j < i - 1; j++) {
            cout << num - i;
        }
        cout << endl;
    }

    return 0;
}