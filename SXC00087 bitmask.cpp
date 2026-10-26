#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >> x;
    int low = x & (-x);
    if (low == x) {
        cout << 3 << "\n";
    } else {
        cout << low << "\n";
    }
    return 0;
}
