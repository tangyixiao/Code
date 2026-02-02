#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int a[N], n, q, l, r;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> q;
    while (q--) {
        cin >> l >> r;
        sort(a + l, a + r + 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}