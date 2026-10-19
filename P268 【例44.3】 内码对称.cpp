#include <bits/stdc++.h>
using namespace std;

unsigned int n;

signed main() {
    cin >> n;
    for (int i = 0; i < 16; i++) {
        if ((n >> i & 1) != (n >> 31 - i & 1)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}