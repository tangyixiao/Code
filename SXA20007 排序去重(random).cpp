#include <bits/stdc++.h>
using namespace std;

const int N = 205;

int n, i, c;
int a[N], u[N];

signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    c = 0;
    for (i = 1; i <= n; i++) {
        if (i == 1 || a[i] != a[i - 1]) {
            u[++c] = a[i];
        }
    }
    cout << c << "\n";
    for (i = 1; i <= c; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << u[i];
    }
    cout << "\n";
    return 0;
}
