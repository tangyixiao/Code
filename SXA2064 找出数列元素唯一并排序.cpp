#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i] != a[i - 1]) {
            cnt++;
            a[cnt] = a[i];
        }
    }
    for (int i = 1; i <= cnt; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
