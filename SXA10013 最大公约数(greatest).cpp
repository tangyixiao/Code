#include <bits/stdc++.h>
using namespace std;

int x, y;

int gcd(int a, int b) {
    for (; b;) {
        int t = a % b;
        a = b, b = t;
    }
    return a;
}

signed main() {
    cin >> x >> y;
    cout << gcd(x, y) << "\n";
    return 0;
}
