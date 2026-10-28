#include <bits/stdc++.h>
using namespace std;
signed main() {
    long long n;
    int x, p = 0, c = 0, f = 0;
    cin >> n;
    while (cin >> x) {
        if (c == 0) {
            p = x, c = 1;
        } else if (x == p) {
            c++;
        } else {
            if (f == 1) {
                cout << " ";
            }
            cout << c;
            f = 1, p = x, c = 1;
        }
    }
    if (c > 0) {
        if (f == 1) {
            cout << " ";
        }
        cout << c;
    }
    cout << "\n";
    return 0;
}
