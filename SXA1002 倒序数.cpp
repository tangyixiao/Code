#include <bits/stdc++.h>
using namespace std;

long long n, r;

signed main() {
    cin >> n;
    while (n) {
        r = r * 10 + n % 10;
        n /= 10;
    }
    cout << r << "\n";
    return 0;
}
