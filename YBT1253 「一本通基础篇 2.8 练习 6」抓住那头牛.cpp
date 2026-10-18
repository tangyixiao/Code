#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k, d[N];

inline void input() {
    cin >> n >> k;
    return;
}

inline void solve() {
    memset(d, -1, sizeof(int) * (N));
    queue<int> q;
    d[n] = 0, q.push(n);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == k) {
            break;
        }
        int y[3] = {x - 1, x + 1, x * 2};
        for (int i = 0; i < 3; ++i) {
            if (y[i] < 0 || y[i] >= N || d[y[i]] > -1) {
                continue;
            }
            d[y[i]] = d[x] + 1, q.push(y[i]);
        }
    }
    cout << d[k] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
