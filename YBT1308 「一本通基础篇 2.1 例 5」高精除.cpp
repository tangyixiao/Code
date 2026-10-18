#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 5;

int a[N], b[N], q[N], r[N], c[N];

void mul(int d) {
    int t = 0;
    for (int i = 0; i < N; i++) {
        t += b[i] * d;
        c[i] = t % 10;
        t /= 10;
    }
}

int cmp() {
    for (int i = N - 1; i >= 0; i--) {
        if (c[i] != r[i]) {
            return c[i] > r[i] ? 1 : -1;
        }
    }
    return 0;
}

void sub() {
    int t = 0;
    for (int i = 0; i < N; i++) {
        int v = r[i] - c[i] - t;
        r[i] = (v + 10) % 10;
        t = v < 0;
    }
}

signed main() {
    char sa[N], sb[N];
    cin.getline(sa, N);
    cin.getline(sb, N);
    int na = strlen(sa), nb = strlen(sb);
    if (sa[na - 1] == '\r') {
        na--;
    }
    if (sb[nb - 1] == '\r') {
        nb--;
    }
    for (int i = 0; i < na; i++) {
        a[i] = sa[na - 1 - i] - '0';
    }
    for (int i = 0; i < nb; i++) {
        b[i] = sb[nb - 1 - i] - '0';
    }
    for (int i = na - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 1; j--) {
            r[j] = r[j - 1];
        }
        r[0] = a[i];
        int d = 0;
        for (; d < 9; d++) {
            mul(d + 1);
            if (cmp() > 0) {
                break;
            }
        }
        q[i] = d;
        mul(d);
        sub();
    }
    int p = na;
    while (p > 1 && q[p - 1] == 0) {
        p--;
    }
    for (int i = p - 1; i >= 0; i--) {
        cout << q[i];
    }
    cout << "\n";
    int k = N;
    while (k > 1 && r[k - 1] == 0) {
        k--;
    }
    for (int i = k - 1; i >= 0; i--) {
        cout << r[i];
    }
    cout << "\n";
    return 0;
}
