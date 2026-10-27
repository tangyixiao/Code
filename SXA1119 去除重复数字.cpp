#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, a[N], f[N], m;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[j] < a[i]) {
                swap(a[i], a[j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i] != a[i - 1]) {
            f[++m] = a[i];
        }
    }
    cout << m << "\n";
    for (int i = 1; i <= m; i++) {
        cout << f[i] << "\n";
    }
    return 0;
}
