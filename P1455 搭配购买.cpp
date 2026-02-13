#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10010;
int fa[MAXN], c[MAXN], d[MAXN];
int group_c[MAXN], group_d[MAXN];
int dp[MAXN];
bool isRoot[MAXN];

int find(int x) {
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void unite(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy)
        fa[fy] = fx;
}

int main() {
    int n, m, w;
    cin >> n >> m >> w;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> d[i];
        fa[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        unite(u, v);
    }

    for (int i = 1; i <= n; ++i) {
        int tr = find(i);
        group_c[tr] += c[i];
        group_d[tr] += d[i];
        isRoot[tr] = true;
    }

    vector<int> prices, values;
    for (int i = 1; i <= n; ++i) {
        if (isRoot[i]) {
            prices.push_back(group_c[i]);
            values.push_back(group_d[i]);
        }
    }

    for (size_t i = 0; i < prices.size(); ++i) {
        for (int j = w; j >= prices[i]; --j) {
            dp[j] = max(dp[j], dp[j - prices[i]] + values[i]);
        }
    }
    cout << dp[w] << endl;
    return 0;
}