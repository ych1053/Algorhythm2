#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string name[100]; // �л� �̸�����
int score[100]; //�л� ���� ����
int idx[100]; // ���Ŀ� �ε���//���� �����ʹ� �״�� �ΰ�, ���� ������ ����


bool a(int a, int b) { // ���� �������� �� (���� 3���ҋ� ������)
    return score[a] > score[b];
}
bool b(int a, int b) { // ���� ���������� �� (�߰��л�)
    return score[a] < score[b];
}//idx�� �л��� ��ȣ(�ε���)�� ��� �ִ� �迭,nth_element�Ҷ� ���Լ��� ������� ������ idx�� ���� ��ü�� �������� ������

int main() {
    cout << "�л� �� �Է�: ";
    cin >> n;

    cout << "�̸��� ���� �Է�:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> name[i] >> score[i];
        idx[i] = i;
    }


    partial_sort(idx, idx + 3, idx + n, a);    // ���� 3�� ��� (partial_sort)

    cout << "\n���� " << 3 << "��:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << name[idx[i]] << " (" << score[idx[i]] << ")" << endl;
    }

    stable_sort(idx, idx + n);    //�̸� ���� ��ü ���� (stable_sort)

    cout << "\n�̸��� ���� ���:" << endl;
    for (int i = 0; i < n; i++) {
        cout << name[idx[i]] << " (" << score[idx[i]] << ")" << endl;
    }

    nth_element(idx, idx + n / 2, idx + n, b);    // �߰� ���� �л� ã�� (nth_element)

    cout << "\n�߰� ���� �л�: "
        << name[idx[n / 2]] << " (" << score[idx[n / 2]] << ")" << endl;

    return 0;
}
