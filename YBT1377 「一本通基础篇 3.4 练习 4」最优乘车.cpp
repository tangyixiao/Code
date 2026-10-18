#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 1e6 + 5;
int n, m, hd[N], to[M], nx[M], wt[M], tot, cn, sq[N], d[N];

inline void add(int u, int v, int w) {
    to[++tot] = v;
    wt[tot] = w;
    nx[tot] = hd[u];
    hd[u] = tot;
    return;
}

inline void input() {
    cin >> m >> n;
    string s;
    getline(cin, s);
    cn = n;
    for (int i = 1; i <= m; i++) {
        getline(cin, s);
        int c = 0, x = 0;
        bool f = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            if (s[j] >= '0' && s[j] <= '9') {
                x = x * 10 + s[j] - '0';
                f = 1;
            } else if (f) {
                sq[++c] = x;
                x = 0;
                f = 0;
            }
        }
        if (f) {
            sq[++c] = x;
        }
        int b = cn;
        cn += c;
        for (int j = 1; j <= c; j++) {
            add(sq[j], b + j, 1);
            add(b + j, sq[j], 0);
        }
        for (int j = 1; j < c; j++) {
            add(b + j, b + j + 1, 0);
        }
    }
}

inline void solve() {
    deque<int> q;
    for (int i = 1; i <= cn; i++) {
        d[i] = 1e9;
    }
    d[1] = 0;
    q.push_back(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (int i = hd[u]; i; i = nx[i]) {
            int v = to[i];
            if (d[v] > d[u] + wt[i]) {
                d[v] = d[u] + wt[i];
                if (wt[i]) {
                    q.push_back(v);
                } else {
                    q.push_front(v);
                }
            }
        }
    }
    cout << d[n] - 1 << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
