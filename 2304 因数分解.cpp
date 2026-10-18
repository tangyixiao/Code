#include <bits/stdc++.h>
using namespace std;

inline void input() {
    long long n;
    cin >> n;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int c = 0;
            while (n % i == 0) {
                n /= i, ++c;
            }
            cout << i;
            if (c > 1) {
                cout << "^" << c;
            }
            cout << " * ";
        }
    }
    if (n > 1) {
        cout << n;
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    return 0;
}
