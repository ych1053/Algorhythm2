#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string name[100]; // 학생 이름저장
int score[100]; //학생 점수 저장
int idx[100]; // 정렬용 인덱스//실제 데이터는 그대로 두고, 정렬 순서만 관리


bool a(int a, int b) { // 점수 내림차순 비교 (상위 3명할떄 쓸거임)
    return score[a] > score[b];
}
bool b(int a, int b) { // 점수 오르ㅁ차순 비교 (중간학생)
    return score[a] < score[b];
}//idx는 학생의 번호(인덱스)만 담고 있는 배열,nth_element할때 비교함수를 사용하지 않으면 idx의 숫자 자체를 기준으로 정렬함

int main() {
    cout << "학생 수 입력: ";
    cin >> n;

    cout << "이름과 점수 입력:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> name[i] >> score[i];
        idx[i] = i;
    }


    partial_sort(idx, idx + 3, idx + n, a);    // 상위 3명 출력 (partial_sort)

    cout << "\n상위 " << 3 << "명:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << name[idx[i]] << " (" << score[idx[i]] << ")" << endl;
    }

    stable_sort(idx, idx + n);    //이름 기준 전체 정렬 (stable_sort)

    cout << "\n이름순 정렬 결과:" << endl;
    for (int i = 0; i < n; i++) {
        cout << name[idx[i]] << " (" << score[idx[i]] << ")" << endl;
    }

    nth_element(idx, idx + n / 2, idx + n, b);    // 중간 점수 학생 찾기 (nth_element)

    cout << "\n중간 점수 학생: "
        << name[idx[n / 2]] << " (" << score[idx[n / 2]] << ")" << endl;

    return 0;
}
