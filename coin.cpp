#include <iostream>
using namespace std;

void change(int money) {
    int coins[4] = { 500, 100, 50, 10 };  // 동전 
    int count[4] = { 0 };                  // 각 동전 개수

    for (int i = 0; i < 4; i++) {
        count[i] = money / coins[i];   // 해당 동전 몇 개 필요한지 계산
        money %= coins[i];             // 남은 금액 
    }

    cout << "거스름돈:" << endl; // 결과 출력
    for (int i = 0; i < 4; i++) {
        if (count[i] > 0) {
            cout << coins[i] << "원: " << count[i] << "개" << endl;
        }
    }
}

int main() {
    int money;
    cout << "거슬러 줄 금액 입력: ";
    cin >> money;

    change(money);

    return 0;
}