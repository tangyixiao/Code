#include <bits/stdc++.h>
using namespace std;
int m, n;
signed main() {
    cin >> m >> n;
    cout << m * n / gcd(m, n);
    return 0;
}