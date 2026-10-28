#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, p, k;
vector<pair<int, int>> g[N];
int d[N];

bool check(int x) {
    memset(d, 0x3f, sizeof(d));
    deque<int> q;
    d[1] = 0;
    q.push_front(1);
    for (; !q.empty();) {
        int u = q.front();
        q.pop_front();
        for (pair<int, int> e : g[u]) {
            int v = e.first, w = e.second > x ? 1 : 0;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if (w) {
                    q.push_back(v);
                } else {
                    q.push_front(v);
                }
            }
        }
    }
    return d[n] <= k;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> p >> k;
    for (int i = 1, a, b, l; i <= p; i++) {
        cin >> a >> b >> l;
        g[a].push_back({b, l});
        g[b].push_back({a, l});
    }
    int l = 0, r = 1e6, ans = -1;
    for (; l <= r;) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid, r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
