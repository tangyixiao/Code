#include <bits/stdc++.h>
using namespace std;

int n;

signed main() {
    cin >> n;
    if (n >= 90) {
        cout << 3 * n << "\n";
    } else if (n >= 80) {
        cout << 2 * n << "\n";
    } else if (n >= 70) {
        cout << n << "\n";
    } else {
        cout << 50 << "\n";
    }
    return 0;
}
