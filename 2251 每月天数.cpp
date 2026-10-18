#include <bits/stdc++.h>
using namespace std;

const int N = 13;
int a, b, d[N];

inline void input() {
    cin >> a >> b;
    for (int i = 1; i < N; i++) {
        d[i] = 31;
    }
    d[4] = d[6] = d[9] = d[11] = 30;
    d[2] = 28;
    if (a % 400 == 0 || a % 4 == 0 && a % 100 != 0) {
        d[2] = 29;
    }
}

inline void solve() {
    cout << d[b] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}