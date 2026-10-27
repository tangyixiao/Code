#include <bits/stdc++.h>
using namespace std;

int n, m, ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        ans = (ans + m) % i;
    }
    cout << ans + 1 << "\n";
    return 0;
}
