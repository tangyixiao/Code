#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, m, x;
multiset<int> s;

inline void input() { cin >> n; }

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        cin >> m;
        for (int j = 1; j <= m; ++j) {
            cin >> x;
            s.insert(x);
        }
        auto p = s.begin();
        cout << *p << " " << *s.rbegin() << "\n";
        s.erase(p);
        s.erase(prev(s.end()));
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}