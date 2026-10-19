#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> c;

inline void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x, ++c[x];
    }
    return;
}

inline void solve() {
    for (map<int, int>::iterator it = c.begin(); it != c.end(); ++it) {
        cout << it->first << " " << it->second << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
