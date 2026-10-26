#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, i, x, s1, s2;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x;
        if (i % 2 == 1) {
            s1 += x;
        } else {
            s2 += x;
        }
    }
    cout << "KING " << s1 << "\n";
    cout << "WIN " << s2 << "\n";
    if (s1 >= s2) {
        cout << "KING" << "\n";
    } else {
        cout << "WIN" << "\n";
    }
    return 0;
}
