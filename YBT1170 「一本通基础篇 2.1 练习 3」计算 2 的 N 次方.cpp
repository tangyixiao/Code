#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int a[N], n, l = 1;

signed main() {
    cin >> n;
    a[0] = 1;
    for (int i = 1; i <= n; i++) {
        int t = 0;
        for (int j = 0; j < l; j++) {
            t += a[j] * 2;
            a[j] = t % 10;
            t /= 10;
        }
        if (t) {
            a[l++] = t;
        }
    }
    for (int i = l - 1; i >= 0; i--) {
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
