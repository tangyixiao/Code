#include <bits/stdc++.h>
using namespace std;

int n, d;
char buf[64];

signed main() {
    cin >> n;
    if (n == 0) {
        cout << "0\n";
        return 0;
    }
    d = 0;
    while (n > 0) {
        buf[d] = "0123456789ABCDEF"[n % 16];
        n /= 16;
        d++;
    }
    for (int i = d - 1; i >= 0; i--) {
        cout << buf[i];
    }
    cout << "\n";
    return 0;
}
