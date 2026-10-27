#include <bits/stdc++.h>
using namespace std;

int n, i, s;

signed main() {
    cin >> n;
    s = 0;
    for (i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            s += i;
        } else {
            s -= i;
        }
    }
    cout << s << "\n";
    return 0;
}
