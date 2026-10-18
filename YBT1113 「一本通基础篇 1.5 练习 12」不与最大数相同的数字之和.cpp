#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int a[N], n, mx = -0x7fffffff - 1;

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    long long s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != mx) {
            s += a[i];
        }
    }
    cout << s << "\n";
    return 0;
}
