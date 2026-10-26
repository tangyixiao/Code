#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    bool f = n >= 2;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            f = false;
            break;
        }
    }
    if (f) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }
    return 0;
}
