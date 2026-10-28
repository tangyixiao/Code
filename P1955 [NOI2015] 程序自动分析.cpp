#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int t, n, fa[N];

int find(int x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    for (; t--;) {
        cin >> n;
        vector<pair<int, int>> eq, neq;
        vector<int> v;
        for (int i = 1, a, b, e; i <= n; i++) {
            cin >> a >> b >> e;
            v.push_back(a), v.push_back(b);
            if (e) {
                eq.push_back({a, b});
            } else {
                neq.push_back({a, b});
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        unordered_map<int, int> id;
        for (int i = 0; i < (int)v.size(); i++) {
            id[v[i]] = i + 1;
        }
        int m = v.size();
        for (int i = 1; i <= m; i++) {
            fa[i] = i;
        }
        for (pair<int, int> p : eq) {
            fa[find(id[p.first])] = find(id[p.second]);
        }
        bool ok = true;
        for (pair<int, int> p : neq) {
            if (find(id[p.first]) == find(id[p.second])) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
