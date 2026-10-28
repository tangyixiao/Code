#include <bits/stdc++.h>
using namespace std;
int n, i, x, cnt, c[105];
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x;
        c[x]++;
    }
    cnt = 0;
    for (i = 1; i <= 100; i++) {
        if (c[i] > 0) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (i = 1; i <= 100; i++) {
        if (c[i] > 0) {
            cout << i << " " << c[i] << "\n";
        }
    }
    return 0;
}
