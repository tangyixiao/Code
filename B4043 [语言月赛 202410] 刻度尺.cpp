#include <bits/stdc++.h>
using namespace std;
int n, a, b;
signed main() {
    cin >> n >> a >> b;
    if (a + b <= n && a - b >= 0) {
        if (b) {
            cout << a - b << ' ' << a + b << "\n";
        } else {
            cout << a << "\n";
        }

    } else {
        if (a + b <= n || a - b >= 0) {
            if (a + b <= n) {
                cout << a + b << "\n";
            } else {
                cout << a - b << "\n";
            }
        } else {
            cout << "No solution\n";
        }
    }
    return 0;
}