#include <bits/stdc++.h>
using namespace std;

const int N = 205;
const int M = 35;

int m, n, i, j, k, w, c, p;
int f[N];

signed main() {
    cin >> m >> n;
    for (i = 1; i <= n; i++) {
        cin >> w >> c >> p;
        if (p == 0) {
            for (j = w; j <= m; j++) {
                f[j] = max(f[j], f[j - w] + c);
            }
        } else {
            for (k = 1; k <= p; k++) {
                for (j = m; j >= w; j--) {
                    f[j] = max(f[j], f[j - w] + c);
                }
            }
        }
    }
    cout << f[m] << "\n";
    return 0;
}
