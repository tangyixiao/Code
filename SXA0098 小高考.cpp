#include <bits/stdc++.h>
using namespace std;

int i, x, cnt;
int a[5];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (i = 1; i <= 4; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= 4; i++) {
        if (a[i] < 60) {
            cout << "Poor LanYangYang" << "\n";
            return 0;
        }
    }
    cnt = 0;
    for (i = 1; i <= 4; i++) {
        if (a[i] >= 90) {
            cnt++;
        }
    }
    if (cnt == 4) {
        cout << 5 << "\n";
    } else {
        cout << cnt << "\n";
    }
    return 0;
}
