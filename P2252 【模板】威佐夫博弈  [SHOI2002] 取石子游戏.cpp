#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
int a, b, u, now;
signed main() {
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    u = b - a, now = (int)((sqrt((double)(5.0)) + 1.0) / 2.0 * u);
    cout << !(a == now);
    return 0;
}