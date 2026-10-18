#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, a[N][N];

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

inline void solve() {
    input();
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i][i];
    }
    cout << s << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}