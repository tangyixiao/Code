#include <bits/stdc++.h>
using namespace std;

int n, a[11];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= 6; i++) {
        a[i] = n % 10;
        n /= 10;
    }
    for (int i = 6; i >= 1; i--) {
        cout << a[i] << "\n";
    }
    return 0;
}
