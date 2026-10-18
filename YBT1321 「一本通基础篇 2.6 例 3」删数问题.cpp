#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 5;
int s, q[N], hh, tt;
char a[N];

inline void input() {
    cin >> a >> s;
    return;
}

inline void solve() {
    for (int i = 0; a[i]; i++) {
        while (tt > hh && q[tt - 1] > a[i] - '0' && s > 0) {
            tt--, s--;
        }
        q[tt++] = a[i] - '0';
    }
    tt -= s;
    while (tt > hh && q[hh] == 0) {
        hh++;
    }
    for (int i = hh; i < tt; i++) {
        cout << q[i];
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}