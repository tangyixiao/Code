#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    sort(edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end()), edges.end());
    m = edges.size();

    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0);
    for (auto &e : edges) {
        int u = e.first, v = e.second;
        g[u].push_back(v);
        ++indeg[v];
    }
    vector<int> indeg0 = indeg;

    priority_queue<int, vector<int>, greater<int>> pq_min;
    for (int i = 1; i <= n; ++i) {
        if (indeg[i] == 0)
            pq_min.push(i);
    }
    int cur_max = 0, ans1 = 0;
    while (!pq_min.empty()) {
        int u = pq_min.top();
        pq_min.pop();
        if (u > cur_max) {
            ++ans1;
            cur_max = u;
        }
        for (int v : g[u]) {
            if (--indeg[v] == 0)
                pq_min.push(v);
        }
    }
    cout << ans1 << '\n';

    indeg = indeg0;
    priority_queue<int> pq_max;
    for (int i = 1; i <= n; ++i) {
        if (indeg[i] == 0)
            pq_max.push(i);
    }
    cur_max = 0;
    int ans2 = 0;
    while (!pq_max.empty()) {
        int u = pq_max.top();
        pq_max.pop();
        if (u > cur_max) {
            ++ans2;
            cur_max = u;
        }
        for (int v : g[u]) {
            if (--indeg[v] == 0)
                pq_max.push(v);
        }
    }
    cout << ans2 << '\n';

    return 0;
}