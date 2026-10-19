#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], n;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i], b[i] = i;
    }
}

inline void solve() {
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (a[b[j]] > a[b[i]]) {
                swap(b[i], b[j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        a[b[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << (i == n ? "\n" : " ");
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}