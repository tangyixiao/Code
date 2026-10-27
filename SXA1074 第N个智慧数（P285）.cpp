#include <bits/stdc++.h>
using namespace std;
signed main() {
    int n, i, c = 0, ans = 0;
    cin >> n;
    for (i = 3; c < n; i++) {
        if (i % 4 != 2 && i != 4) {
            c++, ans = i;
        }
    }
    cout << ans << "\n";
    return 0;
}
