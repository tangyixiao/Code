#include <bits/stdc++.h>
using namespace std;
int l, r;
inline int dismantle2(int x) {
    int cnt = 0;
    while (x) {
        if (x % 10 == 2) {
            cnt++;
        }
        x /= 10;
    }
    return cnt;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> l >> r;
    int ans = 0;
    for (int i = l; i <= r; i++) {
        ans += dismantle2(i);
    }
    cout << ans << endl;
    return 0;
}