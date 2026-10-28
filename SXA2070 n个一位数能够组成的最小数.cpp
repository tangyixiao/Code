#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
int a[N], n, i, j;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++) {
        if (a[i] != 0) {
            break;
        }
    }
    if (i <= n && a[1] == 0) {
        swap(a[1], a[i]);
    }
    for (i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
