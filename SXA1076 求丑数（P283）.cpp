#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int a[10005];

bool ok(int x) {
    for (int d = 2; d <= 5; d++) {
        if (d == 4) {
            continue;
        }
        for (; x % d == 0;) {
            x /= d;
        }
    }
    return x == 1;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (ok(i)) {
            cnt++;
            a[cnt] = i;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        cout << left << setw(6) << a[i];
        if (i % 10 == 0) {
            cout << "\n\n";
        }
    }
    if (cnt % 10 != 0) {
        cout << "\n";
    }
    cout << "个数：" << cnt << "\n";
    return 0;
}
