#include <bits/stdc++.h>
using namespace std;
long long x, s;
signed main() {
    cin >> x;
    s = x * 1000 + x;
    s = s / 7 / 11 / 13;
    cout << s << "\n";
    return 0;
}
