#include <bits/stdc++.h>
using namespace std;
const int N = 255;
const int MOD = 97654321;
int dp[N][N][52];
int eh[52], en[3000], et[3000], ec;
int U, L, p, i, j, u, l, c, d, e, x, y;
long long ans;
int idx(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A';
    }
    return ch - 'a' + 26;
}
void add(int a, int b) {
    ec++;
    et[ec] = b, en[ec] = eh[a], eh[a] = ec;
}
int rd() {
    int ch;
    while ((ch = getchar()) != EOF) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            return ch;
        }
    }
    return -1;
}
signed main() {
    scanf("%d%d%d", &U, &L, &p);
    for (i = 1; i <= p; i++) {
        x = rd(), y = rd();
        add(idx((char)x), idx((char)y));
    }
    for (c = 0; c < 26; c++) {
        dp[1][0][c] = 1;
    }
    for (c = 26; c < 52; c++) {
        dp[0][1][c] = 1;
    }
    for (u = 0; u <= U; u++) {
        for (l = 0; l <= L; l++) {
            for (c = 0; c < 52; c++) {
                int v = dp[u][l][c];
                if (v == 0) {
                    continue;
                }
                for (e = eh[c]; e; e = en[e]) {
                    d = et[e];
                    if (d < 26) {
                        if (u + 1 <= U) {
                            dp[u + 1][l][d] = (dp[u + 1][l][d] + v) % MOD;
                        }
                    } else {
                        if (l + 1 <= L) {
                            dp[u][l + 1][d] = (dp[u][l + 1][d] + v) % MOD;
                        }
                    }
                }
            }
        }
    }
    ans = 0;
    for (c = 0; c < 52; c++) {
        ans += dp[U][L][c];
    }
    printf("%lld\n", ans % MOD);
    return 0;
}
