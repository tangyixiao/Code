#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, k, x, d[N];

signed main() {
    cin >> n;
    cin >> k;
    while (cin >> x) {
        d[x] = 1;
    }
    int mn = n + 1;
    for (int i = 1; i + k - 1 <= n; i++) {
        int c = 0;
        for (int j = i; j <= i + k - 1; j++) {
            c += d[j];
        }
        mn = min(mn, c);
    }
    cout << mn << "\n";
    return 0;
}
