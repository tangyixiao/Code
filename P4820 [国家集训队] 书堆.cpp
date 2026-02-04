#include <bits/stdc++.h>
#define int long long
#define Gamma 0.57721566490153286060651209008240243104215933593992L
using namespace std;
typedef long double ld;
const int MAXN = 1e7;
ld H;
int n, m;
signed main() {
    cin >> n >> m;
    if (n <= MAXN) {
        for (int i = 1; i <= n; ++i) {
            H += 1.0L / i;
        }
    } else {
        ld N = n;
        H = logl(N) + Gamma + 1.0L / (2.0L * N) - 1.0L / (12.0L * N * N) +
            1.0L / (120.0L * N * N * N * N);
    }
    cout << (int)((m * H / 2.0L) - 1e-12L);
    return 0;
}