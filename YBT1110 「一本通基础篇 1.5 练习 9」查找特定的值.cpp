#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int a[N], n, x, p = -1;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
    for (int i = 1; i <= n; i++) {
        if (a[i] == x) {
            p = i;
            break;
        }
    }
    cout << p << "\n";
    return 0;
}
