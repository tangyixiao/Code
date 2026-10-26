#include <bits/stdc++.h>
using namespace std;

int n, i, j, k, tot;
int d[1005];

signed main() {
    cin >> n;
    tot = 0;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            d[tot] = i;
            tot++;
            if (i != n / i) {
                d[tot] = n / i;
                tot++;
            }
        }
    }
    sort(d, d + tot);
    for (i = 0; i < tot; i++) {
        if (i > 0) {
            cout << ",";
        }
        cout << d[i];
    }
    cout << "\n";
    return 0;
}
