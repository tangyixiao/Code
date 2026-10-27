#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, a[15];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i--) {
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
