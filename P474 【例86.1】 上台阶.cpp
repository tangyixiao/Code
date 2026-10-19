#include <bits/stdc++.h>
using namespace std;

const int N = 75 + 5;
long long f[N];
int n;

signed main() {
    f[1] = 1, f[2] = 2, f[3] = 4;
    while (cin >> n && n) {
        if (n <= 3) {
            cout << f[n] << "\n";
            continue;
        }
        for (int i = 4; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2] + f[i - 3];
        }
        cout << f[n] << "\n";
    }
    return 0;
}