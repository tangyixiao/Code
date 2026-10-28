#include <bits/stdc++.h>
using namespace std;
int i, x, mx, mn;
signed main() {
    cin >> x;
    mx = x, mn = x;
    for (i = 2; i <= 5; i++) {
        cin >> x;
        if (x > mx) {
            mx = x;
        }
        if (x < mn) {
            mn = x;
        }
    }
    cout << "Max=" << mx << "\n";
    cout << "Min=" << mn << "\n";
    return 0;
}
