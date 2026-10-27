#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long a[N], b[N], d[2][3], c[3];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int j = 0; j < 3; j++) {
        d[0][j] = (j == 1 ? 0 : b[0]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            c[j] = a[i] + j - 1;
        }
        for (int j = 0; j < 3; j++) {
            long long best = LLONG_MAX;
            for (int k = 0; k < 3; k++) {
                if (c[j] == a[i - 1] + k - 1) {
                    continue;
                }
                if (d[(i - 1) & 1][k] < best) {
                    best = d[(i - 1) & 1][k];
                }
            }
            d[i & 1][j] = best + (j == 1 ? 0 : b[i]);
        }
    }
    long long ans = LLONG_MAX;
    for (int j = 0; j < 3; j++) {
        if (d[(n - 1) & 1][j] < ans) {
            ans = d[(n - 1) & 1][j];
        }
    }
    cout << ans << "\n";
    return 0;
}
