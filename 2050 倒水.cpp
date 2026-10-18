#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int x, y, z, d[N][N];
queue<int> q;

inline void input() {
    cin >> x >> y >> z;
}

inline void solve() {
    memset(d, -1, sizeof(d));
    d[0][0] = 0, q.push(0);
    while (q.size()) {
        int u = q.front() / N, v = q.front() % N;
        q.pop();
        if (u == z || v == z) {
            break;
        }
        int a[6][2] = {{x, v}, {u, y}, {0, v}, {u, 0}, {u - min(u, y - v), v + min(u, y - v)}, {u + min(v, x - u), v - min(v, x - u)}};
        for (int i = 0; i < 6; ++i) {
            int p = a[i][0], r = a[i][1];
            if (d[p][r] != -1) {
                continue;
            }
            d[p][r] = d[u][v] + 1, q.push(p * N + r);
        }
    }
    int ans = -1;
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= y; ++j) {
            if ((i == z || j == z) && d[i][j] != -1) {
                ans = ans == -1 ? d[i][j] : min(ans, d[i][j]);
            }
        }
    }
    if (ans == -1) {
        cout << "No Solution!";
    } else {
        cout << ans;
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
