#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int a[N], n;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n;) {
        int j = i;
        for (; j < n && a[j + 1] == a[i]; ++j) {}
        cout << a[i] << " " << j - i + 1 << "\n";
        i = j + 1;
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