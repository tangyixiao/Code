#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, q, a[N], m;
map<int, int> mp;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> m;
        if (mp.count(m)) {
            cout << mp[m] << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}