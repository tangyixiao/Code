#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x & -x)
using namespace std;
int l, r, ans;
signed main() {
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (i == 1) {
            continue;
        }
        int x = i;
        x -= lowbit(x);
        x -= lowbit(x);
        if (!x) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
