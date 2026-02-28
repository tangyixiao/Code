#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAXN = 200005;

int parent[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y)
        parent[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> eq, neq;
        vector<int> vals;

        for (int i = 0; i < n; ++i) {
            int a, b, e;
            cin >> a >> b >> e;
            vals.push_back(a);
            vals.push_back(b);
            if (e == 1)
                eq.push_back({a, b});
            else
                neq.push_back({a, b});
        }

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        unordered_map<int, int> mp;
        for (size_t i = 0; i < vals.size(); ++i) {
            mp[vals[i]] = i + 1;
        }
        int m = vals.size();
        for (int i = 1; i <= m; ++i)
            parent[i] = i;

        for (auto &p : eq) {
            int u = mp[p.first], v = mp[p.second];
            unite(u, v);
        }

        bool ok = true;
        for (auto &p : neq) {
            int u = mp[p.first], v = mp[p.second];
            if (find(u) == find(v)) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}