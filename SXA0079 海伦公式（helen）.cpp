#include <bits/stdc++.h>
using namespace std;

double a, b, c, p, s;

signed main() {
    cin >> a >> b >> c;
    p = (a + b + c) / 2;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << s << "\n";
    return 0;
}
