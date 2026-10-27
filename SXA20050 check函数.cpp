#include <bits/stdc++.h>
using namespace std;

long long a, b, t;
bool ok;

signed main() {
    cin >> a >> b;
    t = a;
    while (t > 0) {
        if (t % 10 == b) {
            ok = true;
            break;
        }
        t /= 10;
    }
    if (ok) {
        cout << "true" << "\n";
    } else {
        cout << "false" << "\n";
    }
    return 0;
}
