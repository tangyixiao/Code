#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, i, x, mn;
signed main() {
    cin >> n;
    mn = 1e9;
    for (i = 1; i <= n; i++) {
        cin >> x;
        if (x < mn) {
            mn = x;
        }
    }
    cout << mn << "\n";
    return 0;
}
