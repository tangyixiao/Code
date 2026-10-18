#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, a[N], b[N], lb = 1, la;

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

inline void solve() {
    input();
    b[0] = 1;
    for (int i = 0; i < n; i++) {
        mul(9);
    }
    la = n + 1;
    for (int i = 0; i <= n; i++) {
        a[i] = 0;
    }
    a[n] = 1;
    for (int i = 0; i < la; i++) {
        b[i] = i < lb ? b[i] : 0;
    }
    for (int i = 0; i < la; i++) {
        a[i] -= b[i];
        if (a[i] < 0) {
            a[i] += 10, a[i + 1] -= 1;
        }
    }
    for (; la > 1 && !a[la - 1]; la--) {
    }
    for (int i = la - 1; i >= 0; i--) {
        cout << a[i];
    }
    cout << "\n";
    return;
}

signed main() {
    solve();
    return 0;
}