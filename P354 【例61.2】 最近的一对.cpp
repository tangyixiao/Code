#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5, M = 1e5 + 5;
int n, x, ans = M, ansx;
map<int, int> p;

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    input();
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (p.count(x) && i - p[x] < ans) {
            ans = i - p[x], ansx = x;
        }
        p[x] = i;
    }
    if (ans == M) {
        cout << "No\n";
    } else {
        cout << ansx << "\n";
    }
    return;
}

signed main() {
    solve();
    return 0;
}