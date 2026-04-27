#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

int n, m;
int price[MAXN];
vector<int> G1[MAXN]; // 正向图
vector<int> G2[MAXN]; // 反向图

int minPrice[MAXN]; // 从1出发到各点的路径上最小买入价
int maxPrice[MAXN]; // 从n出发（在反向图上）到各点的路径上最大卖出价
bool inq[MAXN];

// SPFA求正向图最小编
void spfa_min() {
    queue<int> q;
    memset(inq, 0, sizeof(inq));
    for (int i = 1; i <= n; ++i)
        minPrice[i] = INF;
    minPrice[1] = price[1];
    q.push(1);
    inq[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : G1[u]) {
            int tmp = min(minPrice[u], price[v]);
            if (tmp < minPrice[v]) {
                minPrice[v] = tmp;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}

// SPFA求反向图最大价值
void spfa_max() {
    queue<int> q;
    memset(inq, 0, sizeof(inq));
    for (int i = 1; i <= n; ++i)
        maxPrice[i] = 0;
    maxPrice[n] = price[n];
    q.push(n);
    inq[n] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : G2[u]) {
            int tmp = max(maxPrice[u], price[v]);
            if (tmp > maxPrice[v]) {
                maxPrice[v] = tmp;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &price[i]);
    }
    for (int i = 0; i < m; ++i) {
        int u, v, z;
        scanf("%d %d %d", &u, &v, &z);
        G1[u].push_back(v);
        G2[v].push_back(u); // 反向边
        if (z == 2) {
            G1[v].push_back(u);
            G2[u].push_back(v);
        }
    }

    spfa_min();
    spfa_max();

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (minPrice[i] != INF && maxPrice[i] != 0) {
            ans = max(ans, maxPrice[i] - minPrice[i]);
        }
    }
    printf("%d\n", ans);
    return 0;
}