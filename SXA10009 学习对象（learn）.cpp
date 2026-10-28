#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, i, j, best, bj;
int a[N];
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++) {
        best = 0, bj = 0;
        for (j = 1; j <= n; j++) {
            if (a[j] > a[i]) {
                if (best == 0 || a[j] < best) {
                    best = a[j], bj = j;
                }
            }
        }
        cout << bj << "\n";
    }
    return 0;
}
