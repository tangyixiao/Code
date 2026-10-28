#include <bits/stdc++.h>
using namespace std;
const int K = 12;
const int S = 9500;
long long way[K][S], pre[K][S], A, B, fa, ans, rem;
int T, t, i, j, d, len, w, dig[20];
long long F(long long x) {
    long long r = 0, b = 1;
    if (x == 0) {
        return 0;
    }
    for (; x > 0; x /= 10, b *= 2) {
        r += x % 10 * b;
    }
    return r;
}
long long cnt(int k, long long s) {
    if (s < 0) {
        return 0;
    }
    if (s >= S) {
        s = S - 1;
    }
    return pre[k][s];
}
signed main() {
    way[0][0] = 1;
    for (i = 1; i < K; i++) {
        w = 1 << (i - 1);
        for (j = 0; j < S; j++) {
            way[i][j] = 0;
        }
        for (j = 0; j < S; j++) {
            if (!way[i - 1][j]) {
                continue;
            }
            for (d = 0; d <= 9; d++) {
                if (j + d * w < S) {
                    way[i][j + d * w] += way[i - 1][j];
                }
            }
        }
    }
    for (i = 0; i < K; i++) {
        for (j = 0; j < S; j++) {
            pre[i][j] = way[i][j] + (j > 0 ? pre[i][j - 1] : 0);
        }
    }
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        scanf("%lld%lld", &A, &B);
        fa = F(A);
        ans = 0;
        long long x = B;
        len = 0;
        for (; x > 0; x /= 10) {
            dig[len++] = x % 10;
        }
        rem = fa;
        for (i = len - 1; i >= 0; i--) {
            w = 1 << i;
            for (d = 0; d < dig[i]; d++) {
                if (rem - (long long)d * w >= 0) {
                    ans += cnt(i, rem - (long long)d * w);
                }
            }
            rem -= (long long)dig[i] * w;
            if (rem < 0) {
                break;
            }
        }
        if (rem >= 0) {
            ans++;
        }
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}
