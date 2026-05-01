#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e4 + 5, mod = 3e7 + 7;
string s;
int T, n, Hash[N], mo[N], u[N], v[N], ans;
inline int gethash(int l, int r) {
    return ((Hash[l] - Hash[r] * mo[r - l]) % mod + mod) % mod;
}
inline void init() {
    mo[0] = 1;
    for (int i = 1; i <= 30000; ++i) {
        mo[i] = mo[i - 1] * 31 % mod;
    }
    return;
}
inline void solve() {
    cin >> s;
    s = " " + s;
    n = s.size();
    memset(u, 0, sizeof(u));
    memset(v, 0, sizeof(v));
    Hash[n + 1] = 0;
    for (int i = n; i; --i) {
        (Hash[i] = Hash[i + 1] * 31 + s[i] - 'a' + 1) %= mod;
    }
    for (int L = 1; L * 2 <= n; ++L) {
        for (int i = L << 1; i <= n; i += L) {
            if (s[i] == s[i - L]) {
                int l = 1, r = L, last = i - L, pos = 0;
                while (l <= r) {
                    int mid = l + r >> 1;
                    if (gethash(last - mid + 1, last + 1) == gethash(i - mid + 1, i + 1))
                        pos = mid, l = mid + 1;
                    else
                        r = mid - 1;
                }
                int hd = i - pos + 1;
                l = 1, r = L, pos = 0;
                while (l <= r) {
                    int mid = l + r >> 1;
                    if (gethash(last, last + mid) == gethash(i, i + mid))
                        pos = mid, l = mid + 1;
                    else
                        r = mid - 1;
                }
                int tl = i + pos - 1;
                hd = max(hd + L - 1, i);
                tl = min(tl, i + L - 1);
                if (hd <= tl) {
                    ++u[hd - 2 * L + 1], --u[tl + 1 - 2 * L + 1];
                    ++v[hd], --v[tl + 1];
                }
            }
        }
    }
    ans = 0;
    for (int i = 1; i <= n; ++i)
        u[i] += u[i - 1], v[i] += v[i - 1];
    for (int i = 1; i < n; ++i) {
        ans += v[i] * u[i + 1];
    }
    cout << ans << endl;
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
