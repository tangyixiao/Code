#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int k, m;
bool vis[N];
queue<pair<int, string>> q;

signed main() {
    cin >> k >> m;
    for (int d = 1; d < k; d++) {
        int r = d % m;
        if (!vis[r]) {
            vis[r] = 1, q.push(make_pair(r, string(1, char('0' + d))));
        }
    }
    while (!q.empty()) {
        pair<int, string> u = q.front();
        q.pop();
        if (!u.first) {
            cout << u.second << "\n";
            break;
        }
        for (int d = 0; d < k; d++) {
            int r = (u.first * 10 + d) % m;
            if (!vis[r]) {
                vis[r] = 1, q.push(make_pair(r, u.second + char('0' + d)));
            }
        }
    }
    return 0;
}