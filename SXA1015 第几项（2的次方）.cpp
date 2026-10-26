#include <bits/stdc++.h>
using namespace std;

signed main() {
    long long m, s = 0, t = 1;
    int n = 0;
    cin >> m;
    for (; s <= m;) {
        s += t;
        t *= 2;
        n++;
    }
    cout << n << "\n";
    return 0;
}
