#include <bits/stdc++.h>
using namespace std;

signed main() {
    long long a, b, t;
    cin >> a >> b;
    for (; b; t = a, a = b, b = t) {
        a %= b;
    }
    cout << a << "\n";
    return 0;
}
