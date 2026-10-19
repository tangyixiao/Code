#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int M = 1e6 + 5;
const int B = 1 << 19;

int n, a[N], nsl[N], s1[N], s2[N], t1, t2, dp[N], tr[M];

inline void upd(int p, int v) {
    p += B - 1;
    tr[p] = v;
    for (p >>= 1; p; p >>= 1) {
        tr[p] = min(tr[p * 2], tr[p * 2 + 1]);
    }
}

inline int qry(int l, int r) {
    int res = 0x3f3f3f3f;
    for (l += B - 1, r += B - 1; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) {
            res = min(res, tr[l++]);
        }
        if (!(r & 1)) {
            res = min(res, tr[r--]);
        }
    }
    return res;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= M; i++) {
        tr[i] = 0x3f3f3f3f;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        while (t1 && a[s1[t1]] <= a[i]) {
            t1--;
        }
        nsl[i] = t1 ? s1[t1] : 0;
        s1[++t1] = i;
        while (t2 && a[s2[t2]] > a[i]) {
            upd(s2[t2], 0x3f3f3f3f);
            t2--;
        }
        s2[++t2] = i;
        upd(i, dp[i - 1]);
        dp[i] = qry(nsl[i] + 1, n) + 1;
    }
    cout << dp[n] << "\n";
    return 0;
}