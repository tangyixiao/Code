#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int n, k, i, ans;
long long a[N];
long long pw(long long x, long long y, long long m) {
    long long r = 1;
    x %= m;
    for (; y; y >>= 1) {
        if (y & 1) {
            r = r * x % m;
        }
        x = x * x % m;
    }
    return r;
}
bool prime(long long x) {
    if (x < 2) {
        return false;
    }
    if (x == 2 || x == 3 || x == 5 || x == 7) {
        return true;
    }
    for (int b = 2; b <= 7; b += 1) {
        if (x % b == 0) {
            return x == b;
        }
    }
    long long d = x - 1, s = 0;
    for (; d % 2 == 0;) {
        d /= 2, s++;
    }
    int bs[4] = {2, 3, 5, 7};
    for (int t = 0; t < 4; t++) {
        long long p = pw(bs[t], d, x);
        if (p == 1 || p == x - 1) {
            continue;
        }
        bool ok = false;
        for (long long r = 1; r < s; r++) {
            p = p * p % x;
            if (p == x - 1) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            return false;
        }
    }
    return true;
}
void dfs(int x, int c, long long s) {
    if (c == k) {
        if (prime(s)) {
            ans++;
        }
        return;
    }
    if (n - x + 1 < k - c) {
        return;
    }
    for (int i = x; i <= n; i++) {
        dfs(i + 1, c + 1, s + a[i]);
    }
}
signed main() {
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    ans = 0;
    dfs(1, 0, 0);
    printf("%d\n", ans);
    return 0;
}
