#include <iostream>
using namespace std;

int main() {
    int A[2] = { 2, 4 };

    cout << "정렬 전: " << A[0] << " " << A[1] << endl;

    int p[1];  // 왼쪽 배열 (원소 1개)
    int q[1];  // 오른쪽 배열 (원소 1개)

    p[0] = A[0]; //왼쪽,오른쪽 배열은 각각 A의 첫번째 두번째 원소
    q[0] = A[1]; 

    cout << "왼쪽 배열: " << p[0] << endl;
    cout << "오른쪽 배열: " << q[0] << endl;

    //  병합
    int i = 0, j = 0, k = 0;
    while (i < 1 && j < 1) {
        if (p[i] <= q[j])       //왼쪽 원소가 작거나 같으면 A에 왼쪽 원소를 넣고 k,i를 증가시킴
            A[k++] = p[i++];
        else
            A[k++] = q[j++];
    }
    while (i < 1) A[k++] = p[i++]; // 왼쪽 원소가 남으면 A에 넣기
    while (j < 1) A[k++] = q[j++]; // 오른쪽 원소가 남으면 A에 넣기


    cout << "병합 후: " << A[0] << " " << A[1] << endl;

    return 0;
}
