#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, a[N], b[N], c[N], fa[N], fbc[N], ans;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fa[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int j = 1; j <= n; j++) {
        fbc[b[c[j]]]++;
    }

    for (int i = 1; i <= n; i++) {
        ans += 1LL * fa[i] * fbc[i];
    }

    cout << ans << '\n';
    return 0;
}