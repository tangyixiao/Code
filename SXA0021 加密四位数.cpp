#include <bits/stdc++.h>
using namespace std;

int n, i, t, r;
int d[5];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (i = 1; i <= 4; i++) {
        d[i] = (n % 10 + 5) % 10;
        n /= 10;
    }
    for (i = 1; i <= 4; i++) {
        r = r * 10 + d[i];
    }
    cout << r << "\n";
    return 0;
}
