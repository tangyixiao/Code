#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, d, A[N], B[N], T[N], U[N];

inline void cl(int a[]) {
    for (int i = 0; i < d; i++) {
        a[i] = 0;
    }
}

inline void cp(int a[], int b[]) {
    for (int i = 0; i < d; i++) {
        a[i] = b[i];
    }
}

inline void ad(int a[], int b[]) {
    int c = 0;
    for (int i = 0; i < d; i++) {
        c += a[i] + b[i], a[i] = c % 10, c /= 10;
    }
}

inline void sb(int a[], int b[]) {
    int c = 0;
    for (int i = 0; i < d; i++) {
        c = a[i] - b[i] - c, a[i] = (c + 10) % 10, c = (c < 0);
    }
}

inline void ml(int a[], int m) {
    int c = 0;
    for (int i = 0; i < d; i++) {
        c += a[i] * m, a[i] = c % 10, c /= 10;
    }
}

inline void dv(int a[], int b) {
    int c = 0;
    for (int i = d - 1; i >= 0; i--) {
        c = c * 10 + a[i], a[i] = c / b, c %= b;
    }
}

inline bool nz(int a[]) {
    for (int i = 0; i < d; i++) {
        if (a[i]) {
            return true;
        }
    }
    return false;
}

inline void at(int a[], int x) {
    cl(T), T[d - 1] = 1, dv(T, x);
    for (int k = 0; nz(T); k++) {
        cp(U, T), dv(U, 2 * k + 1);
        if (k % 2 == 0) {
            ad(a, U);
        } else {
            sb(a, U);
        }
        dv(T, x * x);
    }
    return;
}

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    d = n + 25;
    cl(A), cl(B);
    at(A, 5), at(B, 239);
    ml(A, 16), ml(B, 4);
    sb(A, B);
    for (int i = 1; i <= n; i++) {
        if (i > 1 && (i - 1) % 10 == 0) {
            printf("\n");
        }
        printf("%d", A[d - 1 - i]);
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
