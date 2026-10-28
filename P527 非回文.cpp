#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const long long M = 1e9 + 7;

int n, i, c[30];
long long f[N], g[N];
char s[N];

long long pw(long long a, long long b) {
    long long r = 1;
    while (b > 0) {
        if (b & 1) {
            r = r * a % M;
        }
        a = a * a % M;
        b >>= 1;
    }
    return r;
}

signed main() {
    scanf("%d", &n);
    scanf("%s", s);
    for (i = 0; i < n; i++) {
        c[s[i] - 'a']++;
    }
    f[0] = 1;
    g[0] = 1;
    for (i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i % M;
        g[i] = pw(f[i], M - 2);
    }
    int odd = 0;
    for (i = 0; i < 26; i++) {
        if (c[i] % 2 != 0) {
            odd++;
        }
    }
    long long pal = 0;
    if (odd <= 1) {
        pal = f[n / 2];
        for (i = 0; i < 26; i++) {
            int h = c[i] / 2;
            pal = pal * g[h] % M;
            pal = pal * f[c[i]] % M;
            pal = pal * g[c[i] - h] % M;
        }
    }
    long long ans = (f[n] - pal % M + M) % M;
    printf("%lld\n", ans);
    return 0;
}
