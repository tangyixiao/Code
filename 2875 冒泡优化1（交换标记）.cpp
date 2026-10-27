#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
int a[N], n, i, sw;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int p = 0; p < n; p++) {
        sw = 0;
        for (i = 1; i < n; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]), sw = 1;
            }
        }
        for (i = 1; i <= n; i++) {
            if (i > 1) {
                cout << " ";
            }
            cout << a[i];
        }
        cout << "\n";
        if (sw == 0) {
            break;
        }
    }
    return 0;
}
