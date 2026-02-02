#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n;
signed main() {
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n & 1) {
            cout << 0 << "\n";
        } else {
            cout << n / 4 + 1 << "\n";
        }
    }
    return 0;
}