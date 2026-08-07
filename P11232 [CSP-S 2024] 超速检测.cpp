#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct I {
    int l, r;
    bool operator<(const I &o) const { return r < o.r; }
} A[N];
int t, n, m, L, V, P[N], D[N], W[N], K[N];
void S() {
    cin >> n >> m >> L >> V;
    for (int i = 1; i <= n; ++i)
        cin >> D[i] >> W[i] >> K[i];
    for (int i = 1; i <= m; ++i)
        cin >> P[i];
    int c = 0, l = 0, a = 0;
    for (int i = 1; i <= n; ++i) {
        if (W[i] <= V && K[i] <= 0)
            continue;
        int s = D[i], e = L;
        if (K[i] > 0 && W[i] <= V)
            s += (V * V - W[i] * W[i]) / (2 * K[i]) + 1;
        if (K[i] < 0 && W[i] > V)
            e = D[i] + (W[i] * W[i] - V * V - 1) / (-2 * K[i]);
        int x = lower_bound(P + 1, P + m + 1, s) - P, y = upper_bound(P + 1, P + m + 1, e) - P - 1;
        if (x <= y)
            A[c++] = {x, y};
    }
    sort(A, A + c);
    for (int i = 0; i < c; ++i)
        if (A[i].l > l)
            l = A[i].r, a++;
    cout << c << " " << m - a << "\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
        S();
}
/*


#include <bits/stdc++.h>
#define int long long
// #define local
using namespace std;
const int N = 1e5 + 5;
bool pd[N], vis[N];
int T, n, m, L, V, d[N], v[N], a[N], p[N];
int ans = 0x3f3f3f3f, res;
vector<int> ve[N];
bool beyd(int v_0, int a_, int s_) {
    return (v_0 * v_0 + 2 * a_ * s_) > V * V;
}
inline void dfs(int id, int cnt) {
    if (cnt >= ans) {
        return;
    }
    if (id == n + 1) {
        ans = min(cnt, ans);
        return;
    }
    for (int i = 0; i < ve[id].size(); i++) {
        if (vis[ve[id][i]]) {
            dfs(id + 1, cnt);
            break;
        }
    }
    for (int i = 0; i < ve[id].size(); i++) {
        vis[ve[id][i]] = true;
        dfs(id + 1, cnt + 1);
        vis[ve[id][i]] = false;
    }
    if (ve[id].size() == 0) {
        dfs(id + 1, cnt);
    }
    return;
}
string check() {
    bool f0, f1, f_1;
    f0 = f1 = f_1 = true;
    for (int i = 1; i <= n; i++) {
        if (a[i] != 0) {
            f0 = false;
        }
        if (a[i] <= 0) {
            f1 = false;
        }
        if (a[i] >= 0) {
            f_1 = false;
        }
        if (!((f0 || f1) || f_1)) {
            return "fail";
            break;
        }
    }
    if (f0) {
        return "A";
    }
    if (f1) {
        return "B";
    }
    if (f_1) {
        return "C";
    }
}
inline void solve1() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (d[i] >= p[j]) {
                continue;
            }
            if (beyd(v[i], a[i], p[j] - d[i])) {
                if (!pd[i]) {
                    res++;
                    pd[i] = true;
                }
                ve[i].push_back(j);
            }
        }
    }
    dfs(1, 0);
    ans = n - ans;
    return;
}
inline void solve2(string s) {
    if (s == "A") {
        for (int i = 1; i <= n; i++) {
            if (d[i] <= p[m]) {
                if (v[i] > V) {
                    res++;
                }
            }
        }
        if (res == 0) {
            ans = m;
        } else {
            ans = m - 1;
        }
    }
    if (s == "B") {
        for (int i = 1; i <= n; i++) {
            if (p[m] >= d[i]) {
                if (beyd(v[i], a[i], p[m] - d[i])) {
                    res++;
                }
            }
        }
        if (res == 0) {
            ans = m;
        } else {
            ans = m - 1;
        }
    }
    if (s == "C") {
        for (int i = 1; i <= n; i++) {
            if (v[i] <= V) {
                continue;
            }
            for (int j = 1; j <= m; j++) {
                if (d[i] >= p[j]) {
                    continue;
                }
                if (beyd(v[i], a[i], p[j] - d[i])) {
                    if (!pd[i]) {
                        res++;
                        pd[i] = true;
                    }
                    ve[i].push_back(j);
                }
            }
        }
        if (n >= 30 && m >= 30) {
            ans = n;
            return;
        }
        dfs(1, 0);
        ans = n - ans;
    }
    return;
}
signed main() {
#ifndef local
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (cin >> T; T; T--) {
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++) {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> p[i];
        }
        sort(p + 1, p + 1 + m);
        string s = check();
        if (s != "fail") {
            solve2(s);
        } else {
            solve1();
            for (int i = 1; i <= n; i++) {
                ve[i].clear();
                pd[i] = vis[i] = false;
            }
        }
        cout << res << " " << ans << "\n";
        ans = 0x3f3f3f3f;
        res = 0;
    }
    return 0;
}

*/