#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int a[N], n, i, x, s;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x;
        s = 0;
        for (; x > 0; x /= 10) {
            s += x % 10;
        }
        a[i] = s;
    }
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
