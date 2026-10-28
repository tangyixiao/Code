#include <bits/stdc++.h>
using namespace std;
const int MOD = 100003;
const int N = 64;
int n, m, sz, st, i, j, k, e;
int A[N][N], B[N][N], C[N][N], R[N][N], T[N][N];
void mul() {
    for (i = 0; i < sz; i++) {
        for (j = 0; j < sz; j++) {
            C[i][j] = 0;
        }
    }
    for (i = 0; i < sz; i++) {
        for (k = 0; k < sz; k++) {
            if (!A[i][k]) {
                continue;
            }
            for (j = 0; j < sz; j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
}
void dfs(int r, int cur, int nxt) {
    if (r == n) {
        T[st][nxt]++;
        return;
    }
    if (cur >> r & 1) {
        dfs(r + 1, cur, nxt);
        return;
    }
    if (r + 1 < n && !(cur >> (r + 1) & 1)) {
        dfs(r + 2, cur | (1 << r) | (1 << (r + 1)), nxt);
    }
    dfs(r + 1, cur | (1 << r), nxt | (1 << r));
}
signed main() {
    if (fopen("tile.in", "r")) {
        freopen("tile.in", "r", stdin);
        freopen("tile.out", "w", stdout);
    }
    scanf("%d%d", &n, &m);
    if (n > m) {
        k = n, n = m, m = k;
    }
    sz = 1 << n;
    for (st = 0; st < sz; st++) {
        dfs(0, st, 0);
    }
    for (i = 0; i < sz; i++) {
        R[i][i] = 1;
    }
    for (i = 0; i < sz; i++) {
        for (j = 0; j < sz; j++) {
            B[i][j] = T[i][j];
        }
    }
    e = m;
    while (e) {
        if (e & 1) {
            for (i = 0; i < sz; i++) {
                for (j = 0; j < sz; j++) {
                    A[i][j] = R[i][j];
                    C[i][j] = 0;
                }
            }
            mul();
            for (i = 0; i < sz; i++) {
                for (j = 0; j < sz; j++) {
                    R[i][j] = C[i][j];
                }
            }
        }
        for (i = 0; i < sz; i++) {
            for (j = 0; j < sz; j++) {
                A[i][j] = B[i][j];
            }
        }
        mul();
        for (i = 0; i < sz; i++) {
            for (j = 0; j < sz; j++) {
                B[i][j] = C[i][j];
            }
        }
        e >>= 1;
    }
    printf("%d\n", R[0][0] % MOD);
    return 0;
}
