#include <bits/stdc++.h>
using namespace std;

int m, n, s, i;

signed main() {
    cin >> m >> n;
    for (i = m; i <= n; i++) {
        if (i % 7 == 0) {
            s += i;
        }
    }
    cout << s << "\n";
    return 0;
}
