#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, s = 0, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        s += x;
    }
    cout << s / 3 << "\n";
    return 0;
}
