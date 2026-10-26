#include <bits/stdc++.h>
using namespace std;

long long n, d[15], c;

signed main() {
    cin >> n;
    c = 0;
    for (; n > 0;) {
        d[c++] = n % 10;
        n /= 10;
    }
    for (int i = 0; i < c; i++) {
        if (i > 0) {
            cout << ",";
        }
        cout << d[i];
    }
    cout << "\n";
    return 0;
}
