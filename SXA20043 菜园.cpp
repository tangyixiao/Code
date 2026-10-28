#include <bits/stdc++.h>
using namespace std;

int L, a, b, s, mx;

signed main() {
    cin >> L;
    mx = 0;
    for (a = 1;; a++) {
        b = L - 2 * a;
        if (b < 1) {
            break;
        }
        s = a * b;
        cout << a << " " << b << " " << s << "\n";
        if (s > mx) {
            mx = s;
        }
    }
    cout << mx << "\n";
    return 0;
}
