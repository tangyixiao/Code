#include <bits/stdc++.h>
using namespace std;

namespace TANGYIXIAO {
using ull = unsigned long long;
const int MOD = 998244353;
int c[15], opp[15], mx1, mx2, mx3, mxS[13], mxP[13], mxT[13], b[15], rcnt;
ull res[50005];
bool inited;
unordered_set<ull> st, bad;

inline ull pack(int *a) {
    ull z = 0;
    for (int i = 0; i < 13; i++) {
        z |= ((1ULL << a[i]) - 1) << (i * 4);
    }
    if (a[13]) {
        z |= 1ULL << 52;
    }
    if (a[14]) {
        z |= 1ULL << 53;
    }
    return z;
}

inline ull code() {
    ull z = 0;
    for (int i = 0; i < 15; i++) {
        z |= (ull)c[i] << (i * 3);
    }
    return z;
}

inline bool legal(int tot) {
    if (tot == 1) {
        return true;
    }
    if (tot == 2) {
        if (c[13] && c[14]) {
            return true;
        }
        for (int i = 0; i < 13; i++) {
            if (c[i] == 2) {
                return true;
            }
        }
        return false;
    }
    if (tot == 3) {
        for (int i = 0; i < 13; i++) {
            if (c[i] == 3) {
                return true;
            }
        }
        return false;
    }
    if (tot == 4) {
        for (int i = 0; i < 13; i++) {
            if (c[i] >= 3) {
                return true;
            }
        }
    }
    if (tot == 5) {
        for (int i = 0; i < 13; i++) {
            if (c[i] == 3) {
                for (int j = 0; j < 13; j++) {
                    if (i != j && c[j] == 2) {
                        return true;
                    }
                }
            }
        }
    }
    if (tot == 6) {
        for (int i = 0; i < 13; i++) {
            if (c[i] == 4) {
                return true;
            }
        }
    }
    if (tot >= 5 && tot <= 12) {
        int l = -1, r = -1, k = 0, ok = 1;
        for (int i = 0; i < 15; i++) {
            if (c[i]) {
                if (i >= 12 || c[i] != 1) {
                    ok = 0;
                    break;
                }
                if (l == -1) {
                    l = i;
                }
                r = i, k++;
            }
        }
        if (ok && k == tot && r - l + 1 == k) {
            return true;
        }
    }
    if (tot >= 6 && tot % 2 == 0) {
        int k = tot / 2, l = -1, r = -1, z = 0, ok = k >= 3;
        for (int i = 0; i < 15 && ok; i++) {
            if (c[i]) {
                if (i >= 12 || c[i] != 2) {
                    ok = 0;
                    break;
                }
                if (l == -1) {
                    l = i;
                }
                r = i, z++;
            }
        }
        if (ok && z == k && r - l + 1 == k) {
            return true;
        }
    }
    if (tot >= 6 && tot % 3 == 0) {
        int k = tot / 3, l = -1, r = -1, z = 0, ok = k >= 2;
        for (int i = 0; i < 15 && ok; i++) {
            if (c[i]) {
                if (i >= 12 || c[i] != 3) {
                    ok = 0;
                    break;
                }
                if (l == -1) {
                    l = i;
                }
                r = i, z++;
            }
        }
        if (ok && z == k && r - l + 1 == k) {
            return true;
        }
    }
    if (tot >= 8 && tot % 4 == 0) {
        int k = tot / 4;
        if (k >= 2 && k <= 5) {
            for (int l = 0; l + k - 1 < 12; l++) {
                int ok = 1, sum = 0, z = 0;
                for (int i = l; i < l + k; i++) {
                    if (c[i] < 3) {
                        ok = 0;
                    }
                }
                if (ok) {
                    for (int i = 0; i < 15; i++) {
                        int v = c[i] - ((i >= l && i < l + k) ? 3 : 0);
                        if (v < 0 || v > 1) {
                            ok = 0;
                            break;
                        }
                        sum += v, z += (v > 0);
                    }
                }
                if (ok && sum == k && z == k) {
                    return true;
                }
            }
        }
    }
    if (tot >= 10 && tot % 5 == 0) {
        int k = tot / 5;
        if (k >= 2 && k <= 4) {
            for (int l = 0; l + k - 1 < 12; l++) {
                int ok = 1, sum = 0, z = 0;
                for (int i = l; i < l + k; i++) {
                    if (c[i] < 3) {
                        ok = 0;
                    }
                }
                if (ok) {
                    for (int i = 0; i < 15; i++) {
                        int v = c[i] - ((i >= l && i < l + k) ? 3 : 0);
                        if (i >= 13) {
                            if (v) {
                                ok = 0;
                                break;
                            }
                        } else if (v != 0 && v != 2) {
                            ok = 0;
                            break;
                        }
                        sum += v, z += (v == 2);
                    }
                }
                if (ok && sum == 2 * k && z == k) {
                    return true;
                }
            }
        }
    }
    return false;
}

inline bool dfs(int left);

inline bool wing1(int p, int need, int left) {
    if (!need) {
        return dfs(left);
    }
    int num = 0;
    for (int i = p; i < 15; i++) {
        if (c[i]) {
            num++;
        }
    }
    if (num < need) {
        return false;
    }
    for (int i = p; i < 15; i++) {
        if (c[i]) {
            c[i]--;
            if (wing1(i + 1, need - 1, left - 1)) {
                c[i]++;
                return true;
            }
            c[i]++;
        }
    }
    return false;
}

inline bool wing2(int p, int need, int left) {
    if (!need) {
        return dfs(left);
    }
    int num = 0;
    for (int i = p; i < 13; i++) {
        if (c[i] >= 2) {
            num++;
        }
    }
    if (num < need) {
        return false;
    }
    for (int i = p; i < 13; i++) {
        if (c[i] >= 2) {
            c[i] -= 2;
            if (wing2(i + 1, need - 1, left - 2)) {
                c[i] += 2;
                return true;
            }
            c[i] += 2;
        }
    }
    return false;
}

inline bool dfs(int left) {
    if (legal(left)) {
        return true;
    }
    ull z = code();
    if (bad.count(z)) {
        return false;
    }
    for (int l = 0; l < 12; l++) {
        if (c[l]) {
            for (int r = l; r < 12 && c[r]; r++) {
                int k = r - l + 1;
                if (k >= 5 && r >= mxS[k]) {
                    for (int i = l; i <= r; i++) {
                        c[i]--;
                    }
                    if (dfs(left - k)) {
                        for (int i = l; i <= r; i++) {
                            c[i]++;
                        }
                        return true;
                    }
                    for (int i = l; i <= r; i++) {
                        c[i]++;
                    }
                }
            }
        }
    }
    for (int l = 0; l < 12; l++) {
        if (c[l] >= 2) {
            for (int r = l; r < 12 && c[r] >= 2; r++) {
                int k = r - l + 1;
                if (k >= 3 && r >= mxP[k]) {
                    for (int i = l; i <= r; i++) {
                        c[i] -= 2;
                    }
                    if (dfs(left - 2 * k)) {
                        for (int i = l; i <= r; i++) {
                            c[i] += 2;
                        }
                        return true;
                    }
                    for (int i = l; i <= r; i++) {
                        c[i] += 2;
                    }
                }
            }
        }
    }
    for (int l = 0; l < 12; l++) {
        if (c[l] >= 3) {
            for (int r = l; r < 12 && c[r] >= 3; r++) {
                int k = r - l + 1;
                if (k >= 2 && r >= mxT[k]) {
                    for (int i = l; i <= r; i++) {
                        c[i] -= 3;
                    }
                    if (dfs(left - 3 * k) || wing1(0, k, left - 3 * k) || wing2(0, k, left - 3 * k)) {
                        for (int i = l; i <= r; i++) {
                            c[i] += 3;
                        }
                        return true;
                    }
                    for (int i = l; i <= r; i++) {
                        c[i] += 3;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 13; i++) {
        if (c[i] >= 4) {
            c[i] -= 4;
            if (dfs(left - 4)) {
                c[i] += 4;
                return true;
            }
            for (int j = 0; j < 15; j++) {
                if (j != i && c[j]) {
                    c[j]--;
                    for (int k = j; k < 15; k++) {
                        if (k != i && c[k]) {
                            c[k]--;
                            if (dfs(left - 6)) {
                                c[k]++, c[j]++, c[i] += 4;
                                return true;
                            }
                            c[k]++;
                        }
                    }
                    c[j]++;
                }
            }
            c[i] += 4;
        }
    }
    for (int i = 0; i < 13; i++) {
        if (c[i] >= 3 && i >= mx3) {
            c[i] -= 3;
            if (dfs(left - 3)) {
                c[i] += 3;
                return true;
            }
            for (int j = 0; j < 15; j++) {
                if (j != i && c[j]) {
                    c[j]--;
                    if (dfs(left - 4)) {
                        c[j]++, c[i] += 3;
                        return true;
                    }
                    c[j]++;
                }
            }
            for (int j = 0; j < 13; j++) {
                if (j != i && c[j] >= 2) {
                    c[j] -= 2;
                    if (dfs(left - 5)) {
                        c[j] += 2, c[i] += 3;
                        return true;
                    }
                    c[j] += 2;
                }
            }
            c[i] += 3;
        }
    }
    for (int i = 0; i < 13; i++) {
        if (c[i] >= 2 && i >= mx2) {
            c[i] -= 2;
            if (dfs(left - 2)) {
                c[i] += 2;
                return true;
            }
            c[i] += 2;
        }
    }
    if (c[13] && c[14]) {
        c[13]--, c[14]--;
        if (dfs(left - 2)) {
            c[13]++, c[14]++;
            return true;
        }
        c[13]++, c[14]++;
    }
    for (int i = 0; i < 15; i++) {
        if (c[i] && i >= mx1) {
            c[i]--;
            if (dfs(left - 1)) {
                c[i]++;
                return true;
            }
            c[i]++;
        }
    }
    bad.insert(z);
    return false;
}

inline void prep(int *h) {
    for (int i = 0; i < 13; i++) {
        opp[i] = 4 - h[i];
    }
    opp[13] = 1 - h[13], opp[14] = 1 - h[14];
    mx1 = mx2 = mx3 = -1;
    for (int i = 0; i < 15; i++) {
        if (opp[i]) {
            mx1 = i;
        }
    }
    for (int i = 0; i < 13; i++) {
        if (opp[i] >= 2) {
            mx2 = i;
        }
        if (opp[i] >= 3) {
            mx3 = i;
        }
    }
    for (int k = 0; k <= 12; k++) {
        mxS[k] = mxP[k] = mxT[k] = -1;
    }
    for (int k = 1; k <= 12; k++) {
        for (int l = 0; l + k <= 12; l++) {
            int x = 1, y = 1, z = 1;
            for (int i = l; i < l + k; i++) {
                x &= opp[i] >= 1, y &= opp[i] >= 2, z &= opp[i] >= 3;
            }
            if (x) {
                mxS[k] = l + k - 1;
            }
            if (y) {
                mxP[k] = l + k - 1;
            }
            if (z) {
                mxT[k] = l + k - 1;
            }
        }
    }
}

inline void check1(int *h) {
    for (int i = 0; i < 15; i++) {
        c[i] = h[i];
    }
    prep(h), bad.clear();
    if (dfs(20)) {
        st.insert(pack(h));
    }
}

inline void gen1(int p, int rem, int *h) {
    if (p == 13) {
        if (!rem) {
            check1(h);
        }
        return;
    }
    for (int x = 0; x <= 3 && x <= rem; x++) {
        h[p] = 1 + x;
        gen1(p + 1, rem - x, h);
    }
    h[p] = 1;
}

inline void build1() {
    int h[15] = {};
    for (int i = 0; i < 13; i++) {
        h[i] = 1;
    }
    h[13] = 1, h[14] = 0, gen1(0, 6, h);
    h[13] = 0, h[14] = 1, gen1(0, 6, h);
    h[13] = h[14] = 1, gen1(0, 5, h);
}

inline void add(int *a, int sz) {
    int h[15];
    memcpy(h, a, sizeof(h));
    if (sz == 20) {
        st.insert(pack(h));
        return;
    }
    if (!h[13] && !h[14]) {
        h[13] = h[14] = 1, sz += 2;
    }
    if (sz > 20 || (20 - sz) % 4) {
        return;
    }
    for (int i = 12; i >= 0 && sz < 20; i--) {
        if (!h[i]) {
            h[i] = 4, sz += 4;
        }
    }
    if (sz == 20) {
        st.insert(pack(h));
    }
}

inline void choose1(int p, int need, int k, int sz) {
    if (!need) {
        add(b, sz + k);
        return;
    }
    for (int i = p; i < 15; i++) {
        if (b[i] < (i < 13 ? 4 : 1)) {
            b[i]++;
            choose1(i + 1, need - 1, k, sz);
            b[i]--;
        }
    }
}

inline void choose2(int p, int need, int k, int sz) {
    if (!need) {
        add(b, sz + 2 * k);
        return;
    }
    for (int i = p; i < 13; i++) {
        if (b[i] + 2 <= 4) {
            b[i] += 2;
            choose2(i + 1, need - 1, k, sz);
            b[i] -= 2;
        }
    }
}

inline void build2() {
    memset(b, 0, sizeof(b));
    for (int i = 0; i < 15; i++) {
        b[i] = 1, add(b, 1), b[i] = 0;
    }
    for (int i = 0; i < 13; i++) {
        b[i] = 2, add(b, 2), b[i] = 0;
        b[i] = 3, add(b, 3);
        for (int j = 0; j < 15; j++) {
            if (j != i) {
                b[j]++, add(b, 4), b[j]--;
            }
        }
        for (int j = 0; j < 13; j++) {
            if (j != i) {
                b[j] += 2, add(b, 5), b[j] -= 2;
            }
        }
        b[i] = 0;
        b[i] = 4, add(b, 4);
        for (int j = 0; j < 15; j++) {
            if (j != i) {
                b[j]++;
                for (int k = j; k < 15; k++) {
                    if (k != i && b[k] < (k < 13 ? 4 : 1)) {
                        b[k]++, add(b, 6), b[k]--;
                    }
                }
                b[j]--;
            }
        }
        b[i] = 0;
    }
    b[13] = b[14] = 1, add(b, 2), b[13] = b[14] = 0;
    for (int l = 0; l < 12; l++) {
        for (int r = l; r < 12; r++) {
            int k = r - l + 1;
            if (k >= 5) {
                for (int i = l; i <= r; i++) {
                    b[i] = 1;
                }
                add(b, k);
                for (int i = l; i <= r; i++) {
                    b[i] = 0;
                }
            }
            if (k >= 3) {
                for (int i = l; i <= r; i++) {
                    b[i] = 2;
                }
                add(b, 2 * k);
                for (int i = l; i <= r; i++) {
                    b[i] = 0;
                }
            }
            if (k >= 2) {
                for (int i = l; i <= r; i++) {
                    b[i] = 3;
                }
                add(b, 3 * k);
                if (4 * k <= 20) {
                    choose1(0, k, k, 3 * k);
                }
                if (5 * k <= 20) {
                    choose2(0, k, k, 3 * k);
                }
                for (int i = l; i <= r; i++) {
                    b[i] = 0;
                }
            }
        }
    }
}

inline int id(int x) {
    if (x == 1) {
        return 11;
    }
    if (x == 2) {
        return 12;
    }
    if (x <= 13) {
        return x - 3;
    }
    return x - 1;
}

inline void init() {
    st.reserve(50000), bad.reserve(4096);
    build1(), build2();
    for (auto x : st) {
        res[++rcnt] = x;
    }
    inited = true;
}

inline void solve(int Task_Id) {
    if (!inited) {
        init();
    }
    int n, q[15] = {};
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        q[id(x)]++;
    }
    ull x = pack(q);
    int ans = 0;
    for (int i = 1; i <= rcnt; i++) {
        if (!(x & ~res[i])) {
            ans++;
        }
    }
    cout << ans % MOD << "\n";
}
} // namespace TANGYIXIAO

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        TANGYIXIAO::solve(i);
    }
    return 0;
}