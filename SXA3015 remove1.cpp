#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int a[N], n, i, f = 1;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++) {
        if (i > 1 && a[i] == a[i - 1]) {
            continue;
        }
        if (f == 0) {
            cout << " ";
        }
        cout << a[i], f = 0;
    }
    cout << "\n";
    return 0;
}
