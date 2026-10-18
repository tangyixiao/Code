#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, m, c[N];

inline void input() {
    cin >> n >> m;
    for (int i = 0, x; i < m; i++) {
        cin >> x;
        c[x]++;
    }
}

inline void solve() {
    input();
    int f = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < c[i]; j++) {
            if (f) {
                cout << " " << i;
            } else {
                cout << i, f = 1;
            }
        }
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}