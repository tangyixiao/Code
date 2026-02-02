#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 7;
int c[N], t[N];
signed main() {
    int a, b, m, ans = 0;
    cin >> a >> b >> m;
    c[1] = 1;
    for (int i = 1; i <= b; i++) {
        c[i] = (c[i - 1] + m - 1) % i + 1;
        if (i >= a) {
            t[c[i]]++;
            ans = max(ans, t[c[i]]);
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= b; i++) {
        if (t[i] == ans) {
            cout << i << ' ';
        }
    }
    return 0;
}
