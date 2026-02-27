#include <bits/stdc++.h>
using namespace std;
long long n, m;
signed main() {
    cin >> n >> m;
    if (n < 0) {
        if (m & 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "NO\n";
    }
    if (n & 1) {
        cout << "YES";
    } else {
        if (m == 0) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
    return 0;
}