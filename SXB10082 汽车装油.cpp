#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int M = 2e3 + 5;
int n, m[N], w[N], s[M];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> m[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    for (int i = 1; i <= 2 * n; ++i) {
        s[i] = s[i - 1] + m[(i - 1) % n + 1] - w[(i - 1) % n + 1];
    }
}

inline void solve() {
    int c = 0;
    for (int i = 1; i <= n; ++i) {
        int mn = 0;
        for (int j = i; j < i + n; ++j) {
            mn = min(mn, s[j] - s[i - 1]);
        }
        if (!mn) {
            ++c;
            cout << i << (c == n ? "\n" : " ");
        }
    }
    if (!c) {
        cout << "No Result!\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}