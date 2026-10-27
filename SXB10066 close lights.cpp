#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const long long INF = 1e18;
int n, c, cnt;
int ord[N], pp[N], ww[N];
long long pre[N], f[N][N][2];
int rp[N];
int rw[N];

void swp(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

signed main() {
    if (fopen("power.in", "r")) {
        freopen("power.in", "r", stdin);
        freopen("power.out", "w", stdout);
    }
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &rp[i], &rw[i]);
    }
    for (int i = 1; i <= n; i++) {
        ord[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (rp[ord[j]] < rp[ord[i]]) {
                swp(ord[i], ord[j]);
            }
        }
    }
    int st = 1;
    for (int i = 1; i <= n; i++) {
        pp[i] = rp[ord[i]];
        ww[i] = rw[ord[i]];
        pre[i] = pre[i - 1] + ww[i];
        if (ord[i] == c) {
            st = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j][0] = INF;
            f[i][j][1] = INF;
        }
    }
    f[st][st][0] = 0;
    f[st][st][1] = 0;
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (f[l][r][0] >= INF && f[l][r][1] >= INF) {
                continue;
            }
            long long rem = pre[n] - (pre[r] - pre[l - 1]);
            if (l - 1 >= 1) {
                long long d1 = pp[l] - pp[l - 1];
                long long d2 = pp[r] - pp[l - 1];
                long long v1 = f[l][r][0] + d1 * rem;
                long long v2 = f[l][r][1] + d2 * rem;
                long long v = v1 < v2 ? v1 : v2;
                if (v < f[l - 1][r][0]) {
                    f[l - 1][r][0] = v;
                }
            }
            if (r + 1 <= n) {
                long long d1 = pp[r + 1] - pp[r];
                long long d2 = pp[r + 1] - pp[l];
                long long v1 = f[l][r][1] + d1 * rem;
                long long v2 = f[l][r][0] + d2 * rem;
                long long v = v1 < v2 ? v1 : v2;
                if (v < f[l][r + 1][1]) {
                    f[l][r + 1][1] = v;
                }
            }
        }
    }
    long long ans = f[1][n][0] < f[1][n][1] ? f[1][n][0] : f[1][n][1];
    printf("%lld\n", ans);
    return 0;
}
