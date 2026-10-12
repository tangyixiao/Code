#define MULTIPLE_TEST
#include <bits/stdc++.h>
using namespace std;

namespace TANGYIXIAO {
inline long long pw(long long a, int e, int mod) {
    long long r = 1 % mod;
    for (; e; e >>= 1) {
        if (e & 1) {
            r = r * a % mod;
        }
        a = a * a % mod;
    }
    return r;
}

inline int getphi(int x) {
    int r = x;
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            r = r / d * (d - 1);
            for (; x % d == 0; x /= d) {
            }
        }
    }
    if (x > 1) {
        r = r / x * (x - 1);
    }
    return r;
}

inline bool findseg(const vector<int> &a, long long need, int &st, int &len) {
    if (need <= 0) {
        return false;
    }
    int n = (int)a.size(), r = 0;
    long long sum = 0;
    for (int l = 0; l < n; l++) {
        for (; r < l + n && sum < need; r++) {
            sum += a[r % n];
        }
        if (sum == need) {
            st = l, len = r - l;
            return true;
        }
        if (r > l) {
            sum -= a[l];
        }
    }
    return false;
}

inline void out(long long l, long long r) {
    cout << l << ' ' << r << '\n';
    return;
}

inline void solve(int Task_Id) {
    int k;
    long long p;
    cin >> k >> p;
    int q = k - 1, ph = getphi(q), m = q * ph;
    vector<int> pre(q), cyc(m);
    for (int i = 1; i < q; i++) {
        int x = (int)pw(i, i, q);
        pre[i] = x ? x : q;
    }
    for (int x = 0; x < q; x++) {
        if (x == 0) {
            for (int t = 0; t < ph; t++) {
                cyc[t * q] = q;
            }
            continue;
        }
        long long value = pw(x, q + x, q), ratio = pw(x, q, q);
        for (int t = 0; t < ph; t++) {
            int at = x + t * q;
            cyc[at] = value ? (int)value : q;
            value = value * ratio % q;
        }
    }
    long long sumc = 0;
    for (int x : cyc) {
        sumc += x;
    }

    for (int l = 1; l < q; l++) {
        long long sum = 0;
        for (int r = l; r < q; r++) {
            sum += pre[r];
            if (sum == p) {
                out(l, r);
                return;
            }
            if (sum > p) {
                break;
            }
        }
    }

    long long cnt = p / sumc, rem = p % sumc;
    if (rem == 0 && cnt > 0) {
        out(q, q + cnt * m - 1);
        return;
    }
    int st, len;
    if (findseg(cyc, rem, st, len)) {
        long long l = q + st;
        out(l, l + cnt * m + len - 1);
        return;
    }

    vector<long long> ps(m + 1);
    for (int i = 0; i < m; i++) {
        ps[i + 1] = ps[i] + cyc[i];
    }
    vector<long long> sf(q + 1);
    for (int i = q - 1; i >= 1; i--) {
        sf[i] = sf[i + 1] + pre[i];
    }
    for (int l = 1; l < q; l++) {
        if (p < sf[l]) {
            continue;
        }
        long long need = p - sf[l], cycles = need / sumc, tail = need % sumc;
        auto it = lower_bound(ps.begin(), ps.begin() + m, tail);
        if (it == ps.begin() + m || *it != tail) {
            continue;
        }
        long long tot = cycles * m + (it - ps.begin());
        if (tot > 0) {
            out(l, q - 1 + tot);
            return;
        }
    }

    out(-1, -1);
    return;
}
} // namespace TANGYIXIAO

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef MULTIPLE_TEST
    int T;
    cin >> T;
#else
    int T = 1;
#endif
    for (int Task_Id = 1; Task_Id <= T; Task_Id++) {
        TANGYIXIAO::solve(Task_Id);
    }
    return 0;
}
