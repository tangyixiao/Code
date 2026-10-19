#include <bits/stdc++.h>
using namespace std;

const int N = 5 + 5;

int a[N];

inline void input() {
    cin >> a[1] >> a[2] >> a[3];
}

inline void solve() {
    sort(a + 1, a + 4);
    if (a[1] * a[1] + a[2] * a[2] == a[3] * a[3]) {
        cout << a[3] * a[3] << "\n";
    } else {
        cout << a[2] * a[2] + a[3] * a[3] << "\n";
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
