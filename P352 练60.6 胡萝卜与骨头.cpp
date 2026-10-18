#include <bits/stdc++.h>
using namespace std;
const int N = 30 + 5;
int a[N], p, sz = 30;

inline void input() {
    for (int i = 0; i < 30; i++) {
        a[i] = i + 1;
    }
}

inline void solve() {
    p = 0;
    for (; sz > 15;) {
        p = (p + 8) % sz;
        for (int j = p; j + 1 < sz; j++) {
            a[j] = a[j + 1];
        }
        sz--;
    }
    for (int i = 0; i < sz; i++) {
        cout << a[i] << (i == sz - 1 ? "\n" : " ");
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}