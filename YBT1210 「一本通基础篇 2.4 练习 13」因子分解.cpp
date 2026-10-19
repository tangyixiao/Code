#include <bits/stdc++.h>
using namespace std;

signed main() {
    long long n;
    cin >> n;
    bool f = false;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int b = 0;
            while (n % p == 0) {
                n /= p;
                b++;
            }
            cout << (f ? "*" : "") << p << (b > 1 ? "^" + to_string(b) : "");
            f = true;
        }
    }
    if (n > 1) {
        cout << (f ? "*" : "") << n;
    }
    cout << "\n";
    return 0;
}
