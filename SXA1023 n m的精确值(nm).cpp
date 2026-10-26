#include <bits/stdc++.h>
using namespace std;

long long n, m, r, d;
int a[105];

signed main() {
    cin >> n >> m;
    a[0] = n / m;
    r = n % m;
    for (int i = 1; i <= 100; i++) {
        r *= 10;
        a[i] = r / m;
        r %= m;
    }
    cout << a[0] << ".";
    for (int i = 1; i <= 100; i++) {
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
