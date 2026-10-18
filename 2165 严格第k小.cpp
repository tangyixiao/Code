#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k, a[N], m;

inline void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[j] < a[i]) {
                swap(a[i], a[j]);
            }
        }
    }
    m = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i] != a[i - 1]) {
            a[++m] = a[i];
        }
    }
    cout << a[k] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}