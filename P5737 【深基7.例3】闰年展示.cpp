#include <bits/stdc++.h>
using namespace std;
int l, r, cnt;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
            printf("%d ", i);
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}