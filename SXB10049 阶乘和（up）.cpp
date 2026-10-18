#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N], la, b[N], lb = 1;

inline void input() {
    cin >> n;
    return;
}

inline void mul(int m) {
    for (int i = 0; i < lb; i++) {
        b[i] *= m;
    }
    for (int i = 0; i < lb; i++) {
        b[i + 1] += b[i] / 10, b[i] %= 10;
    }
    while (b[lb]) {
        b[lb + 1] = b[lb] / 10, b[lb] %= 10, lb++;
    }
    return;
}

inline void add() {
    for (int i = 0; i < lb; i++) {
        a[i] += b[i];
        if (i) {
            a[i] += a[i - 1] / 10, a[i - 1] %= 10;
        }
    }
    if (la < lb) {
        la = lb;
    }
    while (a[la]) {
        a[la + 1] = a[la] / 10, a[la] %= 10, la++;
    }
    return;
}

inline void solve() {
    input();
    b[0] = 1;
    for (int i = 1; i <= n; i++) {
        mul(i), add();
    }
    while (la && !a[la]) {
        la--;
    }
    for (int i = la; i >= 0; i--) {
        cout << a[i];
    }
    cout << "\n";
    return;
}

signed main() {
    solve();
    return 0;
}