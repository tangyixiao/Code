#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int a[N], n;

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        cout << a[(i + 1) % n] << (i + 1 == n ? "\n" : " ");
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
