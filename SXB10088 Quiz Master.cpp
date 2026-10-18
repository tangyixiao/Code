#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 1e5 + 5;

int t, n, m;
int a[N], b[N];
int cnt[M], dv[140];
int cov, ans;

inline void add(int x) {
    if (x == 0) {
        return;
    }
    int tot = 0;
    for (int i = 1; 1ll * i * i <= x; i++) {
        if (x % i == 0) {
            if (i <= m) {
                dv[++tot] = i;
            }
            if (i != x / i && x / i <= m) {
                dv[++tot] = x / i;
            }
        }
    }
    for (int i = 1; i <= tot; i++) {
        if (cnt[dv[i]]++ == 0) {
            cov++;
        }
    }
}

inline void del(int x) {
    if (x == 0) {
        return;
    }
    int tot = 0;
    for (int i = 1; 1ll * i * i <= x; i++) {
        if (x % i == 0) {
            if (i <= m) {
                dv[++tot] = i;
            }
            if (i != x / i && x / i <= m) {
                dv[++tot] = x / i;
            }
        }
    }
    for (int i = 1; i <= tot; i++) {
        if (--cnt[dv[i]] == 0) {
            cov--;
        }
    }
}

inline bool cmp(int x, int y) {
    return a[x] < a[y];
}

inline void input() {
    cin >> t;
}

inline void solve() {
    for (; t--;) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = i;
        }
        sort(b + 1, b + n + 1, cmp);
        fill(cnt + 1, cnt + m + 1, 0);
        cov = 0;
        ans = -1;
        int r = 0;
        for (int l = 1; l <= n; l++) {
            while (cov < m && r < n) {
                add(a[b[++r]]);
            }
            if (cov == m) {
                int d = a[b[r]] - a[b[l]];
                if (ans == -1 || d < ans) {
                    ans = d;
                }
            }
            if (l <= r) {
                del(a[b[l]]);
            }
        }
        cout << ans << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
