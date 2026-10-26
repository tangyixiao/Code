#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int p[N], q[N], n, i, j, ok = 1;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> p[i] >> q[i];
        if (p[i] > q[i]) {
            swap(p[i], q[i]);
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            int a = p[i], b = q[i], c = p[j], d = q[j];
            if ((a < c && c < b && b < d) || (c < a && a < d && d < b)) {
                ok = 0;
            }
        }
    }
    if (ok == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
