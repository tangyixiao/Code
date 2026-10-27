#include <bits/stdc++.h>
using namespace std;

int n, p, q;
int a[1005], b[1005], c[1005];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            p++;
            b[p] = a[i];
        } else {
            q++;
            c[q] = a[i];
        }
    }
    sort(b + 1, b + p + 1);
    sort(c + 1, c + q + 1);
    p = 0, q = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            p++;
            cout << b[p];
        } else {
            q++;
            cout << c[q];
        }
        if (i < n) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
