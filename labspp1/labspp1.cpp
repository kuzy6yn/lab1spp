#include <iostream>

using namespace std;

int main() {
    int num;

    // �������� �����
    cout << "Enter Number: ";
    cin >> num;

    // ��������� �������� ��� ������� �����
    for (int i = num; i >= 1; i--) {
        // ������ ������ ����� �������� �� �������
        for (int j = 1; j <= num - i; j++) {
            cout << " ";
        }
        // ������ ������
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        // ������ �����
        for (int j = 0; j < i - 1; j++) {
            cout << num - i;
        }
        cout << endl;
    }

    return 0;
}