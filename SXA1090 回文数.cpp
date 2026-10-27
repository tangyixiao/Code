#include <bits/stdc++.h>
using namespace std;

long long n, x, r, c, t;

signed main() {
    cin >> n;
    x = n;
    c = 0;
    while (1) {
        r = 0;
        t = x;
        while (t > 0) {
            r = r * 10 + t % 10;
            t /= 10;
        }
        if (r == x) {
            break;
        }
        x += r;
        c++;
    }
    cout << c << "\n";
    return 0;
}
