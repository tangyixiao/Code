#include <bits/stdc++.h>
using namespace std;

long long x;
int m;

void f(long long x, int m) {
    if (x < m) {
        cout << x;
        return;
    }
    f(x / m, m);
    cout << "0123456789ABCDEF"[x % m];
}

signed main() {
    cin >> x >> m;
    f(x, m);
    cout << "\n";
    return 0;
}
