#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, k, c[30], p, o;
char s[N];

signed main() {
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        c[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        p += c[i] / 2;
        o += c[i] % 2;
    }
    int l = 1, r = n, ans = 0;
    for (; l <= r;) {
        int m = (l + r) / 2, q = m / 2;
        int ok = 0;
        if (1LL * k * q <= p) {
            if (m % 2 == 0) {
                ok = 1;
            } else if (1LL * o + 2LL * (p - 1LL * k * q) >= k) {
                ok = 1;
            }
        }
        if (ok) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
