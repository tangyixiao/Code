#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 50005;
vector<int> graph[MAXN];
int size[MAXN]; // 子树大小
int dp[MAXN];   // 以i为根时的距离和
int n;

// 第一次DFS：计算子树大小和初始距离
void dfs1(int u, int parent) {
    size[u] = 1; // 包括自己
    for (int v : graph[u]) {
        if (v == parent)
            continue;
        dfs1(v, u);
        size[u] += size[v];
        dp[1] += size[v]; // 根节点1的距离和
    }
}

// 第二次DFS：换根DP
void dfs2(int u, int parent) {
    for (int v : graph[u]) {
        if (v == parent)
            continue;
        // 核心换根公式
        dp[v] = dp[u] + n - 2 * size[v];
        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 第一次DFS，以1为根
    dfs1(1, 0);

    // 第二次DFS，换根计算所有点的dp值
    dfs2(1, 0);

    // 找到最小距离和对应的节点
    int minDist = dp[1], minNode = 1;
    for (int i = 2; i <= n; i++) {
        if (dp[i] < minDist || (dp[i] == minDist && i < minNode)) {
            minDist = dp[i];
            minNode = i;
        }
    }

    cout << minNode << " " << minDist << endl;

    return 0;
}