#include <bits/stdc++.h>
using namespace std;

int i, cnt;
int a[5];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (i = 1; i <= 3; i++) {
        cin >> a[i];
    }
    cnt = 0;
    for (i = 1; i <= 3; i++) {
        if (a[i] >= 90) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
