#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m, a[N];

inline void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    return;
}

inline void solve() {
    int k = 0;
    for (int i = 1; i <= n; i++) {
        k = (k + m - 1) % (n - i + 1);
        int v = a[k];
        for (int j = k; j < n - i; j++) {
            a[j] = a[j + 1];
        }
        cout << v << (i == n ? "\n" : " ");
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