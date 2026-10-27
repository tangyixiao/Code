#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a, i, ans;
int b[N], c[N];
signed main() {
    cin >> n >> a;
    for (i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (i = 0; i < n; i++) {
        c[i] = (b[(i - 1 + n) % n] == 0) + (b[i] == 0) + (b[(i + 1) % n] == 0);
    }
    sort(c, c + n);
    ans = 3 * n;
    for (i = 0; i < a; i++) {
        ans -= c[i];
    }
    cout << ans << "\n";
    return 0;
}
