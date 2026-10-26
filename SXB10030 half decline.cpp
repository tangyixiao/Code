#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n;
long long f[N];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i / 2; j++) {
            f[i] += f[j];
        }
    }
    cout << f[n] << "\n";
    return 0;
}
