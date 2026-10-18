#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, q[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        q[i] = i;
    }
}

inline void solve() {
    int h = 1, t = n;
    while (t - h > 0) {
        int x = q[h++];
        q[++t] = x;
        h++;
    }
    cout << q[h] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
