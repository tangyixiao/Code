#include <bits/stdc++.h>
using namespace std;
signed main() {
    long long a, b, c, d;
    cin >> a >> b >> c;
    if (b - a == c - b) {
        d = b - a;
        cout << c + d << " " << c + 2 * d << " " << c + 3 * d << "\n";
    } else {
        long long r = b / a;
        cout << c * r << " " << c * r * r << " " << c * r * r * r << "\n";
    }
    return 0;
}
