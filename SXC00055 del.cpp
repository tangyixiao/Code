#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int N = 2e3 + 5;
const int M = 2e3 + 5;
const ll INF = 1e18;
int n, m, eu[M], ev[M], done[M];
ll ew[M], ec[M], d[N];
vector<int> g[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i, j, u, v, e;
    ll w;
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> eu[i] >> ev[i] >> ew[i] >> ec[i];
        g[eu[i]].push_back(i);
        g[ev[i]].push_back(i);
    }
    for (int s = 1; s <= n; s++) {
        for (i = 1; i <= n; i++) {
            d[i] = INF;
        }
        d[s] = 0;
        priority_queue<pli, vector<pli>, greater<pli>> q;
        q.push(make_pair(0LL, s));
        while (!q.empty()) {
            pli pr = q.top();
            q.pop();
            u = pr.second;
            if (pr.first > d[u]) {
                continue;
            }
            for (j = 0; j < (int)g[u].size(); j++) {
                e = g[u][j];
                v = eu[e] == u ? ev[e] : eu[e];
                if (d[u] + ew[e] < d[v]) {
                    d[v] = d[u] + ew[e];
                    q.push(make_pair(d[v], v));
                }
            }
        }
        for (i = 1; i <= m; i++) {
            if (done[i]) {
                continue;
            }
            u = eu[i], v = ev[i], w = ew[i];
            if (d[u] < INF && d[u] + w == d[v]) {
                int best = i;
                for (j = 0; j < (int)g[v].size(); j++) {
                    e = g[v][j];
                    int x = eu[e] == v ? ev[e] : eu[e];
                    if (d[x] < INF && d[x] + ew[e] == d[v] && ec[e] < ec[best]) {
                        best = e;
                    }
                }
                done[best] = 1;
            }
            if (d[v] < INF && d[v] + w == d[u]) {
                int best = i;
                for (j = 0; j < (int)g[u].size(); j++) {
                    e = g[u][j];
                    int x = eu[e] == u ? ev[e] : eu[e];
                    if (d[x] < INF && d[x] + ew[e] == d[u] && ec[e] < ec[best]) {
                        best = e;
                    }
                }
                done[best] = 1;
            }
        }
    }
    ll ans = 0;
    for (i = 1; i <= m; i++) {
        if (done[i]) {
            ans += ec[i];
        }
    }
    cout << ans << "\n";
    return 0;
}
