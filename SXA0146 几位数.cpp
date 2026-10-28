#include <bits/stdc++.h>
using namespace std;

int n, c;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    if (n == 0) {
        cout << 1 << "\n";
        return 0;
    }
    for (; n > 0; n /= 10) {
        c++;
    }
    cout << c << "\n";
    return 0;
}
