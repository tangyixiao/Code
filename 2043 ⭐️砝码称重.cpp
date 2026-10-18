#include <bits/stdc++.h>
using namespace std;

const int N = 2e1 + 5;

int n;
long long a[N], v[1 << 20];

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    for (int i = 1; i < (1 << n); i++) {
        v[i] = v[i ^ (i & -i)] + a[__builtin_ctz(i)];
    }
    sort(v + 1, v + (1 << n));
    for (int i = 1; i < (1 << n); i++) {
        if (v[i] != v[i - 1]) {
            cout << v[i] << "\n";
        }
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
