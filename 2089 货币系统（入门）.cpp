#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;
int n, m, a[N], f[N];

inline int rd() {
    char c = getchar();
    for (; c != 0 && c != -1; c = getchar()) {
        if (c == '/') {
            for (; c != 10; c = getchar()) {
            }
            continue;
        }
        if (c == 45 || (c >= 48 && c <= 57)) {
            break;
        }
    }
    int sg = 1;
    if (c == 45) {
        sg = -1, c = getchar();
    }
    int x = 0;
    while (c >= 48 && c <= 57) {
        x = x * 10 + c - 48, c = getchar();
    }
    return x * sg;
}

inline void input() {
    n = rd(), m = rd();
    for (int i = 1; i <= n; i++) {
        a[i] = rd();
    }
    f[0] = 1;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j <= m; j++) {
            f[j] += f[j - a[i]];
        }
    }
    cout << f[m] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
