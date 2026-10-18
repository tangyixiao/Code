#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, M = 1e6 + 5;
int t, bel[M];
bool in[M];
queue<int> q[N], qt;

inline void input() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x, bel[x] = i;
        }
    }
}

inline void solve() {
    string s;
    while (cin >> s) {
        if (s == "STOP") {
            break;
        }
        if (s == "ENQUEUE") {
            int x;
            cin >> x;
            int i = bel[x];
            if (!in[i]) {
                in[i] = 1, qt.push(i);
            }
            q[i].push(x);
        } else {
            int i = qt.front();
            cout << q[i].front() << "\n";
            q[i].pop();
            if (q[i].empty()) {
                qt.pop(), in[i] = 0;
            }
        }
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
