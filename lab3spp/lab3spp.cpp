#include <iostream>

class IntegerStorage {
private:
    int data[10]; // Масив для зберігання цілих чисел довжиною 10 байт

public:
    // Конструктор за замовчуванням
    IntegerStorage() {
        // Ініціалізуємо всі елементи масиву значенням 0
        for (int i = 0; i < 10; ++i) {
            data[i] = 0;
        }
    }

    // Метод для встановлення значення певного елемента масиву
    void setElement(int index, int value) {
        if (index >= 0 && index < 10) {
            data[index] = value;
        }
        else {
            std::cerr << "Index out of range!" << std::endl;
        }
    }

    // Метод для отримання значення певного елемента масиву
    int getElement(int index) const {
        if (index >= 0 && index < 10) {
            return data[index];
        }
        else {
            std::cerr << "Index out of range!" << std::endl;
            return 0; // Повертаємо 0 у разі некоректного індексу
        }
    }

    // Перевантаження оператора "+" для додавання об'єктів класу
    IntegerStorage operator+(const IntegerStorage& other) const {
        IntegerStorage result;
        for (int i = 0; i < 10; ++i) {
            result.data[i] = this->data[i] + other.data[i];
        }
        return result;
    }

    // Перевантаження оператора "+" для додавання об'єкта класу та цілого числа
    IntegerStorage operator+(int value) const {
        IntegerStorage result;
        for (int i = 0; i < 10; ++i) {
            result.data[i] = this->data[i] + value;
        }
        return result;
    }

    // Перевантаження оператора "-" для віднімання об'єктів класу
    IntegerStorage operator-(const IntegerStorage& other) const {
        IntegerStorage result;
        for (int i = 0; i < 10; ++i) {
            result.data[i] = this->data[i] - other.data[i];
        }
        return result;
    }

    // Перевантаження оператора "-" для віднімання цілого числа від об'єкта класу
    IntegerStorage operator-(int value) const {
        IntegerStorage result;
        for (int i = 0; i < 10; ++i) {
            result.data[i] = this->data[i] - value;
        }
        return result;
    }

    // Перевантаження оператора "<<" для виводу об'єкта класу у потік
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

    IntegerStorage sum = a + b; // Додавання двох об'єктів класу
    std::cout << "Sum: " << sum << std::endl;

    IntegerStorage difference = a - b; // Віднімання одного об'єкта класу від іншого
    std::cout << "Difference: " << difference << std::endl;

    IntegerStorage c = a + 2; // Додавання цілого числа до об'єкта класу
    std::cout << "c: " << c << std::endl;

    return 0;
}
