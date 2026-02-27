#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
int n, x = 1e9;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        if (a < x) {
            x = a;
        }
    }
    cout << x << endl;
    return 0;
}