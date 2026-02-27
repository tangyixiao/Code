#include <bits/stdc++.h>
using namespace std;
const int N = 21;
int n = 11, ans, t;
struct node {
    int d, v;
    bool operator<(const node& b) const {
        return d < b.d;
    }
} a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].d >> a[i].v;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        t += a[i].d;
        ans += (t + 20 * a[i].v);
    }
    cout << ans;
    
    return 0;
}
