#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
int n, ans;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while (n) {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    cout << ans << endl;
    return 0;
}