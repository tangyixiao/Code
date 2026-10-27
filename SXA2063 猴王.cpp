#include <bits/stdc++.h>
using namespace std;

int n, v, c[105], best;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v;
        c[v]++;
    }
    best = 1;
    for (int i = 2; i <= n; i++) {
        if (c[i] >= c[best]) {
            best = i;
        }
    }
    cout << best << "\n";
    return 0;
}
