#include <iostream>
using namespace std;

void change(int money) {
    int coins[4] = { 500, 100, 50, 10 };  // ���� 
    int count[4] = { 0 };                  // �� ���� ����

    for (int i = 0; i < 4; i++) {
        count[i] = money / coins[i];   // �ش� ���� �� �� �ʿ����� ���
        money %= coins[i];             // ���� �ݾ� 
    }

    cout << "�Ž�����:" << endl; // ��� ���
    for (int i = 0; i < 4; i++) {
        if (count[i] > 0) {
            cout << coins[i] << "��: " << count[i] << "��" << endl;
        }
    }
}

int main() {
    int money;
    cout << "�Ž��� �� �ݾ� �Է�: ";
    cin >> money;

    change(money);

    return 0;
}