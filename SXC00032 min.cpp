#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const long long BIG = 1e18;

int t, n, i, j;
long long k, g, ans;
long long a[N], b[3 * N];

long long abss(long long x) {
    return x < 0 ? -x : x;
}

signed main() {
    scanf("%d", &t);
    while (t > 0) {
        t--;
        scanf("%d %lld", &n, &k);
        for (i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        sort(a + 1, a + n + 1);
        g = 0;
        for (i = 1; i <= n; i++) {
            g = __gcd(g, a[i]);
        }
        ans = BIG;
        for (i = 1; i <= n; i++) {
            if (a[i] < ans) {
                ans = a[i];
            }
        }
        int dup = 0;
        for (i = 2; i <= n; i++) {
            if (a[i] == a[i - 1]) {
                dup = 1;
            }
        }
        if (dup == 1 && k >= 1) {
            ans = 0;
        }
        if (ans != 0 && k >= 3) {
            map<long long, pair<int, int>> mp;
            for (i = 1; i <= n; i++) {
                for (j = i + 1; j <= n; j++) {
                    long long d = a[j] - a[i];
                    if (mp.count(d)) {
                        pair<int, int> pr = mp[d];
                        if (pr.second <= i || j <= pr.first) {
                            ans = 0;
                        }
                    } else if (d > 0) {
                        mp[d] = make_pair(i, j);
                    }
                }
            }
        }
        if (ans != 0) {
            long long steps = k;
            if (steps > 300) {
                steps = 300;
            }
            int len = n;
            for (i = 1; i <= n; i++) {
                b[i] = a[i];
            }
            for (long long s = 1; s <= steps; s++) {
                long long bd = BIG;
                for (i = 2; i <= len; i++) {
                    if (b[i] - b[i - 1] < bd) {
                        bd = b[i] - b[i - 1];
                    }
                }
                if (bd == 0) {
                    ans = 0;
                    break;
                }
                if (bd < ans) {
                    ans = bd;
                }
                len++;
                b[len] = bd;
                for (i = len; i >= 2 && b[i] < b[i - 1]; i--) {
                    long long tmp = b[i];
                    b[i] = b[i - 1];
                    b[i - 1] = tmp;
                }
            }
            if (k > 300 && g < ans) {
                ans = g;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
