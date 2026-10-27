#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, f[N];
long long o[N], b[N], p[N], s[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> o[i];
        b[i] = o[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + b[i];
    }
    f[n] = n;
    for (int j = n - 1; j >= 1; j--) {
        if (p[j] >= b[j + 1]) {
            f[j] = f[j + 1];
        } else {
            f[j] = j;
        }
    }
    for (int i = 1; i <= n; i++) {
        int k = upper_bound(b + 1, b + n + 1, o[i]) - b - 1;
        s[i] = p[f[k]];
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << s[i];
    }
    cout << "\n";
    return 0;
}
