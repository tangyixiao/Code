#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, f[N], v[N];

signed main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = v[i]; j <= m; j++) {
            f[j] += f[j - v[i]];
        }
    }
    cout << f[m] % 1000000007 << "\n";
    return 0;
}
