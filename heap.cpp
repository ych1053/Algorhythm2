#include <iostream>
#include <vector>
using namespace std;

class MinHeap {//최소힙 클래스
private:
    vector<int> heap; // 힙 데이터를 저장할 벡터

public:
    // 원소 삽입
    void insert(int val) {
        heap.push_back(val);        // 새로운깞을 벡터끝에 삽입
        int i = heap.size() - 1;    // 현재 인덱스

        // 부모보다 값이 작으면 계속 위로 올림
        while (i > 0) {
            int parent = (i - 1) / 2; // 부모 인덱스
            if (heap[parent] > heap[i]) {
                swap(heap[parent], heap[i]);//부모보다 작으면 교환
                i = parent; // 부모로 이동
            }
            else break; // 부모가 더 작으면 멈춤
        }
    }

    // 최소값 삭제
    void deleteMin() {
        if (heap.empty()) {
            cout << "힙이 비어있습니다!" << endl;
            return;
        }

        heap[0] = heap.back(); // 마지막 값을 루트로 이동
        heap.pop_back();       // 마지막 값 제거

        int i = 0; // 루트부터 시작
        while (true) {
            int left = 2 * i + 1;//왼쪽자식
            int right = 2 * i + 2;//오른쪽자식
            int smallest = i;

            if (left < heap.size() && heap[left] < heap[smallest])
                smallest = left;
            if (right < heap.size() && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != i) {
                swap(heap[i], heap[smallest]);//자식과 교환
                i = smallest; //  계속 내려감
            }
            else break; // 더 내려갈 필요 없으면 종료
        }
    }

    // 힙 출력
    void printHeap() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    MinHeap heap;

    heap.insert(10);
    heap.insert(15);
    heap.insert(20);
    heap.insert(18);
    heap.insert(5);

    cout << "삽입 후 힙: ";
    heap.printHeap();

    heap.deleteMin();
    cout << "최소값 삭제 후 힙: ";
    heap.printHeap();

    heap.deleteMin();
    cout << "한 번 더 삭제 후 힙: ";
    heap.printHeap();

    return 0;
}
