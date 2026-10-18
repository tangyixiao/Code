#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N], v[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i]) {
            continue;
        }
        int j = i, c = 0;
        for (; !v[j]; j = a[j]) {
            v[j] = 1, c++;
        }
        ans += c - 1;
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
