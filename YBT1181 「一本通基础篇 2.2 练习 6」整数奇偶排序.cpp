#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int a[N], b[N], x, y, c, d;

inline void input() {
    return;
}

inline void solve() {
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x & 1) {
            a[c++] = x;
        } else {
            b[d++] = x;
        }
    }
    sort(a, a + c, greater<int>());
    sort(b, b + d);
    for (int i = 0, j = 0; i < N; i++) {
        cout << (i < c ? a[i] : b[j++]) << " \n"[i == N - 1];
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}