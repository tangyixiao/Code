#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, t, b1 = -1, b2 = -1;
    string s, n1, n2;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s >> t;
        if (t > b1) {
            b2 = b1;
            n2 = n1;
            b1 = t;
            n1 = s;
        } else if (t > b2) {
            b2 = t;
            n2 = s;
        }
    }
    cout << n2 << "\n";
    return 0;
}
