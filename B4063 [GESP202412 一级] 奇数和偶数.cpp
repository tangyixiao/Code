#include <bits/stdc++.h>
using namespace std;
int n, cnt1, cnt2;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        cnt1 += (x & 1);
        cnt2 += (!(x & 1));
    }
    cout << cnt1 << " " << cnt2;
    return 0;
}