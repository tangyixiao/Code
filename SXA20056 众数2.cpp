#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;
int c[N];

signed main() {
    int n, x, mx = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        c[x]++;
        mx = max(mx, c[x]);
    }
    for (int i = 1; i < N; i++) {
        if (c[i] == mx) {
            cout << i << " " << c[i] << "\n";
        }
    }
    return 0;
}
