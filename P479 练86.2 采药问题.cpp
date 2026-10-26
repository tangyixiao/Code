#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int f[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, m, w, v;
    cin >> t >> m;
    for (int i = 1; i <= m; i++) {
        cin >> w >> v;
        for (int j = t; j >= w; j--) {
            f[j] = max(f[j], f[j - w] + v);
        }
    }
    cout << f[t] << "\n";
    return 0;
}
