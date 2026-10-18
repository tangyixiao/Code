#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, i, ans;
long long x, e;
pair<long long, long long> a[N];
long long mx;

signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x >> e;
        a[i] = make_pair(x - e, -(x + e));
    }
    sort(a + 1, a + n + 1);
    mx = -(1ll << 62);
    for (i = 1; i <= n; i++) {
        if (-a[i].second > mx) {
            ans++;
            mx = -a[i].second;
        }
    }
    cout << ans << "\n";
    return 0;
}