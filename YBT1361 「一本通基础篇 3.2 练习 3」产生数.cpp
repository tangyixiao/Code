#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, k, ch[10][10], a[N], b[N];
set<int> vis;

inline void input() {
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        int x, y;
        cin >> x >> y;
        ch[x][y] = 1;
    }
}

inline void solve() {
    int len = 0;
    for (int x = n; x; x /= 10) {
        a[++len] = x % 10;
    }
    queue<vector<int>> q;
    vector<int> st;
    for (int i = len; i >= 1; --i) {
        st.push_back(a[i]);
    }
    q.push(st);
    vis.insert(n);
    while (!q.empty()) {
        vector<int> u = q.front();
        q.pop();
        for (int p = 0; p < (int)u.size(); ++p) {
            for (int d = 0; d <= 9; ++d) {
                if (!ch[u[p]][d]) {
                    continue;
                }
                vector<int> v = u;
                v[p] = d;
                int val = 0;
                for (int i = 0; i < (int)v.size(); ++i) {
                    val = val * 10 + v[i];
                }
                if (vis.insert(val).second) {
                    q.push(v);
                }
            }
        }
    }
    cout << vis.size() << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}