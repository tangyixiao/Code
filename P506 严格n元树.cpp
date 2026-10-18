#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 5;

int n, d, i, j, k, m, t, b;
int g[N + 1][N];
int a[N], r[N];

void mul(int *x, int *y, int *z) {
    for (i = 0; i < N; i++) {
        r[i] = 0;
    }
    for (i = 0; i < N; i++) {
        if (x[i]) {
            for (j = 0; i + j < N; j++) {
                r[i + j] += x[i] * y[j];
            }
        }
    }
    for (i = 0; i < N - 1; i++) {
        r[i + 1] += r[i] / 10;
        r[i] %= 10;
    }
    r[N - 1] %= 10;
    for (i = 0; i < N; i++) {
        z[i] = r[i];
    }
}

int len(int *x) {
    for (t = N - 1; t > 0 && x[t] == 0; t--) {
    }
    return t + 1;
}

signed main() {
    cin >> n >> d;
    for (i = 0; i < N; i++) {
        g[0][i] = 0;
    }
    g[0][0] = 1;
    for (k = 1; k <= d; k++) {
        for (i = 0; i < N; i++) {
            a[i] = 0;
        }
        a[0] = 1;
        for (m = 1; m <= n; m++) {
            mul(g[k - 1], a, r);
            for (i = 0; i < N; i++) {
                a[i] = r[i];
            }
        }
        for (i = 0; i < N - 1 && a[i] == 9; i++) {
            a[i] = 0;
        }
        a[i]++;
        for (i = 0; i < N; i++) {
            g[k][i] = a[i];
        }
    }
    if (!d) {
        cout << 1 << "\n";
        return 0;
    }
    b = 0;
    for (i = 0; i < N; i++) {
        t = g[d][i] - g[d - 1][i] - b;
        if (t < 0) {
            t += 10;
            b = 1;
        } else {
            b = 0;
        }
        a[i] = t;
    }
    m = len(a);
    if (m > 2e2) {
        for (i = 2e2 - 1; i >= 0; i--) {
            cout << a[i];
        }
        cout << "\n";
        return 0;
    }
    for (i = m - 1; i >= 0; i--) {
        cout << a[i];
    }
    cout << "\n";
    return 0;
}