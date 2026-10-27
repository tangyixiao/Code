#include <bits/stdc++.h>
using namespace std;

long long n, c;

signed main() {
    cin >> n;
    if (n <= 3) {
        cout << 1 << "\n";
        return 0;
    }
    c = (n - 3 + 1) / 2;
    if ((n - 3) % 2 != 0) {
        c = (n - 3) / 2 + 1;
    }
    cout << 2 * c + 1 << "\n";
    return 0;
}
