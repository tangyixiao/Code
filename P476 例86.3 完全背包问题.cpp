#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;
int M, n, w[N], c[N], f[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= M; j++) {
            f[j] = max(f[j], f[j - w[i]] + c[i]);
        }
    }
    cout << "max=" << f[M] << "\n";
    return 0;
}
