#include <bits/stdc++.h>
using namespace std;

int n, p, q, ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num, den;
        char ch;
        cin >> num >> ch >> den;
        if (i == 1) {
            p = num;
            q = den;
        } else {
            p = p * den + num * q;
            q = q * den;
        }
        int g = __gcd(p, q);
        p /= g;
        q /= g;
    }
    if (q == 1) {
        cout << p << "\n";
    } else {
        cout << p << "/" << q << "\n";
    }
    return 0;
}
