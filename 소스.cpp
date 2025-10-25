#include <iostream>
#include <vector>

using namespace std;

int main() {
    int arr1[] = { 3, 9, 30, 40 };
    int arr2[] = { 1, 10, 20, 50 };

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    vector<int> arr3(size1 + size2);

    int i = 0, j = 0, k = 0;

    // 두 배열 병합
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }

    // arr1에 남은 원소 복사
    while (i < size1) {
        arr3[k++] = arr1[i++];
    }

    // arr2에 남은 원소 복사
    while (j < size2) {
        arr3[k++] = arr2[j++];
    }

    // 출력
    for (int idx = 0; idx < size1 + size2; ++idx) {
        cout << arr3[idx] << " ";
    }

    return 0;
}
