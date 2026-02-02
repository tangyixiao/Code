#include <bits/stdc++.h>
#define pii pair<int, int>
#define beg begin()
#define en end()
using namespace std;
const int N = 2e5 + 5;
int t, n, p[N], rt, maxn;
inline void solve() {
    set<pii> s;
    vector<pii> L;s
    maxn = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] == 1) {
            rt = i;
            break;
        }
    }
    if (rt == n) {
        cout << "No\n";
        return;
    }
    for (int i = rt + 1; i <= n; i++) {
        maxn = max(maxn, p[i]);
    }
    for (int i = 1; i <= rt; i++) {
        L.push_back({p[i], i});
    }
    if (!L.size()) {
        cout << "Yes\n";
        return;
    }
    sort(L.beg, L.en);
    for (auto [v, id] : L) {
        int cpm = id, cvm = v;
        for (auto it = s.beg; s.size() && s.beg->first < id; it = s.beg) {
            cpm = min(cpm, it->first), cvm = min(cvm, it->second);
            s.erase(it);
        }
        s.insert({cpm, cvm});
    }
    for (auto cm : s) {
        if (cm.second >= maxn) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
