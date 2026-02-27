#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, m, v[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        v[i] = x;
    }
    for (int id, i = 1; i <= m; i++) {
        cin >> id;
        cout << v[id] << "\n";
    }
    return 0;
}