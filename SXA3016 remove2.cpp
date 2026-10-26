#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int a[N], v[N];

signed main() {
    int n, x, c = 0, f = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        f = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] == a[i]) {
                f = 0;
            }
        }
        if (f) {
            v[++c] = a[i];
        }
    }
    for (int i = 1; i <= c; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << v[i];
    }
    cout << "\n";
    return 0;
}
