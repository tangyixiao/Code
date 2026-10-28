#include <bits/stdc++.h>
using namespace std;

int n, a[5], mx, mn;

signed main() {
    cin >> n;
    a[1] = n / 100, a[2] = n / 10 % 10, a[3] = n % 10;
    sort(a + 1, a + 4);
    mx = a[3] * 100 + a[2] * 10 + a[1];
    mn = a[1] * 100 + a[2] * 10 + a[3];
    cout << mx - mn << "\n";
    return 0;
}
