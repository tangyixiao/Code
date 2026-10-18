#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
const int M = 2e4 + 5;
int n, a[M], b[N], c;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (!b[a[i]]) {
            b[a[i]] = 1;
            ++c;
        }
    }
}

inline void solve() {
    int t = 0;
    for (int i = 1; i <= n; ++i) {
        if (b[a[i]]) {
            b[a[i]] = 0;
            cout << a[i] << (++t == c ? "\n" : " ");
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}