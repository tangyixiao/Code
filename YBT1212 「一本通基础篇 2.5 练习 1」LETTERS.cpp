#include <bits/stdc++.h>
using namespace std;

const int N = 2e1 + 5;
const int A = 26 + 5;

char a[N][N];
int r, c, u[A], b[N][N], mx;

inline void input() {
    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        cin >> a[i] + 1;
    }
}

inline void dfs(int x, int y, int k) {
    if (k > mx) {
        mx = k;
    }
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    for (int i = 0; i < 4; ++i) {
        int p = x + dx[i], q = y + dy[i];
        if (p < 1 || p > r || q < 1 || q > c || b[p][q] || u[a[p][q] - 'A']) {
            continue;
        }
        b[p][q] = u[a[p][q] - 'A'] = 1;
        dfs(p, q, k + 1);
        b[p][q] = u[a[p][q] - 'A'] = 0;
    }
}

inline void solve() {
    b[1][1] = u[a[1][1] - 'A'] = 1;
    dfs(1, 1, 1);
    cout << mx << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
