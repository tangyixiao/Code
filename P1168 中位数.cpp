#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 大根堆：存储较小的一半元素
    priority_queue<int> maxHeap;
    // 小根堆：存储较大的一半元素
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        // 插入元素
        if (maxHeap.empty() || x <= maxHeap.top()) {
            maxHeap.push(x);
        } else {
            minHeap.push(x);
        }

        // 调整两个堆的大小，保持大根堆比小根堆多1个或相等
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // 输出前奇数项的中位数
        if (i % 2 == 1) {
            cout << maxHeap.top() << "\n";
        }
    }

    return 0;
}