#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N], L[N], R[N], i, j, k, ans, t;
int cst(int i, int j) {
    if (i == j) {
        return a[i];
    }
    return abs(a[i] - a[j]) * (j - i + 1);
}
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (j = 1; j <= n; j++) {
        L[j] = 0;
        for (k = 0; k < j; k++) {
            t = L[k] + cst(k + 1, j);
            if (t > L[j]) {
                L[j] = t;
            }
        }
    }
    for (j = n; j >= 1; j--) {
        R[j] = 0;
        for (k = j; k <= n + 1; k++) {
            if (k == j) {
                t = cst(j, j) + R[j + 1];
                if (t > R[j]) {
                    R[j] = t;
                }
            } else {
                t = cst(j, k - 1) + R[k];
                if (t > R[j]) {
                    R[j] = t;
                }
            }
        }
    }
    ans = 0;
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            t = L[i - 1] + cst(i, j) + R[j + 1];
            if (t > ans) {
                ans = t;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
