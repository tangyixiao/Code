#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5, M = 1e5 + 5;
int n, x, ans = M, ansx;
map<int, int> p;

inline void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (p.count(x) && i - p[x] < ans) {
            ans = i - p[x], ansx = x;
        }
        p[x] = i;
    }
    printf("%d\n", n);
    printf("%d\n", ansx);
    return;
}

signed main() {
    solve();
    return 0;
}