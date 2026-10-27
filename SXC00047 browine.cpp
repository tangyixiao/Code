#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n, m, A, B;
long long p[N][N];
int e[N];

long long colsum(int l, int r, int c) {
    return p[r][c] - p[l - 1][c] - p[r][c - 1] + p[l - 1][c - 1];
}

bool feas(int l, int r, long long x) {
    int cnt = 0;
    long long acc = 0;
    for (int c = 1; c <= m; c++) {
        acc += colsum(l, r, c);
        if (acc >= x) {
            cnt++;
            acc = 0;
        }
    }
    return cnt >= B;
}

bool check(long long x) {
    int r = 1;
    for (int l = 1; l <= n; l++) {
        if (r < l) {
            r = l;
        }
        while (r <= n && !feas(l, r, x)) {
            r++;
        }
        e[l] = r;
    }
    r = 1;
    for (int i = 1; i < A; i++) {
        if (r > n || e[r] > n) {
            return false;
        }
        r = e[r] + 1;
    }
    if (r > n) {
        return false;
    }
    return e[r] <= n;
}

signed main() {
    if (fopen("browine.in", "r")) {
        freopen("browine.in", "r", stdin);
        freopen("browine.out", "w", stdout);
    }
    scanf("%d%d%d%d", &n, &m, &A, &B);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int v;
            scanf("%d", &v);
            p[i][j] = v + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }
    long long lo = 0, hi = p[n][m];
    while (lo < hi) {
        long long mid = (lo + hi + 1) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    printf("%lld\n", lo);
    return 0;
}
