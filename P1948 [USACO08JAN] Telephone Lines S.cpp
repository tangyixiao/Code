#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1010;
const int MAXP = 10010;
const int INF = 0x3f3f3f3f;

struct Edge {
    int to, weight;
};

int n, p, k;
vector<Edge> graph[MAXN];
int dist[MAXN];

// 0-1 BFS求最短路，边权为0或1
bool check(int x) {
    // 初始化距离数组
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    // 双端队列
    deque<int> dq;
    dq.push_front(1);

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for (const Edge &e : graph[u]) {
            int v = e.to;
            int w = (e.weight > x) ? 1 : 0; // 边权转换

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0) {
                    dq.push_front(v); // 权值为0，从前面入队
                } else {
                    dq.push_back(v); // 权值为1，从后面入队
                }
            }
        }
    }

    return dist[n] <= k;
}

int main() {
    cin >> n >> p >> k;

    for (int i = 0; i < p; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
    }

    // 二分答案
    int left = 0, right = 1000000, ans = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (check(mid)) {
            ans = mid;
            right = mid - 1; // 尝试更小的花费
        } else {
            left = mid + 1; // 需要更大的花费
        }
    }

    cout << ans << endl;
    return 0;
}