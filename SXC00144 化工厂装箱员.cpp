#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int INF = 1e9;
int n, c[N], pc[N][3], memo[N][12][12][12];

int seg(int l, int r, int p) {
    if (l > r) {
        return 0;
    }
    return pc[r][p] - pc[l - 1][p];
}

int solve(int t, int h, int na, int nb) {
    if (h == 0) {
        return 0;
    }
    int nc = h - na - nb;
    if (memo[t][h][na][nb] >= 0) {
        return memo[t][h][na][nb];
    }
    int best = INF, p, q, take, rest;
    int own[3], nxt[3];
    own[0] = na, own[1] = nb, own[2] = nc;
    for (p = 0; p < 3; p++) {
        if (own[p] == 0) {
            continue;
        }
        rest = h - own[p];
        take = min(10 - rest, n - t);
        for (q = 0; q < 3; q++) {
            nxt[q] = own[q];
            if (q == p) {
                nxt[q] = 0;
            }
            if (take > 0) {
                nxt[q] += seg(t + 1, t + take, q);
            }
        }
        best = min(best, 1 + solve(t + take, rest + take, nxt[0], nxt[1]));
    }
    memo[t][h][na][nb] = best;
    return best;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i, j, t, na, nb;
    char ch;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> ch;
        c[i] = ch - 'A';
    }
    for (i = 1; i <= n; i++) {
        for (j = 0; j < 3; j++) {
            pc[i][j] = pc[i - 1][j];
        }
        pc[i][c[i]]++;
    }
    memset(memo, -1, sizeof(memo));
    t = min(10, n);
    na = seg(1, t, 0), nb = seg(1, t, 1);
    cout << solve(t, t, na, nb) << "\n";
    return 0;
}
