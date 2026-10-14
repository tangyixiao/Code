#include <bits/stdc++.h>
using namespace std;
int n, g[25], a[25];
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    g[1] = a[1];
    for (int i = 2; i <= n; i++) {
        g[i] = min(g[i - 1], g[i - 2]) + a[i];
    }
    cout << g[n];
    return 0;
}