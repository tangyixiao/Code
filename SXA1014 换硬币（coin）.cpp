#include <bits/stdc++.h>
using namespace std;

long long n, q, t;

signed main() {
    cin >> n;
    q = n / 5;
    t = n / 10;
    cout << (t + 1) * (q + 1 - t) << "\n";
    return 0;
}
