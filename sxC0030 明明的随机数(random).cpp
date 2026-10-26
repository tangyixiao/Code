#include <bits/stdc++.h>
using namespace std;

int n, c, a[105];

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            c++;
        }
    }
    cout << c << "\n";
    int f = 1;
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            if (!f) {
                cout << " ";
            }
            cout << a[i];
            f = 0;
        }
    }
    cout << "\n";
    return 0;
}
