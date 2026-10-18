#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, a[N], l;

inline void input() {
    cin >> n;
}

inline void solve() {
    a[0] = 1, l = 1;
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < l; j++) {
            c = a[j] * 2 + c, a[j] = c % 10, c /= 10;
        }
        while (c) {
            a[l] = c % 10, c /= 10, l++;
        }
    }
    for (int i = l - 1; i >= 0; i--) {
        cout << a[i];
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