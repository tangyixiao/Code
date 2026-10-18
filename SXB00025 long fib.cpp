#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;
const int M = 2e2 + 5;

int n, f[N][M], l[N];

inline void add(int x, int y) {
    for (int i = 0; i < l[y]; i++) {
        f[x][i] += f[y][i];
    }
    if (l[y] > l[x]) {
        l[x] = l[y];
    }
    for (int i = 0; i < l[x]; i++) {
        if (f[x][i] >= 10) {
            f[x][i + 1] += f[x][i] / 10, f[x][i] %= 10;
        }
    }
    while (f[x][l[x]]) {
        f[x][l[x] + 1] = f[x][l[x]] / 10, f[x][l[x]] %= 10, l[x]++;
    }
    return;
}

inline void fib(int x) {
    if (l[x]) {
        return;
    }
    if (x < 3) {
        f[x][0] = x - 1, l[x] = 1;
        return;
    }
    fib(x - 1), fib(x - 2), add(x, x - 1), add(x, x - 2);
    return;
}

signed main() {
    cin >> n;
    fib(n);
    for (int i = l[n] - 1; i >= 0; i--) {
        cout << f[n][i];
    }
    cout << "\n";
    return 0;
}