#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1e6 + 5, Base1 = 131, Base2 = 137, Mod1 = 1e9 + 9, Mod2 = 1e9 + 7;
int n, m, pow1[M], pow2[M], h1[M], h2[M], lx, ly, ans, cnt0, cnt1;
char x = '0', y = '1';
string s, t;
namespace Mathematics {
inline int qpow(int a, int b, int MOD) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
} // namespace Mathematics
inline void Init() {
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i <= m; i++) {
        pow1[i] = pow1[i - 1] * Base1 % Mod1;
        pow2[i] = pow2[i - 1] * Base2 % Mod2;
    }
    h1[0] = h2[0] = 0;
    for (int i = 1; i <= m; i++) {
        h1[i] = (h1[i - 1] * Base1 + t[i - 1]) % Mod1;
        h2[i] = (h2[i - 1] * Base2 + t[i - 1]) % Mod2;
    }
    return;
}
inline pair<int, int> get_hash(int l, int r) {
    int hash1 = (h1[r] - h1[l] * pow1[r - l] % Mod1 + Mod1) % Mod1;
    int hash2 = (h2[r] - h2[l] * pow2[r - l] % Mod2 + Mod2) % Mod2;
    return {hash1, hash2};
}
inline bool check() {
    int now = 0, px = -1, py = -1;
    pair<int, int> hashx, hashy;
    for (int i = 0, l, r; i < n; i++) {
        if (s[i] == x) {
            l = now, r = now + lx;
            pair<int, int> h = get_hash(l, r);
            if (px == -1) {
                hashx = h;
                px = l;
            } else if (h != hashx) {
                return false;
            }
            now = r;
        } else {
            l = now, r = now + ly;
            pair<int, int> h = get_hash(l, r);
            if (py == -1) {
                hashy = h;
                py = l;
            } else if (h != hashy) {
                return false;
            }
            now = r;
        }
    }
    if (hashx == hashy) {
        if (lx == ly) {
            if (t.substr(px, lx) == t.substr(py, ly)) {
                return false;
            }
        }
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    n = s.size(), m = t.size();
    Init();
    cnt0 = count(s.begin(), s.end(), '0'), cnt1 = n - cnt0;
    if (cnt0 < cnt1) {
        swap(x, y);
        swap(cnt0, cnt1);
    }
    for (lx = 1; lx <= m; lx++) {
        int totx = cnt0 * lx;
        if (totx >= m) {
            break;
        }
        int rem = m - totx;
        if (!(rem % cnt1)) {
            ly = rem / cnt1;
            if (ly > 0) {
                ans += check();
            }
        }
    }
    cout << ans << "\n";
    return 0;
}