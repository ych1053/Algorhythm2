#include <iostream>
#include <vector>
using namespace std;

class MinHeap {//�ּ��� Ŭ����
private:
    vector<int> heap; // �� �����͸� ������ ����

public:
    // ���� ����
    void insert(int val) {
        heap.push_back(val);        // ���ο�� ���ͳ��� ����
        int i = heap.size() - 1;    // ���� �ε���

        // �θ𺸴� ���� ������ ��� ���� �ø�
        while (i > 0) {
            int parent = (i - 1) / 2; // �θ� �ε���
            if (heap[parent] > heap[i]) {
                swap(heap[parent], heap[i]);//�θ𺸴� ������ ��ȯ
                i = parent; // �θ�� �̵�
            }
            else break; // �θ� �� ������ ����
        }
    }

    // �ּҰ� ����
    void deleteMin() {
        if (heap.empty()) {
            cout << "���� ����ֽ��ϴ�!" << endl;
            return;
        }

        heap[0] = heap.back(); // ������ ���� ��Ʈ�� �̵�
        heap.pop_back();       // ������ �� ����

        int i = 0; // ��Ʈ���� ����
        while (true) {
            int left = 2 * i + 1;//�����ڽ�
            int right = 2 * i + 2;//�������ڽ�
            int smallest = i;

            if (left < heap.size() && heap[left] < heap[smallest])
                smallest = left;
            if (right < heap.size() && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != i) {
                swap(heap[i], heap[smallest]);//�ڽİ� ��ȯ
                i = smallest; //  ��� ������
            }
            else break; // �� ������ �ʿ� ������ ����
        }
    }

    // �� ���
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

    cout << "���� �� ��: ";
    heap.printHeap();

    heap.deleteMin();
    cout << "�ּҰ� ���� �� ��: ";
    heap.printHeap();

    heap.deleteMin();
    cout << "�� �� �� ���� �� ��: ";
    heap.printHeap();

    return 0;
}
