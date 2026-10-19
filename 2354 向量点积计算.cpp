#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, a[N], b[N];

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
}

inline void solve() {
    input();
    long long s = 0;
    for (int i = 0; i < n; i++) {
        s += (long long)a[i] * b[i];
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