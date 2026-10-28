#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;

signed main() {
    cin >> n;
    a = n % 10, b = n / 10 % 10, c = n / 100;
    cout << a << b << c << n << "\n";
    return 0;
}
