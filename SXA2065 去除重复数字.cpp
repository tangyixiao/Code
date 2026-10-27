#include <bits/stdc++.h>
using namespace std;
int a[105], n, i, c;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    c = 0;
    for (i = 1; i <= n; i++) {
        if (i == 1 || a[i] != a[i - 1]) {
            a[++c] = a[i];
        }
    }
    cout << c << "\n";
    for (i = 1; i <= c; i++) {
        cout << a[i] << "\n";
    }
    return 0;
}
