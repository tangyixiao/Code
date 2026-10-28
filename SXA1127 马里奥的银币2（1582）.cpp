#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, i, a[N];
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++) {
        if (i <= n / 2) {
            a[i] *= 2;
        } else {
            a[i] += 1;
        }
    }
    for (i = 1; i <= n; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
