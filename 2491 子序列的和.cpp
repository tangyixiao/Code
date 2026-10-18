#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m;

signed main() {
    while (cin >> n >> m && (n || m)) {
        double s = 0;
        for (int i = n; i <= m; i++) {
            s += 1.0 / i / i;
        }
        printf("%.5f\n", s);
    }
    return 0;
}