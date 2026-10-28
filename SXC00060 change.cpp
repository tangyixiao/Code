#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, i, p, half;
int a[N], b[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    half = (n + 1) / 2;
    for (p = 0; p < n; p++) {
        if (p < half) {
            b[p] = a[n - 1 - 2 * p] ^ 1;
        } else {
            b[p] = a[2 * p - n];
        }
    }
    for (i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << b[i];
    }
    cout << "\n";
    return 0;
}
