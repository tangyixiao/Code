#include <bits/stdc++.h>
using namespace std;

int n;

signed main() {
    cin >> n;
    int r = n % 10 * 10 + n / 10;
    cout << max(n, r) << "\n";
    return 0;
}
