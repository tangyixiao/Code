#include <bits/stdc++.h>
using namespace std;

int n, f;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    f = n >= 2;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            f = 0;
            break;
        }
    }
    cout << (f ? "YES" : "NO") << "\n";
    return 0;
}
