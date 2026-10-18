#include <bits/stdc++.h>
using namespace std;

const int N = 5 + 5;

int a[N], x;

inline void input() {
    for (int i = 1; i <= 5; i++) {
        cin >> a[i];
    }
    cin >> x;
}

inline void solve() {
    cout << a[x] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
